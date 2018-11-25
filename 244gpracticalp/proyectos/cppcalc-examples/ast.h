#pragma once

// using namespace std;

class AST {
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
};

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

class UnaryNode : public AST {
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

class AddNode : public BinaryNode {
 public:
   AddNode(AST* left, AST* right);
   
   int evaluate();
};

class SubNode : public BinaryNode {
 public:
   SubNode(AST* left, AST* right);

   int evaluate();
};

class TimesNode : public BinaryNode {
 public:
  TimesNode(AST * left, AST* right);
  int evaluate();
};

class DivideNode : public BinaryNode {
 public:
  DivideNode(AST * left, AST* right);
  int evaluate();
};

class ModNode : public BinaryNode {
 public:
  ModNode(AST * left, AST* right);
  int evaluate();
};

class NumNode : public AST {
 public:
   NumNode(int n);

   int evaluate();

 private:
   int val;
};

class StoreNode : public UnaryNode {
 public:
  StoreNode(AST* sub);

  int evaluate();
};

class RecallNode : public AST {
 public:
  RecallNode();

  int evaluate();
};
