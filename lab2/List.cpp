//filename: List.cpp
//Julia Shea, jts6mq
//9/12/19
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

//default constructor, initialize to an empty list
List::List(){
  head=new ListNode();
  tail=new ListNode();
  count = 0;
  tail->previous=head;
  head->next=tail;

  tail->next = nullptr; //dummy tail node
  head->previous = nullptr; //dummy head node
  
}

//copy constructor
List::List(const List& source) {
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


//destructor: iterate through the list and delete each element
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}
	   
//overloaded equals method 
List& List::operator=(const List& source) {
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


//returns true if the list is empty, returns false if not
bool List::isEmpty() const {
  if(count == 0 && head->next == NULL && tail->previous == NULL){
    return true;
  }
    return false;
}

//iterates through the list and deallocates space/deletes the node 
void List:: makeEmpty(){
  ListItr *itr = new ListItr(head->next);
  while(itr->isPastEnd() != true){
      itr->moveForward();
      delete itr->current;
    }
  //set the head to be pointing to the tail visa versa
  head->next = tail; 
  tail->next = head;
  count = 0; //reset the count to 0

}
//returns an iterator that points to the ListNode in the first position
ListItr List::first(){
  return ListItr(head->next);
}

//returns an iterator that points to the ListNode in the last position
ListItr List::last(){
  return ListItr(tail->previous);
}


//inserts x after the current iterator position
void List::insertAfter(int x, ListItr position){
  ListNode *node = new ListNode();
  node->value = x;
  position.current->next->previous = node; 
  node->next = position.current->next; //sets the node's field "next" to the iterator's next node 
  node->previous = position.current; //sets the node's field "previous" to the iterator's current position
  position.current->next = node; //places the node after the current position of the iterator
  count++; //increment the total node count by 1 
}

//inserts x before the current iterator position
void List::insertBefore(int x, ListItr position){
  ListNode *node = new ListNode();
  node->value = x;
  position.current->previous->next = node; 
  node->previous = position.current->previous; //sets the node's field "previous" to the iterator's prev.
  node->next = position.current; //sets the node's field "next" to the iterator's current position
  position.current->previous = node; //places the node before the current position of the iterator
  count++; //increment the total node count by 1 
}

//inserts x right before the tail node
void List::insertAtTail(int x){
  ListNode *node = new ListNode();

  //set the node's value, next, and previous
  node->value = x;
  node->next = tail;
  node->previous = tail->previous;
 

  //set the dummy tail's next and previous
  tail->previous->next = node;
  tail->previous = node;
  
  //increment the count by 1
  count++;
}

//removes the first occurence of x
void List::remove(int x){
  ListItr *itr = new ListItr(head);
  while(itr->current->value != x){
      itr->moveForward();
  }
  itr->current->next->previous = itr->current->previous; 
  itr->current->previous->next = itr->current->next;
  delete itr->current;
  count--;
}

//returns an iterator that points to the first occurence of x
ListItr List::find(int x){
  ListItr *itr = new ListItr(head);
  while (itr->isPastEnd() != true){
    if(itr->current->value == x){
      return *itr;
    }
    itr->current = itr->current->next;
  }
  return tail->next;
}

//returns the number of elements in the list (does not include the dummy head/tail)
int List::size() const {
  return count;
}



