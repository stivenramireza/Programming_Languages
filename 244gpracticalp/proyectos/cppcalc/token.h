#pragma once
#include <string>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Eq -> equal
 * smc -> semicolon
 * eol -> end of line
 */

/**
 * Enumeraciones de TokenType que permite reconocer el token
 * que se está ingresando en la entrada de cppcalc.
 */

enum TokenType {
  identifier,keyword,number,add,sub,times,divide,mod,lparen,rparen,eq,smc,eol,eof,unrecognized
};

/**
 * Clase Token que contiene su constructor con los atributos
 * typ, line y col, su destructor, un método getType() de 
 * TokenType, métodos getLine() y getCol(), además de un
 * método getLext() para obtener el lexema de la expresión.
 */

class Token {
public:

  Token();
  Token(TokenType typ, int line, int col);
  virtual ~Token();

  TokenType getType() const;
  int getLine() const;
  int getCol() const;
  virtual string getLex() const;

private:
  TokenType type;
  int line,col;
};

/**
 * Clase LexicalToken que extiende de Token y contiene su
 * constructor con los atributos typ, line y col, su destructor,
 * y un método getLex() para obtener el lexema de la expresión.
 */

class LexicalToken: public Token {
 public:
   LexicalToken(TokenType typ, string* lex, int line, int col);
   ~LexicalToken();

   virtual string getLex() const;

 private:
   string* lexeme;
};





