#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include "calcutils.h"
#include "calcex.h"
#include "calculator.h"
#include "ewegen.h"
#include <libgen.h>
/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

const int inf = 1000000007;
Calculator *calc;
EweGenerator *eweGen;

/**
 * Método que crea los ficheros y evalúa las expresiones generadas para
 * el código en EWE.
 * @param files.
 * @param createEWE.
 */

void readFromFile(vector<string> files, bool createEWE){
  for(int i = 0; i < files.size(); ++i){
    ifstream ifs;
    ifs.open(files[i].c_str());
    string idx = basename((char *)files[i].c_str());
    int opt = idx.find(".calc");
    string name = idx.substr(0, opt) + ".ewe";
    string line = "";
    int j = 0;
    bool can = eweGen->proofEWE(name);
    cout << "> ";
    while(getline(ifs, line)){
      if(line == "")
	line += "\n";
      if(createEWE && !can){
	eweGen->initEWE(line, name, j);
	j++;
      }
      pair<int, string> results= calc->eval(line, createEWE);
      int res = results.first;
      string opt = results.second;
      if(res != inf && res != inf + 1){
	cout << "= ";
	if(1 <= ass.size()){
	  cout << ass[0] << " <- ";
	  ass.pop_back();
	}
        cout << res << endl;
	if(createEWE && !can){
	  eweGen->addTo(opt, name);
	  eweGen->waitEWE(name);
	}
      }
      else if (res == inf){
	//	cout << "= " << endl;
      }
      else{
      	cout <<"";
      }
      lc++;
      cout << "> ";
    }
    if(createEWE && !can){
      eweGen->closeEWE(name);
    }
    if(ifs.is_open())
      ifs.close();
  }
}

/**
 * Método que lee la línea, la evalúa y genera el código EWE para el fichero.
 * @param createEWE.
 */

void readTo(bool createEWE){
  cout << "> ";
  string line;
  int j = 0;
  bool can = eweGen->proofEWE("a.ewe");
  while(getline(cin, line)){
    if(line == "")
      line += "\n";
    if(createEWE && !can){
      eweGen->initEWE(line, "a.ewe", j);
      j++;
    }
    pair<int, string> results= calc->eval(line, createEWE);
    int res = results.first;
    string opt = results.second;
    if(res != inf && res != inf + 1){
      cout << "= ";
      if(1 <= ass.size()){
	cout << ass[0] << " <- ";
	ass.pop_back();
      }
      cout << res << endl;
      if(createEWE && !can){
	eweGen->addTo(opt, "a.ewe");
	eweGen->waitEWE("a.ewe");
      }
    }else if (res == inf){
      //      cout << "= " << endl;
    }
    else
      cout <<"";
    cout << "> ";
    lc++;
  }
  if(createEWE && !can){
    eweGen->closeEWE("a.ewe");
  }
    
}

/**
 * Método que recibe una variable de ambiente, y devuelve un sufijo disminuido
 * en su tamaño que sea el valor dado al nombre de dicha variable.
 * @param **env.
 */

void goEnv(char **env){
  for(int i = 0; env[i] != NULL; ++i){
    string temp = env[i];
    if(temp.substr(0, PREFIX.size()) == PREFIX){
      string ret = temp.substr(temp.find_last_of(PREFIX) + 1, temp.size() - PREFIX.size());
      ret = ret.substr(0, ret.find("="));
      string name = PREFIX + ret;
      char *var = getenv(name.c_str());
      if(var != NULL){
	vars[ret] = atoi(var);
      }
    }
  }
}

/**
 * Método principal que ejecuta el programa, evalúa los árboles abstractos
 * sintácticos, las variables de ambiente y crea el archivo de EWE.
 * @param argc.
 * @param argv.
 */

int main(int argc, char* argv[], char **env) {
   string line;
#ifdef debug
   cout << "El programa empieza" << endl;
#endif
   
   try {
     goEnv(env);
     vector<string> files;
     string get, key;
     int val;
     bool createEWE = false;
     bool can = false;
     if(argc > 1){
       int i = 1;
       for(; i < argc;){
     	 if(strcmp(argv[i],"-v") == 0){
     	   get = argv[i + 1];
     	   get.replace(get.find("="), 1, " ");
     	   istringstream go(get);
     	   go >> key;
     	   go >> val;
     	   vars[key] = val;
     	   i+=2;
	   continue;
     	 }
	 if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-g") == 0){
	   createEWE = true;
	 }
	 get = argv[i];
	 if(get.size() >= CALCP.size()){
	   if(get.compare(get.size() - CALCP.size(),
	 		  CALCP.size(), CALCP) == 0)
	     {
	       can = true;
	       files.push_back(get);
	     }
	 }
	 i += 1;
       }
     }
     calc = new Calculator();
     eweGen = new EweGenerator();
     if(can){
       readFromFile(files, createEWE);
     }else{
       readTo(createEWE);
     }
   }
   catch(Exception ex) {
      cout << "Program Aborted due to exception!" << endl;
   }
}
