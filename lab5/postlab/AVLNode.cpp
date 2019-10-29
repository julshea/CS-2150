//Filename: AVLNode.cpp
//Julia Shea - jts6mq - 12:30 lab section - lab5 - 10/17/19

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
  value = "?";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::~AVLNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;

}
