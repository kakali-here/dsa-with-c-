#include<iostream>
#include "genBST.h"

using namespace std;

//A function for searching a binary search tree

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const {
 while (p != 0)
 if (el == p->el)
 return &p->el;
 else if (el < p->el)
 p = p->left;
 else p = p->right;
 return 0;
}

//A nonrecursive implementeteion of preorder tree traversal

template<class T>
void BST<T>::iterativePreorder() { 
 Stack<BSTNode<T>*> travStack;
 BSTNode<T> *p = root;
 if (p != 0) {
 travStack.push(p);
 while (!travStack.empty()) {
 p = travStack.pop();
 visit(p);
 if (p->right != 0)
 travStack.push(p->right);
 if (p->left != 0) // left child pushed after right
 travStack.push(p->left); // to be on the top of 
 } // the stack;
 }
}

//A nonrecursive implementation of postorder tree traversal

template<class T>
void BST<T>::iterativePostorder() { 
 Stack<BSTNode<T>*> travStack;
 BSTNode<T>* p = root, *q = root;
 while (p != 0) {
 for ( ; p->left != 0; p = p->left)
 travStack.push(p);
 while (p->right == 0 || p->right == q) {
 visit(p);
 q = p;
 if (travStack.empty())
 return;
 p = travStack.pop();
 }
 travStack.push(p);
 p = p->right;
 }
}

