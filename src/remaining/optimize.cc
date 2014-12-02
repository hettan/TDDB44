#include "optimize.hh"

/*** This file contains all code pertaining to AST optimisation. It currently
     implements a simple optimisation called "constant folding". Most of the
     methods in this file are empty, or just relay optimize calls downward
     in the AST. If a more powerful AST optimization scheme were to be
     implemented, only methods in this file should need to be changed. ***/


ast_optimizer *optimizer = new ast_optimizer();


/* The optimizer's interface method. Starts a recursive optimize call down
   the AST nodes, searching for binary operators with constant children. */
void ast_optimizer::do_optimize(ast_stmt_list *body)
{
    if (body != NULL) {
        body->optimize();
    }
}


/* Returns 1 if an AST expression is a subclass of ast_binaryoperation,
   ie, eligible for constant folding. */
bool ast_optimizer::is_binop(ast_expression *node)
{
    switch (node->tag) {
    case AST_ADD:
    case AST_SUB:
    case AST_OR:
    case AST_AND:
    case AST_MULT:
    case AST_DIVIDE:
    case AST_IDIV:
    case AST_MOD:
        return true;
    default:
        return false;
    }
}



/* We overload this method for the various ast_node subclasses that can
   appear in the AST. By use of virtual (dynamic) methods, we ensure that
   the correct method is invoked even if the pointers in the AST refer to
   one of the abstract classes such as ast_expression or ast_statement. */
void ast_node::optimize()
{
    fatal("Trying to optimize abstract class ast_node.");
}

void ast_statement::optimize()
{
    fatal("Trying to optimize abstract class ast_statement.");
}

void ast_expression::optimize()
{
    fatal("Trying to optimize abstract class ast_expression.");
}

void ast_lvalue::optimize()
{
    fatal("Trying to optimize abstract class ast_lvalue.");
}

void ast_binaryoperation::optimize()
{
    fatal("Trying to optimize abstract class ast_binaryoperation.");
}

void ast_binaryrelation::optimize()
{
    fatal("Trying to optimize abstract class ast_binaryrelation.");
}



/*** The optimize methods for the concrete AST classes. ***/

/* Optimize a statement list. */
void ast_stmt_list::optimize()
{
    if (preceding != NULL) {
        preceding->optimize();
    }
    if (last_stmt != NULL) {
        last_stmt->optimize();
    }
}


/* Optimize a list of expressions. */
void ast_expr_list::optimize()
{
    /* Your code here */  
  if (preceding != NULL) {
    preceding->optimize();
  }
  if (last_expr != NULL) {
    last_expr->optimize();
    last_expr = optimizer->fold_bin(last_expr);
  }
}


/* Optimize an elsif list. */
void ast_elsif_list::optimize()
{   /* Your code here */  
  if (preceding != NULL) {
    preceding->optimize();
  }
  if (last_elsif != NULL) {
    last_elsif->optimize();
  }  
}


/* An identifier's value can change at run-time, so we can't perform
   constant folding optimization on it unless it is a constant.
   Thus we just do nothing here. It can be treated in the fold_constants()
   method, however. */
void ast_id::optimize()
{
}

void ast_indexed::optimize()
{
    /* Your code here */

  //if(index != NULL){
  index->optimize();
  //}
  index = optimizer->fold_bin(index);
}

bool ast_optimizer::is_binrel(ast_expression *node)
{
    switch (node->tag) {
    case AST_EQUAL:
    case AST_NOTEQUAL:
    case AST_GREATERTHAN:
    case AST_LESSTHAN:
        return true;
    default:
        return false;
    }
}

bool ast_optimizer::is_value(ast_expression *node) {
  switch(node->type) {
  case AST_INTEGER:
  case AST_REAL:
    return true;
  default:
    return false;
  }
}

bool ast_optimizer::is_constant(ast_expression *node) {
  if(node->tag == AST_ID) {
    sym_index sym_p = node->get_ast_id()->sym_p;
    return (sym_tab->get_symbol_tag(sym_p) == SYM_CONST);
  }
  return false;
}

