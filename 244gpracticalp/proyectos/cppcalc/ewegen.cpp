#include "ewegen.h"
#include <fstream>
#include <map>
#include "calcutils.h"
#include <iterator>
#include <sstream>
#include <iostream>
#include <cmath>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

EweGenerator::EweGenerator()
{}

/**
 * Método que agrega al archivo .ewe el nombre asignado
 en el cat que permite ver el contenido del fichero.
 * @param str.
 * @param name.
 */

void EweGenerator::addTo(string str, string name){
  ofstream eFile;
  eFile.open(name.c_str(), ofstream::out | ofstream::app);
  eFile << str;
  eFile.close();
}

/**
 * Método que permite saber si el fichero generado está bien.
 * @param name.
 * @return bool.
 */

bool EweGenerator::proofEWE(string name){
  ifstream ifs;
  ifs.open(name.c_str());
  return ifs.good();
}

/**
 * Método que permite crear el inicio de la generación del código
 * en EWE a partir de un fichero template1.txt y con el uso de 
 * map<string, int> la generación del resto del código.
 * @param expr.
 * @param name.
 * @param i.
 */

void EweGenerator::initEWE(const string expr, string name, int i){
  ofstream eFile;
  ifstream ifs;
  eFile.open(name.c_str(), ofstream::out | ofstream::app);
  string go = "# Expresion ";
  eFile << go << " " << expr << endl;
  eFile << "start" << i+1 << ":" << endl;
  ifs.open("template1.txt", ifstream::in);
  string line;
  
  while(getline(ifs, line)){
    eFile << line << endl;
  }
  
  if(i == 0){
    eFile << " sp := 1010\n";
    for(map<string, int>::iterator it = vars.begin(); it != vars.end(); ++it){
      if(it->second < 0){
	stringstream ss;
	ss << abs(it->second);
	string var = "var := " + ss.str() + "\n";
	eFile << var;
	eFile << " " << it->first << " := " << " zero - var\n";
      }
      else
	eFile << " " << it->first << ":= " << it->second << endl;
    }
    eFile << " memory := " << "zero" << endl;
  }
  ifs.close();
  eFile.close();
}

/**
 * Método que permite crear la mitad de la generación del código
 * en EWE a través del fichero template2.txt.
 * @param name.
 */

void EweGenerator::waitEWE(string name){
  ofstream eFile;
  ifstream ifs;
  ifs.open("template2.txt", ifstream::in);
  string line;
  eFile.open(name.c_str(), ofstream::out | ofstream::app);
  while(getline(ifs, line)){
    eFile << line << endl;
  }
  ifs.close();
  eFile.close();
}

/**
 * Método que permite crear el final de la generación del código
 * en EWE a través del uso de map<string, int> para seleccionar
 * las unidades de memoria usadas estén correctas para EWE.
 * @param name.
 */

void EweGenerator::closeEWE(string name){
  ofstream eFile;
  eFile.open(name.c_str(), ofstream::out | ofstream::app);
  string go = "end: halt\n";
  go += "equ memory\tM[0]\n";
  go += "equ one  \tM[1]\n";
  go += "equ zero\tM[2]\n";
  go += "equ first\tM[3]\n";
  go += "equ second\tM[4]\n";
  go += "equ sp  \tM[5]\n";
  int start = 6;
  for(map<string, int>::iterator it = vars.begin(); it != vars.end(); it++, start++){
    stringstream ss;
    ss << start;
    go += "equ " + it->first + "\t\tM["+ss.str()+"]\n";
  }
  stringstream ss;
  ss << start;
  go += "equ var\t\tM["+ss.str()+"]\n";
  start++;
  stringstream ss1;
  ss1 << start;
  go += "equ temp\tM[" +ss1.str()+"]\n";
  start++;
  stringstream ss2;
  ss2 << start;
  go += "equ stack\tM["+ss2.str()+"]";
  eFile << go;
  eFile.close();
}
