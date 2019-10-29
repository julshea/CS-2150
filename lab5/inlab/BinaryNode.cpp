//Filename: BinaryNode.cpp
//Julia Shea - jts6mq - 12:30 lab section - lab5 - 10/15/19


#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
  value = "?";
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}

string BinaryNode::pathTo(const string& x) {
  if (x == this->value)
    return this->value;
  else if (x < this->value)
    return this->value + " " + this->left->pathTo(x);
  else if (x > this->value)
    return this->value + " " + this->right->pathTo(x);
  else
    return "";
}
