#pragma once
#include <string>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Clase AST que contiene el constructor,
 * destructor, evaluate() y hardest().
 */

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
   virtual string hardest() = 0;
};

/**
 * Clase BinaryNode que extiende de AST,
 * contiene el constructor con sus atributos
 * izquierda y derecha, el destructor y los
 * métodos getLeftSubTree() y getRightSubTree().
 */

class BinaryNode : public AST {
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

/**
 * Clase UnaryNode que extiende de AST,
 * contiene su constructor con el subárbol,
 * el destructor y el método getSubTree().
 */

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

/**
 * Clase AddNode que extiende de BinaryNode,
 * contiene su constructor con los atributos
 * izquierda y derecha, el método evalute()
 * y hardest().
 */

class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);
   
   int evaluate();
   string hardest();
};

/**
 * Clase SubNode que extiende de BinaryNode,
 * contiene su constructor con los atributos
 * izquierda y derecha, el método evalute()
 * y hardest().
 */

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);

   int evaluate();
   string hardest();
};

/**
 * Clase TimesNode que extiende de BinaryNode,
 * contiene su constructor con los atributos
 * izquierda y derecha, el método evalute()
 * y hardest().
 */

class TimesNode : public BinaryNode {
 public:
  TimesNode(AST * left, AST* right);
  int evaluate();
  string hardest();
};

/**
 * Clase DivideNode que extiende de BinaryNode,
 * contiene su constructor con los atributos
 * izquierda y derecha, el método evalute()
 * y hardest().
 */

class DivideNode : public BinaryNode {
 public:
  DivideNode(AST * left, AST* right);
  int evaluate();
  string hardest();
};

/**
 * Clase ModNode que extiende de BinaryNode,
 * contiene su constructor con los atributos
 * izquierda y derecha, el método evalute()
 * y hardest().
 */

class ModNode : public BinaryNode {
 public:
  ModNode(AST * left, AST* right);
  int evaluate();
  string hardest();
};

/**
 * Clase NumNode que extiende de AST,
 * contiene su constructor con un atributo entero,
 * el método evalute() y hardest().
 */

class NumNode : public AST {
 public:
   NumNode(int n);

   int evaluate();
   string hardest();
 private:
   int val;
};

/**
 * Clase NegationNode que extiende de UnaryNode,
 * contiene su constructor con el subárbol, el
 * método evaluate() y hardest().
 */

class NegationNode: public UnaryNode{
 public:
  NegationNode(AST *sub);

  int evaluate();
  string hardest();
};

/**
 * Clase MinusNode que extiende de UnaryNode,
 * contiene su constructor con el subárbol, el
 * método evaluate() y hardest().
 */

class MinusNode: public UnaryNode{
 public:
  MinusNode(AST *sub);

  int evaluate();
  string hardest();
};

/**
 * Clase PlusNode que extiende de UnaryNode,
 * contiene su constructor con el subárbol, el
 * método evaluate() y hardest().
 */

class PlusNode: public UnaryNode{
 public:
  PlusNode(AST *sub);

  int evaluate();
  string hardest();
};

/**
 * Clase StoreNode que extiende de UnaryNode,
 * contiene su constructor con el subárbol, el
 * método evaluate() y hardest().
 */

class StoreNode : public UnaryNode {
 public:
  StoreNode(AST* sub);

  int evaluate();
  string hardest();
};

/**
 * Clase RecallNode que extiende de AST,
 * contiene su constructor vacío, el método 
 * evaluate() y hardest().
 */

class RecallNode : public AST {
 public:
  RecallNode();

  int evaluate();
  string hardest();
};

/**
 * Clase ClearNode que extiende de AST,
 * contiene su constructor vacío, el método
 * evaluate() y hardest().
 */

class ClearNode: public AST{
 public:
  ClearNode();

  int evaluate();
  string hardest();
};

/**
 * Clase AssignNode que extiende de AST,
 * con su constructor que recibe un string left
 * y un AST* right, los métodos *getRightSubTree(),
 * evaluate() y hardest().
 */

class AssignNode: public AST{
 public:
  AssignNode(std::string left, AST *right);
  std::string getName();
  AST *getRightSubTree();
  int evaluate();
  string hardest();
 private:
  std::string name;
  AST *rightTree;
};

/**
 * Clase IdentifierNode que extiende de AST,
 * con su constructor que recibe un string left,
 * los métodos evaluate() y hardest().
 */

class IdentifierNode: public AST{
 public:
  IdentifierNode(std::string left);
  int evaluate();
  string hardest();
 private:
  std::string name;
};

/**
 * Clase EmptyNode que extiende de AST,
 * con su constructor con un atributo entero,
 * los método evaluate() y hardest().
 */

class EmptyNode: public AST{
 public:
  EmptyNode(int add);
  int evaluate();
  string hardest();
 private:
  int val;
  int inf;
};
