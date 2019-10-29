//Filename: testPostfixCalc.cpp - Julia Shea - jts6mq - 9/15 - lab3

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "stack.h"
#include "stackNode.h"
#include "postfixCalculator.h"
using namespace std;


int main(){
  string s;
  int operand;
  postfixCalculator p;
  
  cout << "Enter a postfix expression: " << endl;
  while (cin >> s){
  
    //evaluates the string input for operators and executes the operation:
    if(s == "+"){p.add();}
    else if(s == "-"){p.subtract();}
    else if(s == "/"){p.divide();}
    else if(s == "*"){p.multiply();}
    else if(s == "~"){p.negate();}

    //turns the operand values into integers and pushes them onto the stack:
    else{
       stringstream(s) >> operand;
       p.pushValue(operand);
    }
  }
  cout << "Result: "<< p.getTopValue() << endl;
  return 0;
}
