#pragma once
#include <iostream>
#include "token.h"

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

/**
 * Clase Scanner que contiene el constructor determinado
 * por la entrada, el destructor, un Token* getToken()
 * y el método void putBackToken(), además de unos atributos
 * privados que reciben la entrada, cuentan las líneas y
 * las columnas.
 */

class Scanner {

 public:
  Scanner(istream* in);
  ~Scanner();

  Token* getToken();
  void putBackToken();
 
private:
  Scanner();

  istream* inStream;
  int lineCount;
  int colCount;

  bool needToken;
  Token* lastToken;
};

  
  

