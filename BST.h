#include "Treenode.h"

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();

  void insert_node(int);
  void print(int = 0);
    /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/

};

// Additional functions
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr,int); //The real lab
  void kill(TreeNodePtr);

void BST::insert_node(int value) {
  bool inserted = false;
  TreeNodePtr new_node, t;
  new_node = new TreeNode(value);
  if (new_node) {
   
    if (size == 0) {rootPtr = new_node; size = 1;}// Check for the new node using size, not robust but works better than checking for move_right and move_left
    
    else
      {
        t = rootPtr;
        while (!inserted)
        {
          // Smaller Case
          if (value <= t->get_value() && t->move_left()  != NULL) t = t -> move_left();
          if (value <= t->get_value() && t->move_left()  == NULL){ t->set_left(new_node); inserted = true; size++;};
          //Bigger Case
          if (value  >  t->get_value()&& t->move_right() != NULL) t = t -> move_right(); // Not the end of branch
          if (value  >  t->get_value()&& t->move_right() == NULL){ t->set_right(new_node); inserted = true; size++;}; // End of branch, make leaf
        }
      }
  }
}


void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
      default:
    printTree(rootPtr,0);
    cout << endl;
  }
}


BST::BST() {
  rootPtr=NULL;
  size=0;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
    
}

void inOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function
  //printTree(rootPtr,0);

void printTree(TreeNodePtr treePtr,int l) {
      if (treePtr) {
       printTree(treePtr->move_right(),l+1); // Recursion to the right
       cout << setw(3*l) << treePtr->get_value() << endl; // print the value
       printTree(treePtr->move_left(),l+1); // Recursion to the left
  }
} // end function


void postOrder(TreeNodePtr treePtr) {
  // TreeNodePtr treePtr=rootPtr;
 if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    inOrder(treePtr->move_right()); // Recursion to the right
    cout << setw(3) << treePtr->get_value();
  }                                          // end if
} // end function

void kill(TreeNodePtr treePtr) {
  // TreeNodePtr 
  if(treePtr){
       //delete everything
        
    }                                          // end if
} // end function

void preOrder(TreeNodePtr treePtr) {
  if(treePtr){
    inOrder(treePtr->move_left()); // Recursion to the left
    inOrder(treePtr->move_right()); // Recursion to the right
    cout << setw(3) << treePtr->get_value();
 
  }                                          // end if
} // end function

