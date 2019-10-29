//Filename: BinarySearchTree.cpp
//Julia Shea - jts6mq - 12:30 lab section - lab5 - 10/15/19

#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {
  root = NULL;
  num_nodes = 0;

}

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  insert(root, x);
  num_nodes+=1; 
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); num_nodes-=1;}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  if (find(x)!=true){
    return "";
  }
  return root->pathTo(x);
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  return find(root, x);
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  return num_nodes;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}
//insert helper function
void BinarySearchTree::insert(BinaryNode *&n, const string &x){
  if (n == NULL){
    n = new BinaryNode();
    n->value = x;
  }
  else if (x < n->value) {
    insert(n->left, x);
  }
  else if (x > n->value) {
    insert(n->right, x);
  }
  else
    num_nodes --;
    return;
}

//find helper function
bool BinarySearchTree::find(BinaryNode* n, const string& x) const {
  if (n == NULL)
    return false;
  else if (x < n->value)
    return find(n->left, x);
  else if (x > n->value)
    return find(n->right, x);
  else if (x == n->value)
    return true;
  else
    return false;
}
void BinarySearchTree::printTree() { printTree(root, NULL, false); }
