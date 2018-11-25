#ifndef ewegen_h
#define ewegen_h
#include <fstream>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Clase EweGenerator que contiene el constructor
 * con los métodos addTo(str, fileName), proofEWE(name),
 * initEWE(expr, str, i), waitEWE(str) y closeEWE(str).
 */

class EweGenerator{
 public:
  EweGenerator();
  void addTo(string str, string fileName);
  bool proofEWE(string name);
  void initEWE(const string expr, string str, int i);
  void waitEWE(string str);
  void closeEWE(string str);
};

/** Declaración externa para *eweGen. */

extern EweGenerator *eweGen;
#endif