ast_expression *ast_optimizer::get_new_node(position_information *pos, fold_value lvalue, fold_value rvalue) {

  cout << "get_new_node() left ival="<< lvalue.value.ival << "  rval=" << lvalue.value.rval << "type" << lvalue.type << endl;
  cout << "get_new_node() right ival="<< rvalue.value.ival << "  rval=" << rvalue.value.rval << "type" << rvalue.type << endl;
  if(lvalue.type == integer_type && rvalue.type == integer_type){
    return new ast_integer(pos, lvalue.value.ival + rvalue.value.ival);
  }
  if(lvalue.type == integer_type && rvalue.type == real_type){
    return new ast_real(pos, lvalue.value.rval + rvalue.value.rval);
  }
  if(lvalue.type == real_type && rvalue.type == integer_type){
    return new ast_real(pos, lvalue.value.rval + rvalue.value.ival);
  }
  if(lvalue.type == real_type && rvalue.type == real_type){
    return new ast_real(pos, lvalue.value.ival + rvalue.value.rval);
  }
  fatal("couln't create node");
  return NULL;
}



ast_expression *ast_optimizer::fold_bin(ast_expression *node) {
  //OUR CODE
  if(is_binop(node)) {
    cout << "fold_bin() found bin_op" << endl;

    ast_binaryoperation* opr = node->get_ast_binaryoperation();
    fold_value lvalue = get_constant_value(opr->left);  
    fold_value rvalue = get_constant_value(opr->right);
    if (lvalue.type == NULL || rvalue.type == NULL){
      cout << "constant value not found " << endl;
      return node;
    }
    
    position_information *pos = node->pos;
    free(node);
    return get_new_node(pos, lvalue, rvalue);
  }
  else if(is_binrel(node)) {
    ast_binaryrelation rel = <dynamic???>node->get_ast_binaryoperataion();
    fold_value lvalue = get_constant_value(rel->left);  
    fold_value rvalue = get_constant_value(rel->right);
    if (lvalue.type == NULL || rvalue.type == NULL){
      cout << "constant value not found " << endl;
      return node;
    }
    cout << "fold_bin() found bin_rel" << endl;
    return node;
  }
  else {
    cout << "fold_bin() fund something else" << endl;
    return node;
  }
}

fold_value ast_optimizer::get_constant_value(ast_expression *node) {
  fold_value f_value;
  f_value.type = NULL;
  if(is_constant(node)) {
    cout << "get_constant_value() found constant" << endl;
    sym_index sym_p = node->get_ast_id()->sym_p;
    constant_symbol *const_sym = sym_tab->get_symbol(sym_p)->get_constant_symbol();
    if(const_sym->type == integer_type) {
      f_value.value.ival = const_sym->const_value.ival;
    }
    else{
      f_value.value.rval = const_sym->const_value.rval;
    }  
    f_value.type = const_sym->type;
  }
  else if(node->tag == AST_INTEGER){
    cout << "get_constant_value() found integer" << endl;
    f_value.value.ival = node->get_ast_integer()->value;
    f_value.type = integer_type;
  }
  else if (node->tag == AST_REAL){
    cout << "get_constant_value() found real" << endl;
    f_value.value.rval = node->get_ast_real()->value;
    f_value.type = real_type;
  }
  else if (node->tag == AST_CAST){
    cout << "get_constant_value() found cast" << endl;
    fold_value cast_value = get_constant_value(node->get_ast_cast()->expr);
    if (cast_value.type != NULL){
	f_value = cast_value;
    }
  }
  else{
    cout << "no constant_value " << "type : " << node->tag << endl;
  }
  return f_value;
}

/* This convenience method is used to apply constant folding to all
   binary operations. It returns either the resulting optimized node or the
   original node if no optimization could be performed. */
