//Filename: ListItr.cpp
//jts6mq, 9/8

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

//default constructor
ListItr::ListItr(){
  current = NULL;
}

//constructor with parameter
ListItr::ListItr(ListNode *theNode){
  current = theNode;
}

//returns true if past the end position in the list, else false
bool ListItr::isPastEnd() const{
  if (this->current->next == NULL){
    return true;
  }
    return false;
}

//returns true if past the first position of the list, else false
bool ListItr::isPastBeginning() const{
  if (this->current->previous == NULL){
    return true; 
  }
    return false;
}

//advances the current pointer to the next position in the list
void ListItr::moveForward(){
  if (this->isPastEnd() != true){
   current = current->next; 
}
}
//moves the current pointer to the previous position in the list
void ListItr::moveBackward(){
  if (this->isPastBeginning() != true){
    current = current->previous;
}
}

//returns the value of the item in the current position of the list
int ListItr::retrieve() const{
  return current->value;
}


//prints list forward when direction is true, and backward when direction is false
void printList(List &source, bool direction){
  if (direction){
   ListItr *itr = new ListItr(source.first());
   while(itr->isPastEnd() != true){
     cout << itr->retrieve() << endl;
     itr->moveForward();
    } 
   }
  
  else{
    ListItr *itr = new ListItr(source.last());
    while(itr->isPastBeginning() != true){
      cout << itr->retrieve() << endl;
      itr->moveBackward();
    }
  }
}









