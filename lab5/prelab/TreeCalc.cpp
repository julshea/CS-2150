// Julia Shea (jts6mq) - 12:30 lab section - 10/12
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

//Constructor
TreeCalc::TreeCalc(){
  stack <TreeNode*> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  mystack.empty();
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  cleanTree(ptr->left);
  cleanTree(ptr->right);
  delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode *node = new TreeNode(val); //creates a new TreeNode to hold value
  //first, check to see if the value is an operand (can be positive or negative)
  if((isdigit(val[0])) || (val[0] == '-' && isdigit(val[1]))){
    mystack.push(node); //pointers to numerical values are pushed onto the stack
  }
  
  //handle the cases in which val is an operator
  else if ((val == "-") || (val == "+") || (val == "/") || (val == "*")){
    //pointers to the top 2 values are assigned to be right and left children of the operator
    //then, they're each popped from the stack
    TreeNode *right = mystack.top(); 
    mystack.pop(); 
    TreeNode *left = mystack.top();
    mystack.pop();
    //a new tree is formed and a pointer to the operand (the root) is pushed onto the stack
    node->right = right;
    node->left = left;
    mystack.push(node);
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if(ptr == NULL){
    cout << "This expression tree is empty!" << endl;
  }
      //prints the node
    else if(ptr != NULL){
      cout << ptr->value << " ";
    }
    //prints the left subtree
    if(ptr->left != NULL){
     printPrefix(ptr->left);
    }
    //prints the right subtree
    if(ptr->right != NULL){
     printPrefix(ptr->right);   
    }
}
//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  //print tree in infix format with appropriate parentheses
  string val = ptr->value;
  if(ptr==NULL){
    cout << "This expression tree is empty!" << endl;
  }

  //prints the left subtree
  if(ptr->left != NULL){
    cout << "(";
    printInfix(ptr->left);
  }

  //prints the node
  cout << ptr->value;
  
  //prints the right subtree
  if(ptr->right != NULL){
    printInfix(ptr->right);
      cout << ")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
  if(ptr == NULL){
    cout << "This expression tree is empty!" << endl;
  }
   //prints the left subtree
    if(ptr->left != NULL){
     printPrefix(ptr->left);
    }
    //prints the right subtree
    if(ptr->right != NULL){
     printPrefix(ptr->right);   
    }
  //prints the node
  else if(ptr != NULL){
    cout << ptr->value << " ";
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
	printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  if(ptr->value[0] == '-'){
    return (calculate(ptr->left)-calculate(ptr->right));
  }
  else if(ptr->value[0] == '+'){
    return (calculate(ptr->left)+calculate(ptr->right));
  }
  else if(ptr->value[0] == '/'){
    return (calculate(ptr->left)/calculate(ptr->right));
  }
  else if(ptr->value[0] == '*'){
    return (calculate(ptr->left)*calculate(ptr->right));
  }

  return atoi(ptr->value.c_str());
 
}


//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    i = calculate(mystack.top());
    return i;
}
