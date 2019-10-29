//filename: stackNode.cpp
//jts6mq - Julia Shea - lab3 - 9/18

#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

class stackNode{
 public:
  stackNode(); //constructor

 private:
  int value;
  stackNode *next;

  friend class Stack;

};
#endif
