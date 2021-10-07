
//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Kunal Vilas Banekar
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{// cout << "... in llist constructor..." << endl; 
  Front = NULL;
  Rear = NULL;
  Count = 0;

}

llist::~llist()
{// cout << ".... in llist destructor..." << endl; 
 
  el_t A;

  while(!isEmpty()){

    deleteFront(A);
   

}

}

//PURPOSE:to check if the list is empty
//PARAMETER:no parameter
bool llist::isEmpty() { 
  if(Front == NULL && Rear == NULL && Count == 0){
    return true;
  }

  else{ return false;}
 

} // be sure to check all 3 data members

//PURPOSE:displaying the contents of the linked list
//PARAMETER:no parameter
void llist::displayAll() {   // be sure to display horizontally in [  ] with
// blanks between elements
  
  if(!isEmpty()){
    Node *P;
    P = Front;
    cout<<"[ ";
    while(P != NULL){// while front is not null
      cout<<P->Elem<<" ";
      P = P->Next;
  }
  cout<<"]"<<endl;
  }else{cout<<"[empty]"<<endl;}
}



//PURPOSE:add from rease
//PARAMETER:NewNum
void llist::addRear(el_t NewNum) { 
  if(isEmpty()){// special case: if its a very first node

    addFront(NewNum);

  }else{//regular case: if it has a node addd a new node at the rear
    Rear->Next = new Node;//Rear now points to a new node
// adds a new node at the very end
    Rear = Rear->Next; //rear points to it now
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  }

} // comment the 2 cases

//PURPOSE:add from front
//PARAMETER:NewNum
void llist::addFront(el_t NewNum) { 
  if(isEmpty()){//special case

    Front = new Node; // Front now points to a new noed
    //    Front->Next = Rear;
    Front->Elem = NewNum;// elem gets the new number
    
    Rear = Front;
    Rear->Next = NULL;
    Count++;

  }else{//regular case
    
    Node *reg;
    reg = new Node;
    reg->Elem = NewNum;
    reg->Next = Front;
    Front = reg;
    //Front->Elem = NewNum;
    Count++;
  }


} // comment the 2 cases

//PURPOSE:delete from front
//PARAMETER:OldNum
void llist::deleteFront(el_t& OldNum) { 

  if(isEmpty()){ throw Underflow();}//error case


  else if(Front->Next == NULL){

    OldNum = Front->Elem;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
 }
  else{//regular case

   OldNum = Front->Elem;
    Node *Second;
    Second = Front-> Next;
    delete Front;
    Front = Second;
    Count--;

   


    
  }



} // comment the 3 cases

//PURPOSE:Deleting from the Rear
//PARAMETER:OldNum
void llist::deleteRear(el_t& OldNum){

  if(isEmpty()){ throw Underflow();}// if empty throw underflow
   
  else{


    OldNum = Rear->Elem;
   
    Node *P;
    P = Front;
   
    if(P->Next == NULL){// if p's next is Null, delete P
      delete P;
      Front = NULL;
      Rear = NULL;
      Count = 0;


      return;
    }
 
      
 
      

    while(P->Next != Rear){// p's next is not equal to rear 
      P = P->Next;
    }


    delete Rear;

    Rear = P;
    Count--;

    Rear->Next = NULL;
    
    if(isEmpty()){//special case if is going to make empty 

      Front = NULL;
      Rear = NULL;
      Count = 0;
    }

  }



} // comment the 3 cases


// harder ones follow 

// Utility Function to move a local pointer to the Jth node

void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node

temp = Front;
  for ( int K = 1; K <= J-1; K++ ){ temp = temp->Next;}

}






//PURPOSE:deleting element at the Ith position
//PARAMETER:I, OldNum
void llist::deleteIth(int I, el_t& OldNum) {



  if( I > Count || I < 1 ){


    throw OutOfRange();} // Error Case 

  else if(I == 1){ // special case: if I is the first elem
    deleteFront(OldNum);
  }

  else if(I == Count){//special case: if I is the LAst elem
    deleteRear(OldNum);
  }


  else{
    int x = I-1;
    int y = I+1;

    Node *temp;
    Node *P;
    Node *Ith;

    moveTo(x, temp);
    moveTo(y, P);
    moveTo(I, Ith);

    OldNum = Ith->Elem;
    delete Ith;
    temp->Next = P;
    Count--;
  } 



 } // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:inserting elements at Ith position
//PARAMETER: I, newNum
void llist::insertIth(int I, el_t newNum) {
  if( I > Count+1 || I < 1 ){ throw OutOfRange();}

  else if(I == 1){// if I is the first elem
    addFront(newNum);
  }

  else if(I == Count+1){//special case:if I is count+1
    addRear(newNum);
  }


  else{
    Node *P;
    P = Front;

    int counter = 1;
    Node *temp;
    Node *newNode = new Node;// creating new node for saving new num

    while(counter != I){
      temp = P;
      P = P->Next;
    

      counter++;
    }

    newNode->Elem = newNum; //storing newNum
    //temp =  P->Next;
    temp->Next= newNode;//pointing previous node to new node
    newNode->Next = P;// setting p's next




    Count++;
  }
    

 } // use moveTo to move local pointers. Be sure to comment to which node you are moving them.




//PURPOSE:copy constructor for pass by value
//PARAMETER:Original
llist::llist(const llist& Original) {



  Front = NULL;
  Rear = NULL;
  Count = 0;

  Node *P = new Node;
  P = Original.Front;
  while(P != NULL){
    this->addRear(P->Elem);
    P = P->Next;
  }






 } // use my code





//PURPOSE:Overload
//PARAMETER:OtherOne

llist& llist::operator=(const llist& OtherOne) { 


  el_t x;

  if(&OtherOne != this){
    while(!this->isEmpty())
      this->deleteRear(x);

    Node *P;
    P = OtherOne.Front;

    while(P!=NULL){
      this->addRear(P->Elem);
      P = P->Next;
    }
  }
  return *this;





} // use my code


