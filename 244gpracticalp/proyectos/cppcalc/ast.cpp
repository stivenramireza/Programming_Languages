#include "ast.h"
#include <iostream>
#include <map>
#include <iterator>
#include "calculator.h"
#include "calcutils.h"
#include <sstream>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

/** Constructor de la clase AST. */

AST::AST() {}

/** Destructor de la clase AST. */

AST::~AST() {}

/**
 * Clase BinaryNode que recibe dos atributos
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

/**
 * Destructor de la clase BinaryNode.
 */

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}

/**
 * Método que retorna lo obtenido en la izquierda
 * del árbol abstracto sintáctico AST.
 * @return AST*.
 */
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

/**
 * Método que retorna lo obtenido en la derecha
 * del árbol abstracto sintáctico AST.
 * @return AST*.
 */

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

/**
 * Clase UnaryNode que recibe un atributo
 * sub del árbol abstracto sintáctico AST.
 * @param sub.
 */

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

/**
 * Destructor de la clase UnaryNode.
 */

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}

/**
 * Método que retorna lo obtenido en el único
 * hijo del árbol abstracto sintáctico AST.
 * @return *AST.
 */
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

/**
 * Clase AddNode que permite llevar a cabo la
 * suma o adición de los hijos izquierdo y derecho
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

/**
 * Método que permite evaluar el resultado entero de
 * la suma del hijo izquierdo con el hijo derecho.
 * @return int.
 */ 

