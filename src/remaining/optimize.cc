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

  if(index != NULL){
    index->optimize();
  }
}

bool is_value(ast_expression *node) {
  switch(node->type) {
  case AST_INTEGER:
  case AST_REAL:
    return true;
  default:
    return false;
  }
}

bool is_constant(ast_expression *node) {
  if(node->type == AST_ID) {
    sym_index sym_p = node->get_ast_id()->sym_p;
    return (sym_tab->get_symbol_type(sym_p) == SYM_CONST);
  }
  return false;
}

ast_expression *ast_optimizer::fold_bin(ast_expression *node) {
  //OUR CODE
  /*if (is_value(node)) {
    return node;
  }
  else if(is_constant(node)) {
    return node
    }*/
  if(is_binop(node)) {
    //try fold
    return fold_constants(node);
  }
  else if(is_binrel(node)) {
    return fold_constants(node);
  }
  else {
    return node;
  }
}

constant_value *ast_optimizer::get_constant_value(ast_expression *node) {
  constant_value value;
  if(is_constant(node)) {
    sym_index sym_p = node->get_ast_id()->sym_p;
    value = sym_tab->get_symbol(sym_p)->get_constant_symbol()->const_value;
  }
  else if(node->type == AST_INTEGER){
    value = node->get_ast_integer()->value;
  }
  else if (node->type == AST_REAL){
    value = node->get_ast_real()->value;
  }
  else{
    value = -1;
  }
  return value;
}

/* This convenience method is used to apply constant folding to all
   binary operations. It returns either the resulting optimized node or the
   original node if no optimization could be performed. */
ast_expression *ast_optimizer::fold_constants(ast_expression *node)
{
    /* Your code here */
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
}

/* All the binary operations should already have been detected in their parent
   nodes, so we don't need to do anything at all here. */
void ast_add::optimize()
{
    /* Your code here */
  left->optimize();
  right->optimize();
  left = fold_constants(left);
  right = fold_constants(right);
  //this* = optimizer->fold_constants(this);
}

void ast_sub::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_mult::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_divide::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_or::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_and::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_idiv::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
}

void ast_mod::optimize()
{
    /* Your code here */
  //this* = optimizer->fold_constants(this);
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
}


void ast_assign::optimize()
{
    /* Your code here */
}


void ast_while::optimize()
{
    /* Your code here */
}


void ast_if::optimize()
{
    /* Your code here */
}


void ast_return::optimize()
{
    /* Your code here */
}


void ast_functioncall::optimize()
{
    /* Your code here */
}

void ast_uminus::optimize()
{
    /* Your code here */
}

void ast_not::optimize()
{
    /* Your code here */
}


void ast_elsif::optimize()
{
    /* Your code here */
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
}



void ast_procedurehead::optimize()
{
    fatal("Trying to call ast_procedurehead::optimize()");
}


void ast_functionhead::optimize()
{
    fatal("Trying to call ast_functionhead::optimize()");
}
