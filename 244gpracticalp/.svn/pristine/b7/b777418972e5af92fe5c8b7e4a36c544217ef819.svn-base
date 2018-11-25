#pragma once
#include <string>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Clase Calculator que contiene el constructor,
 * los métodos eval(expr, gen), store(val), minus(val),
 * plus(val), clear(), recall() y assign().
 */

class Calculator {
 public:
   Calculator();

   pair<int, string> eval(string expr, bool gen);
   void store(int val);
   void minus(int val);
   void plus(int val);
   void clear();
   int recall();
   void assign();
 private:
   int memory;
};

/** Declaración externa de calc. */

extern Calculator* calc;
