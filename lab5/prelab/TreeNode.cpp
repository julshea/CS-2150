// Julia Shea (jts6mq) - 12:30 lab section - 10/12
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

//Default Constructor -left and right are NULL, value '?'
TreeNode::TreeNode() {
    value="?";
    left=NULL;
    right=NULL;
}

//Constructor - sets value to val
TreeNode::TreeNode(const string & val) {
    value=val;
    left=NULL;
    right=NULL;
}
