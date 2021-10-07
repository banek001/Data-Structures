// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Kunal Vilas Banekar
// File type:  Client file  (tester)
// ================================================

//**

#include <iostream>
#include "dgraph.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{// **





  //  0.Declare table object
  dgraph ll; 

  slist sl;

  //  1.fillTable()
  ll.fillTable(); 

  // 2.displayGraph()
  ll.displayGraph();
 

  int exito = 0;


  while(exito != 1){    // while (the user does not want to stop)


    char vertex = 'A';
    //  a.the user will specify which vertex     


    cout<<"Enter 1 to stop or press other integer to continue!"<<endl;
    cin>>exito;


    if(exito != 1){ // if user enters 1 exit
    cout<<"Enter the vertex name: ";
    cin>>vertex;
    cout<<endl; 

    //    char y;
    // int z;
    try{
    // b.findOutDegree of the vertex and display the result
       ll.findOutDegree(vertex);

      //      cout<<"The value of y: "<<y<<endl;
      // b.findAdjacency of the vertex and display the result (see Hint)
       ll.findAdjacency(vertex);
      //      cout<<"The value of z: "<<ll<<endl;
    // c.catch exception to display error mesg but do not exit
    }catch(dgraph::BadVertex){cerr<<" ERROR: No such Vertex! "<<endl;



    }
    }
  }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
