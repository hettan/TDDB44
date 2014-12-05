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
  index->optimize();
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



fold_value ast_optimizer::fold_int(ast_node_type tag, long lvalue, long rvalue) {
  fold_value res;
  res.type = integer_type;
  switch(tag) {
  case AST_ADD:
     res.value.ival = lvalue + rvalue;
     break;
  case AST_SUB:
    res.value.ival = lvalue - rvalue;
    break;
  case AST_DIVIDE:
    res.type = real_type;
    res.value.rval = lvalue / rvalue;
    break;
  case AST_MULT:
    res.value.ival = lvalue * rvalue;
    break;
  case AST_IDIV:
    res.value.ival = (long)(lvalue / rvalue);
    break;
  case AST_MOD:
    res.value.ival = lvalue % rvalue;
    break;
  case AST_OR:
    res.value.ival = (lvalue || rvalue);
    break;
  case AST_AND:
    res.value.ival = (lvalue && rvalue);
    break;
  default:
    fatal("Error optimizing, couldn't find a valid operation. INT");
  }
  return res;
}


double ast_optimizer::fold_float(ast_node_type tag, double lvalue, double rvalue) {
  switch(tag) {
  case AST_ADD:
     return lvalue + rvalue;
  case AST_SUB:
    return lvalue - rvalue;
  case AST_DIVIDE:
    return lvalue / rvalue;
  case AST_MULT:
    return lvalue * rvalue;
  default:
    fatal("Error optimizing, couldn't find a valid operation. REAL");
    return 0;
  }
}

ast_expression *ast_optimizer::get_new_node(position_information *pos, ast_node_type tag, fold_value lvalue, fold_value rvalue) {
  
  if(lvalue.type == integer_type && rvalue.type == integer_type){
    fold_value folded_int = fold_int(tag, lvalue.value.ival, rvalue.value.ival);
    if(folded_int.type == integer_type) {
      return new ast_integer(pos, folded_int.value.ival);
    }
    else {
      return new ast_real(pos, folded_int.value.rval);
    }
  }

  if(lvalue.type == integer_type && rvalue.type == real_type){
    return new ast_real(pos, fold_float(tag, (double)lvalue.value.ival, rvalue.value.rval));
  }
  
  if(lvalue.type == real_type && rvalue.type == integer_type){
    return new ast_real(pos, fold_float(tag, lvalue.value.rval, (double)rvalue.value.ival));
  }
  
  if(lvalue.type == real_type && rvalue.type == real_type){
    return new ast_real(pos, fold_float(tag, lvalue.value.rval, rvalue.value.rval));
  }

  fatal("couln't create node");
  return NULL;
}

ast_expression *ast_optimizer::fold_bin(ast_expression *node) {
  if(is_binop(node)) {
    ast_binaryoperation* opr = node->get_ast_binaryoperation();
    fold_value lvalue = get_constant_value(opr->left);  
    fold_value rvalue = get_constant_value(opr->right);
    if (lvalue.type == void_type || rvalue.type == void_type){
      return node;
    }
    
    position_information *pos = node->pos;
    free(node);
    return get_new_node(pos, opr->tag, lvalue, rvalue);
  }
  else {
    return node;
  }
}

fold_value ast_optimizer::get_constant_value(ast_expression *node) {
  fold_value f_value;
  f_value.type = void_type;
  if(is_constant(node)) {
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
    f_value.value.ival = node->get_ast_integer()->value;
    f_value.type = integer_type;
  }

  else if (node->tag == AST_REAL){
    f_value.value.rval = node->get_ast_real()->value;
    f_value.type = real_type;
  }

  else if (node->tag == AST_CAST){
    fold_value cast_value = get_constant_value(node->get_ast_cast()->expr);
    if (cast_value.type != void_type){
	f_value = cast_value;
    }
  }
  return f_value;
}

/* This convenience method is used to apply constant folding to all
   binary operations. It returns either the resulting optimized node or the
   original node if no optimization could be performed. */
ast_expression *ast_optimizer::fold_constants(ast_expression *node)
{
  /* Your code here */
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
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_notequal::optimize()
{
    /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_lessthan::optimize()
{
    /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
}

void ast_greaterthan::optimize()
{
    /* Your code here */
  left->optimize();
  right->optimize();
  left = optimizer->fold_bin(left);
  right = optimizer->fold_bin(right);
  
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
  lhs->optimize();
  rhs->optimize();
 
  rhs = optimizer->fold_bin(rhs);
}


void ast_while::optimize()
{
  /* Your code here */
  condition->optimize();
  if(body != NULL){ 
    body->optimize();
  }
  condition = optimizer->fold_bin(condition);
}


void ast_if::optimize()
{
  /* Your code here */
  condition->optimize();
  if(body != NULL) {
    body->optimize();
  }
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
  if(value != NULL) {
    value->optimize();
    value = optimizer->fold_bin(value);
  }
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
  if(body != NULL) {
    body->optimize();
  }

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
