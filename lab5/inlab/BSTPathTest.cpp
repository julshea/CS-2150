//Filename: BSTPathTest.cpp
//Julia Shea - jts6mq - 12:30 lab section - lab5 - 10/15/19
#include "BinarySearchTree.h"
#include "BinaryNode.h"

#include <iostream>
using namespace std;

int main() {
  BinarySearchTree bst;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      bst.insert(word);
    } else if (instr == "R") {
      bst.remove(word);
    } else if (instr == "L") {
      cout << "BST path: " << bst.pathTo(word) << endl;
    }
  }
  cout << "BST numNodes: " << bst.numNodes() << endl;
}
