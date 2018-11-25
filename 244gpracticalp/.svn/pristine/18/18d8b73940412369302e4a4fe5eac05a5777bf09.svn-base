#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in){
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return Prog();
}

AST* Parser::Prog() {
   AST* result = Expr();
   Token* t = scan->getToken();

   if (t->getType() != eof) {
      cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
      throw ParseError;
   }

   return result;
}

AST* Parser::Expr() {
   return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e) {
   Token* t = scan->getToken();

   if (t->getType() == add) {
      return RestExpr(new AddNode(e,Term()));
   }

   if (t->getType() == sub)
      return RestExpr(new SubNode(e,Term()));

   scan->putBackToken();

   return e;
}

AST* Parser::Term() {
  return RestTerm(Storable());
   // Token* t = scan->getToken();

   // if (t->getType() == number) {
   //    istringstream in(t->getLex());
   //    int val;
   //    in >> val;
   //    return new NumNode(val);
   // }

   // cout << "Term not implemented" << endl;

   // throw ParseError;
}

AST* Parser::RestTerm(AST* e) {
  Token* t = scan->getToken();

  if (t->getType() == times) {
    return RestTerm(new TimesNode(e, Storable()));
  }

  if (t->getType() == divide){
    return RestTerm(new DivideNode(e, Storable()));
  }

  if (t->getType() == mod){
    return RestTerm(new ModNode(e, Storable()));
  }
  
  
  scan->putBackToken();

  return e;
}

AST* Parser::Storable() {
  AST* result = Factor();

  Token* t = scan->getToken();

  if (t->getType() == keyword){
    if (t->getLex() == "S"){
      return new StoreNode(result);
    }else{
      cout << "Error: Expected S found "
	   << t->getLex() << endl;
      throw ParseError;
    }
  }

  scan->putBackToken();

  return result;
   // cout << "Storable not implemented" << endl;

   // throw ParseError;
  
}

AST* Parser::Factor() {
   // cout << "Factor not implemented" << endl;

   // throw ParseError;

  Token* t = scan->getToken();

  if(t->getType() == number){
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }

  if(t->getType() == keyword){
    if(t->getLex() == "R"){
      
      return new RecallNode();
    }else{
      cout << "Error: Expected R found"
	   << t->getLex() << endl;
      throw ParseError;
    }
  }

  if(t->getType() == lparen){
    AST* result = Expr();

    t = scan->getToken();
    if(t->getType() == rparen){
      return result;
    }else{
      cout << "Error: expected )" << endl;
      throw ParseError;
    }
  }
  cout << "Expected number, R o (" << endl;

  throw ParseError;
}
   
