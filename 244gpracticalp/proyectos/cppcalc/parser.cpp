#include <iterator>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "calcutils.h"
#include "parser.h"
#include "calcex.h"

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

/** Constructor de Parser. */

Parser::Parser(istream* in){
   scan = new Scanner(in);
}

/** Destructor de Parser. */

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

/**
 * Retorna el valor de Prog() al AST.
 * @return AST*.
 */

AST* Parser::parse() {
  return Prog();
}

/**
 * Retorna el valor del resultado obtenido en
 * Stmts() si el tipo es diferente del final 
 * de fichero.
 * @return AST*.
 */

AST* Parser::Prog() {
  AST *res = Stmts();
  Token *t = scan->getToken();
  if(t->getType() != eof){
    return new EmptyNode(1);
  }
  return res;
}

/**
 * Crea un token, evalúa si es un identificador,
 * un equal o un smc. Si cumple estas condiciones crea
 * un nodo de asignación con el string obtenido y el 
 * resultado en el árbol abstracto sintáctico, sino
 * retorna un nodo vacío.
 * @return AssignNode(ret, rest).
 * @return EmptyNode().
 */

AST* Parser::Stmts(){
  Token *t = scan->getToken();
  if(t->getType() == identifier){
    string ret = t->getLex();
    t = scan->getToken();
    if(t->getType() == eq){
      AST* res = Expr();
      t = scan->getToken();
      if(t->getType() == smc){
  	t = scan->getToken();
	return new AssignNode(ret, res);
      }else{
  	cout << "* parse error line: " << lc << " col: " << t->getCol() << endl;
  	return new EmptyNode(1);
      }
    }else{
      cout << "* parse error line: " << lc << " col: " << t->getCol() << endl;
      return new EmptyNode(1);
    }
  }
  if(t->getType() == eol){
    return new EmptyNode(0);
  }
}

/**
 * Retorna el resultado de la expresión evaluada
 * en el Term().
 * @return AST*.
 */

AST* Parser::Expr() {
   return RestExpr(Term());
}

/**
 * Crea un token, evalúa si es un add o un sub. Si lo
 * es, retorna un AddNode o un SubNode con el valor de
 * la expresión. De lo contrario, retorna el AST.
 * @return AST*.
 */

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

/**
 * Retorna el resultado de la expresión evaluada
 * en el Storable().
 * @return AST¨.
 */

AST* Parser::Term() {
  return RestTerm(Storable());
}

/**
 * Crea un token, evalúa si es un times, divide o mod. Si
 * lo es, retorna un TimesNode, DivideNode o ModNode con el
 * valor de la expresión. De lo contrario, retorna el AST.
 * @return AST*.
 */

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

/**
 * Crea un token, evalúa si es un sub. Si lo es retorna un
 * NegationNode con el valor del factor con signo negativo.
 * @return AST*.
 */
AST* Parser::Negation(){
  Token *t = scan->getToken();
  if(t->getType() == sub){
    return new NegationNode(Factor());
  }
  scan->putBackToken();
  return Factor();
}

/**
 * Crea un MemOperacion con el valor obtenido en Negation().
 * @return AST*.
 */

AST* Parser::Storable() {
  return MemOperation(Negation());
}

/**
 * Crea un token, evalúa si es una palabra reservada, y analiza
 * si es S, P ó M, retornando StoreNode, PlusNode o MinusNode con
 * lo obtenido en el árbol abstracto sintáctico AST.
 * @return AST*.
 */

AST* Parser::MemOperation(AST* e){
  Token *t = scan->getToken();
  
  if(t->getType() == keyword){
    if(t->getLex() == "S"){
      return new StoreNode(e);
    }
    if(t->getLex() == "P"){
      return new PlusNode(e);
    }
    if(t->getLex() == "M"){
      return new MinusNode(e);
    }
  }
  
  scan->putBackToken();
  return e;
}

/**
 * Crea un token, evalúa si es un número. Si lo es, retorna un
 * NumNode con el valor recibido. Analiza si es un keyword, sea
 * R ó C, para crear un RecallNode o ClearNode. Además, analiza
 * si es un identificador para crear un IdentifierNode con el 
 * string obtenido o si es un lparen que cree un AST con el valor
 * obtenido en Expr() y un rparen para retornar el resultado. De
 * lo contrario, se retorna un nodo vacío.
 * @return AST*.
 */

AST* Parser::Factor() {
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
    }
    if(t->getLex() == "C"){
      return new ClearNode();
    }
    cout << "* parse error line: " << lc << " col: " << t->getCol() << endl;
    return new EmptyNode(1);
  }

  if(t->getType() == identifier){
    string ret = t->getLex();
    return new IdentifierNode(ret);
  }

  if(t->getType() == lparen){
    AST* result = Expr();
    t = scan->getToken();
    if(t->getType() == rparen){
      return result;
    }else{
      cout << "* parse error line: " << lc << " col: " << t->getCol() << endl;
      return new EmptyNode(1);
    }
  }
}
