//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Kunal Vilas Banekar
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
 public:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  


  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //to check if llist is empty
  bool isEmpty();
    
  //to display all the contents of llist
  void displayAll();

  //to add at the front of llist
  void addFront(el_t);
    
  //to add at the rear of the llist
  void addRear(el_t);

  //to delete from the front
  void deleteFront(el_t&);
    
  //to delete from the rear
  void deleteRear(el_t&);
    
  //to delete an element from Ith position
  void deleteIth(int, el_t&);  // calls moveTo

  //to insert an element at the Ith node    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
