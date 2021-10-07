// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** Do not delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: **
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  // ** add the job j at the rear (and update count)
  if(count<MAX){
  Q[count] = j;
  count++;
  // **   if possible else display error message. 


  trickleup(); // moves the job to the right place
  }else{cout<<"Cannot add: '"<<j<<"', queue is full"<<endl;}
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for(int i = 0; i<count; i++){
    cout<<Q[i];
    cout<<" ";
  }

} 


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  // ** swap the values in these locations in Q


  int temp = Q[loc1];
  Q[loc1] = Q[loc2];
  Q[loc2] = temp;

  // int temp = loc1;
  // loc1 = loc2;
  //  loc2 = temp;
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  // ** While x is > 0
  
  //    compare Q[x] with the parent (*)
  int P;



  while(x>0){    
    int temp = Q[x];
    P = getParent(x);

    //    x = getSmallerchild(x);
    
    //    if(Q[P] > Q[x]){
    if(Q[P] > Q[x]){
      //    while(Q[P] > Q[x]){
      swap(x,P);  
    x = P;
    // }//else{x = 0;}
   
    //    if(Q[P] > Q[x]){x = 0;}
    }else{x = 0;}
    //    and if the parent is bigger swap & update x 
    //    to be the parent . Otherwise stop the loop.
  }
  
  //    P = getParent(x);
    // (*) Call getParent to get the location of the parent
  //            based on the child's location.

}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  // ** return the parent location based on the child loc
  int P;
  if(even(childloc)){
    P = ((childloc-2)/2);
  }else{    P = ((childloc-1)/2);}

  return P;

}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  // ** Start X at 0 (the root)
  // Q[X] = Q[0];
  X = 0; 
  //    while X is within the array:
 
  int par = getParent(count);
  while(X < par){
  //  while(X < 6){//6  @@@@
  




    //       Find the location of the smaller child
  //         (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent,
  //          swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.

    //    cout<<"inside rehipify loop "<<endl;

    int Small =   getSmallerchild(X); 
    // X = getParent(Small);

  // if(Small<par){
    if(Q[Small] <= Q[X]){

    //    if(Small =! X){// < Q[X]){
 //    swap(Q[Small], Q[par]);
   //  while(Small < par){
   // while(Q[Small] < Q[X]){
      //  cout<<"Value of Small: "<<Small<<endl;
      // cout<<"Value of Q Small: "<<Q[Small]<<endl;
      
      //cout<<"Value of X: "<<X<<endl;
      //cout<<"Value of Q X: "<<Q[X]<<endl;
      swap(X, Small);

      int temp = Small;
      Small = X;
      X = temp;

      //cout<<"Value of A Small: "<<Small<<endl;
      //cout<<"Value of Q Small: "<<Q[Small]<<endl;
      //cout<<"Value of A X: "<<X<<endl;
      //cout<<"Value of Q X: "<<Q[X]<<endl;








      //      Small = par;    
      //          Small = Q[0];  
      //     Small = X;
      //	    Q[0] = Small;      
      //      X = Small;
      //      Small = X;




      // }
 }else{
   //   cout<<"Value of X"<<X<<endl; 
   X = 51;}


  }

  //      trickleup();    


}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
// ** return the location of the smaller child 
//    Be careful because one or both of them may be
//    beyond count-1.  Check boundaries before you 
//    compare Q contents!!!!

//  cout<<"Inside Child"<<endl;
  //  cout<<"Count: "<<count<<endl;
  int S;
  int Left = (2*i + 1);
  int Right = (2*i + 2);

  if((Left < count-1) && (Q[Left] < Q[Right])){
    S = Left;
    //  cout<<"Left: "<<S<<endl;
  }


   else if((Right < count-1) && (Q[Right] < Q[Left])){
  //  else{
    S = Right;
    //  cout<<"Right: "<<S<<endl;
  }
   else{ S = Q[count-1];}
  return S;
}



