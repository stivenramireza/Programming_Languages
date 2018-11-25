#include "calculator.h"
#include "ewegen.h"
#include "parser.h"
#include "ast.h"
#include "calcutils.h"
#include <string>
#include <iostream>
#include <sstream>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

Calculator::Calculator():
   memory(0)
{}

/**
 * Método que evalúa la expresión invocando el parser, el
 * resultado obtenido en el evaluate() y hardest(), que se
 * retorna en un pair<int, string>.
 * @param expr.
 * @param gen.
 */

pair<int, string> Calculator::eval(string expr, bool gen) {
   Parser* parser = new Parser(new istringstream(expr));
   AST* tree = parser->parse();
   int result = tree->evaluate();
   string hardest = "";
   if(gen){
     hardest = tree->hardest();
   }
   delete tree;   
   delete parser;
   return make_pair(result, hardest);
}

/**
 * Método que muestra el valor de la memoria igual al valor.
 * @param val.
 */

void Calculator::store(int val) {
   memory = val;
}

/**
 * Método que muestra el valor de la memoria disminuido
 * en el valor.
 * @param val.
 */

void Calculator::minus(int val){
  memory -= val;
}

/**
 * Método que muestra el valor de la memoria aumentada
 * en el valor.
 * @param val.
 */

void Calculator::plus(int val){
  memory += val;
}

/**
 * Método que retorna el valor obtenido en la memoria.
 * @return int.
 */

int Calculator::recall() {
   return memory;
}

/**
 * Método que pone el valor de la memoria en cero.
 */ 

void Calculator::clear(){
  memory = 0;
}
