#include "token.h"

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

/** Constructor de Token. */

Token::Token() :
  type(eof),
  line(0),
  col(0)
{}

/** Destructor de Token. */

Token::~Token() {}

/**
 * Clase Token con su contructor que tiene como atributos
 * typ, lineNum y colNum.
 */

Token::Token(TokenType typ, int lineNum, int colNum) : 
  type(typ),
  line(lineNum),
  col(colNum)
{}

/**
 * Método que permite obtener el tipo de token reconocido.
 * @return TokenType.
 */

TokenType Token::getType() const {
  return type;
}

/**
 * Método que permite obtener la línea del token reconocido.
 * @return int.
 */

int Token::getLine() const {
  return line;
}

/**
 * Método que permite obtener la columna del token reconocido.
 * @return int.
 */

int Token::getCol() const {
  return col;
}

/**
 * Método que retorna el lexema de la expresión.
 * @return string.
 */

string Token::getLex() const {
  return "";
}

/**
 * Clase LexicalToken que contiene su constructor con los atributos
 * typ, lex, lineNum y colNum.
 */

LexicalToken::LexicalToken(TokenType typ, string* lex, int lineNum, int colNum) :
   Token(typ,lineNum,colNum),
   lexeme(lex)
{}

/** Destructor de LexicalToken. */

LexicalToken::~LexicalToken() {
   try {
      delete lexeme;
   } catch (...) {}
}

/**
 * Método que retorna el lexema de la expresión.
 * @return string.
 */

string LexicalToken::getLex() const {
  return *lexeme;
}

