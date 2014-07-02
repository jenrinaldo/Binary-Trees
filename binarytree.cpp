#include "binarytree.h"
#include <stddef.h>
#include <iostream>
#include <math.h>

// constructor
bTreeClass::bTreeClass() {
  for (int i = 0; i < ARRAY_MAX; i++) {
    arr[i] = -1;
  }
  numElements = 0;
  height = 0;
}

// destructor
bTreeClass::~bTreeClass() {
}

bool bTreeClass::insert(int element, bool& success) {
  if (numElements == ARRAY_MAX) {
    cout << "Tree is full." << endl;
    return false;
  }
  else {
    arr[numElements] = element;
    numElements++;
    if (numElements > pow(2, height) -1) {
      height++;
    }
    return true;
  }
}

bool bTreeClass::deleteNode(int& n) {
  n = arr[numElements-1];
  if (numElements == 0) {
    cout << "Tree is empty." << endl;
    return false;
  }
  else {
    arr[numElements] = -1;
    numElements--;
    if (numElements <= pow(2, height-1) - 1) {
      height--;
    }
    return true;
  }
}

void bTreeClass::displayLevel(int lvl) {
  int x = pow(2, lvl-1) - 1;
  int count = 0;

  while (true) {
    if (numElements == 0 || arr[x] == -1 || count == pow(2, lvl-1)) {
      break;
    }
    cout << arr[x] << " ";
    x++;
    count++;
  }
}

bool bTreeClass::isEmpty() const {
  if (numElements == 0) {
    return true;
  }
  else {
    return false;
  }
}

void bTreeClass::inorder() {
  inorder(0);
  cout << endl;
}
void bTreeClass::inorder(int x) {
  if (numElements == 0) {
    cout << "Tree is empty." << endl;
  }
  else {
    if (arr[x] != -1) {
      // left
      if (arr[2*x+1] != -1) {
	inorder(2*x+1);
      }
      // root
      cout << arr[x] << " ";
      // right
      if (arr[2*x+2] != -1) {
	inorder(2*x+2);
      }
    }
  }
}

void bTreeClass::preorder() {
  preorder(0);
  cout << endl;
}
void bTreeClass::preorder(int x) {
if (numElements == 0) {
    cout << "Tree is empty." << endl;
  }
  else {
    if (arr[x] != -1) {
      // root
      cout << arr[x] << " ";
      // left
      if (arr[2*x+1] != -1) {
	inorder(2*x+1);
      }
      // right
      if (arr[2*x+2] != -1) {
	inorder(2*x+2);
      }
    }
  }
}

void bTreeClass::postorder() {
  postorder(0);
  cout << endl;
}
void bTreeClass::postorder(int x) {
if (numElements == 0) {
    cout << "Tree is empty." << endl;
  }
  else {
    if (arr[x] != -1) {
      // left
      if (arr[2*x+1] != -1) {
	inorder(2*x+1);
      }
      // right
      if (arr[2*x+2] != -1) {
	inorder(2*x+2);
      }
      // root
      cout << arr[x] << " ";
    }
  }
}

int bTreeClass::HeightOfTree() const {
  return height;
}

int bTreeClass::NumberOfElements() const {
  return numElements;    
}
