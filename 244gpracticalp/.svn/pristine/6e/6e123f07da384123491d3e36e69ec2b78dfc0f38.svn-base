#include "ast.h"
#include <iostream>
#include "calculator.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

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
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int TimesNode::evaluate() {
  return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int DivideNode::evaluate() {
  return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

ModNode::ModNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int ModNode::evaluate() {
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}

StoreNode::StoreNode(AST* sub) :
  UnaryNode(sub) { }

int StoreNode::evaluate(){
  // int valor = getSubTree()->evaluate();
  // calc->store(valor); // return valor;
  calc->store(getSubTree()->evaluate());
  return calc->recall();
}

RecallNode::RecallNode() : AST()
{}

int RecallNode::evaluate(){
  return calc->recall();
}
