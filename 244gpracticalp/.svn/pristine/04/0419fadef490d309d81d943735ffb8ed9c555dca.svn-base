#pragma once
#include "ast.h"
#include "scanner.h"
#include <vector>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

/**
 * Clase Parser que contiene el constructor determinado
 * por la entrada, el destructor, un AST* en el parse(),
 * un método público getTree() y unos métodos privados que
 * realizan las operaciones de la nueva gramática independiente
 * de contexto LL(1).
 */

class Parser {
 public:
   Parser(istream* in);
   ~Parser();
   AST* parse();
   void getTree();
 private:
   AST* Prog();
   AST* Stmts();
   AST* Expr();
   AST* RestExpr(AST* e);
   AST* Term();
   AST* RestTerm(AST* t);
   AST* Storable();
   AST* MemOperation(AST *e);
   AST* Negation();
   AST* Factor();
   Scanner* scan;
};
