#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
using namespace std;


Calculator* calc;

int main(int argc, char* argv[]) {
   string line;

#ifdef debug
   cout << "El programa empieza" << endl;
#endif
   
   try {

      cout << "> ";

      getline(cin, line);
      // line + '\n';

#ifdef debug
      cout << "Va a crear una calculadora" << endl;
#endif
      calc = new Calculator();

      int result = calc->eval(line);

      cout << "= " << result << endl;

      delete calc;

   }
   catch(Exception ex) {
      cout << "Program Aborted due to exception!" << endl;
   }
}
   
