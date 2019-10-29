//filename: stack.cpp
//jts6mq - Julia Shea - lab3 - 9/18

#include "stack.h"
#include "stackNode.h"
#include <iostream>
using namespace std;

//default stack constructor, initialize fields to null
Stack::Stack(): head(new stackNode){
  head->next=NULL;
}

//destructor
Stack::~Stack(){
  while(!empty()){
    pop();}
}

//returns true if there are no stackNodes in the stack
bool Stack::empty() const{
 if(head->next == NULL){
    return true;
  }
     return false;
}

//adds a new int element to the top of the stack
void Stack::push(int x){
  stackNode *node=new stackNode();
  node->value=x;
  node->next=head->next;
  head->next=node;
}

//removes the top element of the stack, but does not return it
void Stack::pop(){
  stackNode *node=head->next;
  delete head;
  head=node;
  
  
}

//returns the top element of the stack, but does not remove it
int Stack::top() const{
  return head->next->value;
}
