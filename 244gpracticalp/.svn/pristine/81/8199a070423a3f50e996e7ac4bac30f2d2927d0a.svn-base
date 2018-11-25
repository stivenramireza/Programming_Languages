#include "scanner.h"
#include "calcex.h"
#include <iostream>
#include <string>
#include "calcutils.h"

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Constantes para las palabras reservadas.
 */

const int numberOfKeywords = 5;

const string keywd[numberOfKeywords] = {
  string("S"), string("M"), string("P"), string("C"), string("R")
};

/**
 * Método que permite reconocer si la línea ingresada es una letra.
 * @return int.
 */

int isLetter(char c) {
   return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * Método que permite reconocer si la línea ingresada es un dígito.
 * @return int. 
 */

int isDigit(char c) {
  return (c >= '0' && c <= '9');
}

/**
 * Método que permite reconocer si la línea ingresada tiene espacios 
 * en blanco.
 * @return int.
 */

int isWhiteSpace(char c) {
  return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * Clase Scanner que contiene su constructor con la entrada, y los
 * atributos lineCount, colCount, needToken y lastToken. 
 */

Scanner::Scanner(istream* in):
  inStream(in),
  lineCount(1),
  colCount(-1),
  needToken(true),
  lastToken(0)
{}

/** Destructor de Scanner */

Scanner::~Scanner() {
   try {
      delete inStream;
   } catch (...) {}
}

/**
 * Método que permite saber si requier un token en la entrada de la
 * aplicación.
 */

void Scanner::putBackToken() {
   needToken = false;
}

/**
 * Método que permite obtener el token y saber de qué tipo es, con el fin
 * de llevar a cabo sus respectivas operaciones que están dadas por unos
 * casos que determinan si es add, sub, times, divide, mod, lparen, rparen.
 * Además, evalúa si es un número, identificador o palabra reservada para
 * crear un LexicalToken(type, lex, line, column). De lo contrario crea un
 * Token(type, line, colum).
 * @return Token*. 
 */

Token* Scanner::getToken() {
   if (!needToken) {
      needToken=true;
      return lastToken;
   }

   Token* t;
   int state=0;
   bool foundOne=false;
   char c;
   string lex;
   TokenType type;
   int k;
   int column, line;
   c = inStream->get();

   while (!foundOne) {
      colCount++;
      switch (state) {
         case 0 : 
            lex = "";
            column=colCount;
            line = lineCount;
            if (isLetter(c)) state=1;
            else if (isDigit(c)) state=2;
            else if (c=='+') state=3;
            else if (c=='-') state=4;
            else if (c=='*') state=5;
            else if (c=='/') state=6;
	    else if (c=='%') state=7;
            else if (c=='(') state=8;
            else if (c==')') state=9;
	    else if (c=='=') state=10;
	    else if (c==';') state=11;
            else if (c=='\n' || ((int)c) == 13) {
	      state = 12;
            }
            else if (isWhiteSpace(c));
            else if (inStream->eof() or c == -1) {
               foundOne=true;
               type=eof;
            }
            else {
            }
            break;
         case 1 :
            if (isLetter(c) || isDigit(c)) state=1;
            else {
               for (k=0;k<numberOfKeywords;k++)
                  if (lex == keywd[k]) {
                     foundOne = true;
                     type = keyword;
                  }
               if (!foundOne) {
                  type = identifier;
                  foundOne = true;
               }
            }
            break;
         case 2 :
            if (isDigit(c)) state=2;
            else {
               type = number;
               foundOne=true;
            }
            break;
         case 3 :
            type = add;
            foundOne = true;
            break;
         case 4 :
            type = sub;
            foundOne = true;
            break;
         case 5 :
            type = times;
            foundOne=true;
            break;
         case 6 :
            type = divide;
            foundOne=true;
            break;
         case 7 :
	    type = mod;
	    foundOne=true;
	    break;
         case 8 :
            type = lparen;
            foundOne=true;
            break;
         case 9 :
            type = rparen;
            foundOne=true;
            break;
         case 10:
	   type = eq;
	   foundOne = true;
	   break;
         case 11:
	   type = smc;
	   foundOne = true;
	   break;
      case 12:
	colCount=-1;
	type = eol;
	foundOne = true;
	break;
      }
      
      if (!foundOne) {
         lex = lex + c;
         c = inStream->get();
      }
   }
   inStream->putback(c);
   colCount--;
   if (type == number || type == identifier || type == keyword) {
      t = new LexicalToken(type,new string(lex), line, column);
   }
   else {
      t = new Token(type,line,column);
   }

#ifdef debug
   cout << "just found " << lex << " with type " << type << endl;
#endif

   lastToken = t;
   return t;
}