int AddNode::evaluate() {
  return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

/**
 * Método que permite evaluar el resultado de la suma del
 * hijo izquierdo con el hijo derecho y lo convierte a
 * código en EWE.
 * @return string.
 */

string AddNode::hardest(){
  string go = getLeftSubTree()->hardest() + getRightSubTree()->hardest();
  #ifdef debug
   cout << "Add" << endl;
  #endif
  go += "# Add\n";
  go += " second := M[sp + 0]\n";
  go += " first := M[sp + 1]\n";
  go += " first := first + second\n";
  go += " sp := sp + one\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase SubNode que permite llevar a cabo la
 * resta de los hijos izquierdo y derecho
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

/**
 * Método que permite evaluar el resultado entero de
 * la resta del hijo izquierdo con el hijo derecho.
 * @return int.
 */

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

/**
 * Método que permite evaluar el resultado de la resta del
 * hijo izquierdo con el hijo derecho y lo convierte a
 * código en EWE.
 * @return string.
 */

string SubNode::hardest(){
  string go = getLeftSubTree()->hardest() + getRightSubTree()->hardest();
  #ifdef debug
   cout << "Sub" << endl;
  #endif
  go += "# Sub\n";
  go += " second := M[sp + 0]";
  go += " first := M[sp + 1]\n";
  go += " first := first - second\n";
  go += " sp := sp + one\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase TimesNode que permite llevar a cabo la
 * multiplicación de los hijos izquierdo y derecho
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

TimesNode::TimesNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

/**
 * Método que permite evaluar el resultado entero de
 * la multiplicación del hijo izquierdo con el hijo derecho.
 * @return int.
 */

int TimesNode::evaluate() {
  return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

/**
 * Método que permite evaluar el resultado de la multiplicación del
 * hijo izquierdo con el hijo derecho y lo convierte a
 * código en EWE.
 * @return string.
 */

string TimesNode::hardest(){
  string go = getLeftSubTree()->hardest() + getRightSubTree()->hardest();
  #ifdef debug
   cout << "Times" << endl;
  #endif
  go += "# Times\n";
  go += " second := M[sp + 0]\n";
  go += " first := M[sp + 1]\n";
  go += " first := first * second\n";
  go += " sp := sp + one\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase DivideNode que permite llevar a cabo la
 * división de los hijos izquierdo y derecho
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

DivideNode::DivideNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

/**
 * Método que permite evaluar el resultado entero de
 * la división del hijo izquierdo con el hijo derecho.
 * @return int.
 */

int DivideNode::evaluate() {
  return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

/**
 * Método que permite evaluar el resultado de la división del
 * hijo izquierdo con el hijo derecho y lo convierte a
 * código en EWE.
 * @return string.
 */

string DivideNode::hardest(){
  string go = getLeftSubTree()->hardest() + getRightSubTree()->hardest();
  #ifdef debug
   cout << "Divide" << endl;
  #endif
  go += "# Divide\n";
  go += " second := M[sp + 0]\n";
  go += " first := M[sp + 1]\n";
  go += " first := first / second\n";
  go += " sp := sp + one\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase ModNode que permite llevar a cabo el
 * módulo de los hijos izquierdo y derecho
 * del árbol abstracto sintáctico AST.
 * @param left.
 * @param right.
 */

ModNode::ModNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

/**
 * Método que permite evaluar el resultado entero de
 * el módulo del hijo izquierdo con el hijo derecho.
 * @return int.
 */

int ModNode::evaluate() {
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

/**
 * Método que permite evaluar el resultado del módulo del
 * hijo izquierdo con el hijo derecho y lo convierte a
 * código en EWE.
 * @return string.
 */

string ModNode::hardest(){
  string go = getLeftSubTree()->hardest() + getRightSubTree()->hardest();
  #ifdef debug
   cout << "Mod" << endl;
  #endif
  go += "# Modulo\n";
  go += " second := M[sp + 0]\n";
  go += " first := M[sp + 1]\n";
  go += " first := first % second\n";
  go += " sp := sp + one\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase NumNode que recibe el valor entero
 * del árbol abstracto sintáctico AST.
 * @param n.
 */

NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

/**
 * Método que retorna el valor obtenido
 * en el árbol abstracto sintáctico AST.
 * @return int.
 */

int NumNode::evaluate() {
   return val;
}

/**
 * Método que permite evaluar el resultado del valor obtenido
 * en el árbol abstracto sintáctico AST y lo convierte a código
 * en EWE.
 * @return string.
 */

string NumNode::hardest(){
  stringstream ss;
  ss << val;
  string go = "# Push ("+ss.str()+")\n";
  #ifdef debug
   cout << "Num" << endl;
  #endif
  go += " sp := sp - one\n";
  go += " first := " + ss.str()+"\n";
  go += " M[sp + 0] := first\n";
  return  go;
}

/**
 * Clase NegationNode que recibe un subárbol.
 * @param *sub.
 */ 

NegationNode::NegationNode(AST *sub):
  UnaryNode(sub)
{}

/**
 * Método que retorna el valor de lo obtenido en el subárbol
 * pero con el resultado negativo.
 * @return int.
 */

int NegationNode::evaluate(){
  return -(getSubTree()->evaluate());
}

/**
 * Método que permite evaluar el valor obtenido en el árbol 
 * abstracto sintáctico AST y lo convierte a código en EWE.
 * @return string.
 */

string NegationNode::hardest(){
  string go = getSubTree()->hardest();
  go += "# Negation\n";
  go += " temp := M[sp + 0]\n";
  go += " first := zero - temp\n";
  go += " M[sp + 0] := first\n";
  return go;
}

/**
 * Clase StoreNode que recibe un subárbol de la
 * clase UnaryNode.
 * @param *sub.
 */

StoreNode::StoreNode(AST* sub) :
  UnaryNode(sub) {}

/**
 * Método que permite calcular el valor en el store, después
 * de haberlo realizado en el evaluate() del subárbol y retorna
 * lo obtenido en el recall().
 * @return int.
 */

int StoreNode::evaluate(){
  calc->store(getSubTree()->evaluate());
  return calc->recall();
}

/**
 * Método que permite evaluar el valor obtenido en el Store (S)
 * y convertirlo a código en EWE.
 * @return string.
 */

string StoreNode::hardest(){
  string go = getSubTree()->hardest();
  #ifdef debug
   cout << "Store" << endl;
  #endif
  go += "# Store\n";
  go += " memory := M[sp + 0]\n";
  return go;
}

/**
 * Clase MinusNode que recibe un subárbol.
 * @param *sub.
 */

MinusNode::MinusNode(AST *sub):
  UnaryNode(sub)
{}

/**
 * Método que permite calcular el valor en minus, después
 * de haberlo realizado en el evaluate() del subárbol y retorna
 * lo obtenido en el recall() con un valor menor en la memoria.
 * @return int.
 */

int MinusNode::evaluate(){
  calc->minus(getSubTree()->evaluate());
  return calc->recall();
}

/**
 * Método que evalúa el valor obtenido en el Minus (M)
 * y convertirlo a código en EWE.
 * @return string.
 */

string MinusNode::hardest(){
  string go = getSubTree()->hardest();
  #ifdef debug
   cout << "Minus" << endl;
  #endif
  go += "# Minus Memory\n";
  go += " second := M[sp + 0]\n";
  go += " memory := memory - second\n";
  go += " M[sp + 0] := memory\n";
  return go;
}

/**
 * Clase PlusNode que recibe un subárbol.
 * @param *sub.
 */

PlusNode::PlusNode(AST *sub):
  UnaryNode(sub)
{}

/**
 * Método que permite calcular el valor en el plus, después de
 * haberlo realizado en el evaluate() del subárbol y retorna
 * lo obtenido en el recall() con un valor mayor en la memoria.
 * @return int.
 */

int PlusNode::evaluate(){
  calc->plus(getSubTree()->evaluate());
  return calc->recall();
}

/**
 * Método que permite evaluar el valor obtenido en el Plus (P)
 * y convertirlo a código en EWE.
 * @return string.
 */

string PlusNode::hardest(){
  string go = getSubTree()->hardest();
  #ifdef debug
   cout << "Plus" << endl;
  #endif
  go += "# Plus Memory\n";
  go += " second := M[sp + 0]\n";
  go += " memory := memory + second\n";
  go += " M[sp+0] := memory\n";
  return go;
}

/**
 * Clase RecallNode que extiende de AST.
 */

RecallNode::RecallNode() : AST()
{}

/**
 * Método que permite calcular el resultado después de haberlo
 * realizado en el evaluate() del subárbol y retorna lo obtenido
 * en el recall().
 * @return int.
 */

int RecallNode::evaluate(){
  return calc->recall();
}

/**
 * Método que permite evaluar el valor obtenido en el Recall (R)
 * y lo convierte a código en EWE.
 * @return string.
 */

string RecallNode::hardest(){
  string go = "# Recall\n";
  #ifdef debug
   cout << "Recall" << endl;
  #endif
  go += " sp := sp - one\n";
  go += " M[sp + 0] := memory\n";
  return go;
}

/**
 * Clase ClearNode que extiende de AST.
 */

ClearNode::ClearNode() : AST()
{}

/**
 * Método que permite calcular el valor en el clear, después de
 * haberlo realizado en el evaluate() del subárbol y retorna
 * lo obtenido en el recall() con un valor de 0 en la memoria.
 * @return int.
 */

int ClearNode::evaluate(){
  calc->clear();
  return calc->recall();
}

/**
 * Método que permite evaluar el valor obtenido en el Clear (C)
 * y lo convierte a código en EWE.
 * @return string.
 */

string ClearNode::hardest(){
  string go = "# Clear\n";
  #ifdef debug
   cout << "Clear" << endl;
  #endif
  go += " memory := zero\n";
  go += " sp := sp - one\n";
  go += " M[sp + 0] := memory\n";
  return go;
}

/**
 * Clase AssignNode que recibe cómo parámetro la asignación
 * de un string a la izquierda del árbol y un AST* a la derecha.
 * @param left.
 * @param right.
 */

AssignNode::AssignNode(std::string left, AST* right):
  AST(),
  rightTree(right),
  name(left)
{}

/**
 * Método que permite obtener el nombre de la asignación.
 * @return string.
 */
std::string AssignNode::getName(){
  return name;
}

/**
 * Método que retorna el valor de la izquierda del árbol
 * abstracto sintáctico AST.
 * @return AST*.
 */

AST *AssignNode::getRightSubTree(){
  return rightTree;
}

/**
 * Método que permite evaluar la expresión del nombre y guardarla
 * en un vector <string> como el resultado obtenido en la izquierda
 * del árbol abstracto sintáctico AST.
 * @return int.
 */

int AssignNode::evaluate(){
  ass.push_back(getName());
  vars[getName()] = getRightSubTree()->evaluate();
  return vars[getName()];
}

/**
 * Método que permite evaluar el valor obtenido en la asignación
 * y convertirlo a código en EWE.
 * @return string.
 */

string AssignNode::hardest(){
  string go = getRightSubTree()->hardest();
  go += "# Assign\n";
  go += " " + getName() + " := M[sp + 0]\n";
  #ifdef debug
   cout << "Add" << endl;
  #endif
  return go;
}

/**
 * Clase IdentifierNode que recibe un string en la izquierda del
 * árbol abstracto sintáctico AST.
 * @param left.
 */

IdentifierNode::IdentifierNode(std::string left):
  AST(),
  name(left)
{}

/**
 * Método que permite evaluar la expresión y guardarla en un map<string, int>
 * donde se encuentra el nombre del identificador y retorna el resultado
 * obtenido en el árbol abstracto sintáctico AST.
 * @return int.
 */

int IdentifierNode::evaluate(){
  map<string, int>::iterator it = vars.find(name);
  if(it != vars.end())
    return vars[name];
  return vars[name] = 0;
}

/**
 * Método que permite evaluar la expresión obtenida en el map<string, int>
 * y convertirlo a código en EWE.
 * @return string.
 */

string IdentifierNode::hardest(){
  string go = "";
  std::map<string, int>::iterator it = vars.find(name);
  #ifdef debug
   cout << "Add" << endl;
  #endif
  if(it != vars.end()){
    go += "# Push #("+it->first+")\n";
    go += " sp := sp - one\n";
    go += " first := " + it->first+"\n";
    go += " M[sp + 0] := first\n";
  }else{
    go += "#Push #("+name+")\n";
    go += " sp := sp - one\n";
    go += " first := "+ name +"\n";
    go += " M[sp + 0] := first\n";
  }
  return go;
}

/**
 * Clase EmptyNode que recibe un valor entero que se
 * adiciona al valor del árbol abstracto sintáctico AST.
 * @param add.
 */

EmptyNode::EmptyNode(int add):
  AST(),
  val(add),
  inf(1000000007)
{}

/**
 * Método que permite evaluar la expresión de la adición
 * del inf con el valor obtenido.
 * @return int.
 */

int EmptyNode::evaluate(){
  return inf + val;
}

/**
 * Método que retorna una cadena vacía para el código
 * generado en EWE.
 * @return string.
 */

string EmptyNode::hardest(){
  return "";										 
}
