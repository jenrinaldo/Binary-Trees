// assign7.cpp
// Mark Hunsinger
// 4/14/13
// Binary Trees - Array Implementation
// This program creates and manipulates a binary tree.
// ----------
// Call intro
// Prompt user for menu item and complete action.
// Loop until user exits.
// ----------
// I have tested my program and it all seems to be functioning correctly.
// Tested valid/invalid menu options.
// Tested valid/invalid input items.

#include <cassert>
#include <iostream>
#include "binarytree.h"
#include <math.h>

void intro();
void menu();

int main() {
  bTreeClass bTree;
  bool success;
  int myChoice;
  bool getmeout = false;
  int n = 0;
  
  intro();
  
  while (!getmeout) {
    for ( ; ; ) {
      menu();
      cin >> myChoice;
      cout << endl;
      cout << "You entered: " << myChoice << endl;
      
      if (cin.good() && myChoice > 0 && myChoice < 11) {
	break;
      }
      
      cout << "You entered invalid input. Please enter a menu item." << endl;
      cin.clear();
      cin.ignore(120,'\n');
    }
      
    int theItem = 0;

      switch (myChoice) {
	
      case 1:  // add element
	for ( ; ; ) {
	  cout << "Enter an integer to add: ";
	  cin >> theItem;
	  cout << endl;
	  cout << "You entered: " << theItem << endl;
	  if (cin.good() && theItem >= 0) {
	    break;
	  }
	  cout << "You entered invalid input. Please enter a positive integer" << endl;
	  cin.clear();
	  cin.ignore(120,'\n');
	}
	
	bTree.insert(theItem, success);
	break;
      case 2:  // delete element
	if (bTree.deleteNode(n)) {
	  cout << n << " deleted from the tree" << endl;
	}
	else {
	  cout << "Delete unsuccessful" << endl;
	}
	break;
      case 3:  // display level of element
	for ( ; ; ) {
	  cout << "Enter level to display: ";
	  cin >> theItem;
	  cout << endl;
	  cout << "You entered: " << theItem << endl;
	  if (cin.good() && theItem <= bTree.HeightOfTree()) {
	    break;
	  }
	  cout << "You entered invalid input. Please enter a positive integer" << endl;
	  cin.clear();
	  cin.ignore(120,'\n');
	}
	bTree.displayLevel(theItem);
	cout << endl;
	break;
      case 4:  // inorder traversal
	bTree.inorder();
	break;
      case 5:  // preorder traversal
	bTree.preorder();
	break;
      case 6:  // postorder traversal
	bTree.postorder();
	break;
      case 7:  // print height
        cout << "height = " << bTree.HeightOfTree() << endl;
	break;
      case 8:  // print number of elements
	cout << "number of elements = " << bTree.NumberOfElements() << endl;
	break;
      case 9:  // display whether full or not
	if (bTree.NumberOfElements() == pow(2, bTree.HeightOfTree() - 1)) {
	  cout << "Tree is full." << endl;
	}
	else {
	  cout << "Tree is not full." << endl;
	}
	break;
      case 10: // exit
	cout << "Exiting. Goodbye!" << endl;
	getmeout = true;
	break;
      }
  }
  return 0;
}

void intro() {
  cout << "Written by: Mark Hunsinger" << endl;
  cout << "Binary Trees - Array Implementation" << endl;
  cout << "This program creates and manipulates a binary tree" << endl;
  cout << endl;
}

void menu() {
  cout << " 1. Add element." << endl;
  cout << " 2. Delete element." << endl;
  cout << " 3. Display level of an element." << endl;
  cout << " 4. Print tree (inorder traversal)" << endl;
  cout << " 5. Print tree (preorder traversal)" << endl;
  cout << " 6. Print tree (postorder traversal)" << endl;
  cout << " 7. Print height." << endl;
  cout << " 8. Print number of elements." << endl;
  cout << " 9. Display whether tree is full or not." << endl;
  cout << "10. Exit." << endl;
  cout << "----------" << endl;
  cout << "Please enter a menu item: ";
}
