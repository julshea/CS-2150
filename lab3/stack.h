//Filename: stack.h
//jts6mq- Julia Shea - lab3 - 9/18

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include "stackNode.h"
using namespace std;

class stackNode;

class Stack{
 public:
  Stack(); //constructor
  ~Stack(); //destructor
  bool empty () const;
  void push (int value);
  void pop();
  int top() const;

 private:
  stackNode *head;

  friend class stackNode;;
};


#endif
