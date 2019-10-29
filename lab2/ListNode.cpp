// Filename: ListNode.cpp
//Julia Shea jts6mq
//9/12/2019

#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

//default constructor, initialize the value to 0 and the pointers to null
ListNode::ListNode(){
  value=0;
  next=nullptr;
  previous=nullptr;
}
