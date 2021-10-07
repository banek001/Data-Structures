//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Kunal Vilas Banekar
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include dgraph, slist and stack

#include "dgraph.h"
#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments. 

  dgraph ll;
  slist sl;
  stack sT;
  llist L;
  char V;
      int mark = 0;
//Display the graph before DFS begins
 ll.fillTable();
 ll.displayGraph();
//Push A onto the stack to start

 sT.push('A');
//While the stack is not empty do:
 while(!sT.isEmpty()){
//{

//Remove a vertex v from the stack.
     sT.pop(V);
//Display the vertex name. E.G. "removed B from the stack"
     cout<<"Removed "<<V<<" from the stack"<<endl;
//**if v is not marked yet (visit number is 0) then
     if(ll.isMarked(V) == false){
//mark it (visit it ** ) and inform the user E.G. "Visit B as 2"
       mark++;
      cout<<"Visit "<<V<<" is: "<<mark<<endl; 
      ll.visit(mark, V);

      //      mark;
//gets its adjacency list
//      try{
	//      ll.findAdjacency(V);



	cout<<"...pushing: ";
          sl  = ll.findAdjacency(V);
     
	  
	  char x;
	  int deg;

	  deg = ll.findOutDegree(V);


	  for(int i = 0; i<deg ;i++){
	  
	    //	  cout <<"'Inside for loop:"<<endl;
	  // sl.displayAll();	  

	  sl.deleteRear(x);
	  // cout<<"The removed: "<<x<<endl;

	  sT.push(x);
	  }
	  //	  sl.displayAll();	  






	  // sT.push(sl);
	  //      }catch(dgraph::BadVertex){cerr<<"ERROR: Deadend reached - backup"<<endl;}
// if no adjacent ones inform the user E.G. " Deadend reahed- backup"
	  if(deg == 0){cerr<<"ERROR: Deadend reached - backup"<<endl;}
// else put adjacent ones on the stack (delete from the rear and push) informing the user
     }else{cout<<V<<" is already marked - backup"<<endl;}
//** else inform the user E.G. "B had been visited already - backup."
      
//Diplay the stack cleary labeling it as the current stack
     sT.displayAll();
//}
   }
//Display the graph nicely with visit numbers forall vertices
   ll.displayGraph();




}
