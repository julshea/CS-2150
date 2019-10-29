//filename: postfixCalculator.cpp - Julia Shea-jts6mq-9/14-lab3

#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "stackNode.h"
#include "postfixCalculator.h"
using namespace std;

//default constructor
postfixCalculator::postfixCalculator(){
  Stack *s = new Stack();
}


//CALC FUNCTIONS
void postfixCalculator::add(){
  if (s.empty() == true){
    exit(-1);
  }
  else{
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  int z = x + y;
  s.push(z);
  } 
}

//y-x
void postfixCalculator::subtract(){
  if (s.empty() == true){
    exit(-1);
  }
  else{
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  int z = y - x;
  s.push(z);
  } 
}

//y/x
void postfixCalculator::divide(){
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  int z = y/x;
  s.push(z);
}

void postfixCalculator::multiply(){
  if (s.empty() == true){
    exit(-1);
  }
  else{
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  int z = y * x;
  s.push(z);
  }
 }

void postfixCalculator::negate(){
  if (s.empty() == true){
    exit(-1);
  }
  else{
  int x = s.top();
  s.pop();
  int z = x*-1;
  s.push(z);
  }
 }

//STACK FUNCTIONS:

//adds a value to the top of the stack
void postfixCalculator::pushValue(int e){
  s.push(e);
}

//returns the value at the top of the stack
//does not remove it
int postfixCalculator::getTopValue(){
  return s.top();
}

//removes the value at the top of the stack
//does not return it
void postfixCalculator::removeTopValue(){
   s.pop();
}

//returns true if stack is empty, false if not
bool postfixCalculator::isEmpty(){
  return s.empty();
}

