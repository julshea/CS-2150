//filename: stackNode.cpp
//jts6mq - Julia Shea - lab3-9/18

#include "stackNode.h"
#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//default constructor, initialize the value to 0 and the pointer to null
stackNode::stackNode(){
  value=0;
  next=nullptr;
}