ast_expression *ast_optimizer::fold_constants(ast_expression *node)
{
   /* Your code here */
  /*
  ast_binaryoperation opr = node->get_ast_binaryoperation();
  constant_value lvalue;
  if (opr->left->get_ast_id() != NULL){
    sym_index sym_p = opr->left->get_ast_id()->sym_p;
    symbol* sym = sym_tab->get_symbol(sym_p);
    if(sym->type == SYM_CONST){
      lvalue = sym->get_constant_symbol()->const_value;
    }
    else{
      return node; 
    }
  }
  else if(node->left->get_ast_integer() != NULL){
    lvalue = opr->left->get_ast_integer()->value;
  }
  else if (opr->left->get_ast_real() ! = NULL){
    lvalue = opr->left->get_ast_real()->value;
  }
  else{
    fatal("Should not be here 1");
  }

  constant_value rvalue;
  if (opr->right->get_ast_id() != NULL){
    sym_index sym_p = opr->right->get_ast_id()->sym_p;
    symbol* sym = sym_tab->get_symbol(sym_p);
    if(sym->type == SYM_CONST){
      rvalue = sym->get_constant_symbol()->const_value;
    }
    else{
      return node; 
    }
  }
  else if(opr->right->get_ast_integer() != NULL){
    rvalue = opr->right->get_ast_integer()->value;
  }
  else if (opr->right->get_ast_real() ! = NULL){
    rvalue = opr->right->get_ast_real()->value;
  }
  else{
    fatal("Should not be here 2");
  }
  
  if(node->type == integer_type) {
    return new ast_integer(node->pos, lvalue + rvalue);
  }
  else {
    return new ast_real(node->pos, lvalue + rvalue);
  }
  */
  return NULL;
  }

/* All the binary operations should already have been detected in their parent
   nodes, so we don't need to do anything at all here. */
void ast_add::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_sub::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_mult::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_divide::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_or::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_and::optimize()
{
  /* Your code here */ 
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_idiv::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_mod::optimize()
{
  /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}



/* We can apply constant folding to binary relations as well. */
void ast_equal::optimize()
{
    /* Your code here */
}

void ast_notequal::optimize()
{
    /* Your code here */
}

void ast_lessthan::optimize()
{
    /* Your code here */
}

void ast_greaterthan::optimize()
{
    /* Your code here */
}



/*** The various classes derived from ast_statement. ***/

void ast_procedurecall::optimize()
{
  /* Your code here */
  id->optimize();
  parameter_list->optimize();
}


void ast_assign::optimize()
{
  /* Your code here */
  cout << "ast_assign" << endl;
  lhs->optimize();
  rhs->optimize();
 
  rhs = optimizer->fold_bin(rhs);
}


void ast_while::optimize()
{
  /* Your code here */
  condition->optimize();
  body->optimize();

  condition = optimizer->fold_bin(condition);
}


void ast_if::optimize()
{
  /* Your code here */
  condition->optimize();
  body->optimize();
  if(elsif_list != NULL) {
    elsif_list->optimize();
  }
  if(else_body != NULL) {
    else_body->optimize();
  }

  condition = optimizer->fold_bin(condition);
}


void ast_return::optimize()
{
  /* Your code here */
  value->optimize();
  value = optimizer->fold_bin(value);
}


void ast_functioncall::optimize()
{
  /* Your code here */
  id->optimize();
  parameter_list->optimize();
}

void ast_uminus::optimize()
{
  /* Your code here */
  expr->optimize();
  expr = optimizer->fold_bin(expr);
}

void ast_not::optimize()
{
  /* Your code here */
  expr->optimize();
  expr = optimizer->fold_bin(expr);
}


void ast_elsif::optimize()
{
  /* Your code here */
  condition->optimize();
  body->optimize();

  condition = optimizer->fold_bin(condition);
}



void ast_integer::optimize()
{
    /* Your code here */
}

void ast_real::optimize()
{
    /* Your code here */
}

/* Note: See the comment in fold_constants() about casts and folding. */
void ast_cast::optimize()
{
  /* Your code here */
  expr->optimize();
  expr = optimizer->fold_bin(expr);
}

void ast_procedurehead::optimize()
{
    fatal("Trying to call ast_procedurehead::optimize()");
}


void ast_functionhead::optimize()
{
    fatal("Trying to call ast_functionhead::optimize()");
}
