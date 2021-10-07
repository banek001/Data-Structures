//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Kunal Vilas Banekar
// File Type: Implementation file
//========================================================

#include "dgraph.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

dgraph::dgraph()
{
  for(int i = 0; i<SIZE; i++){
    Gtable[i].vertexName = ' '; // initialize vertexName (blank) and
    Gtable[i].visit = 0;// visit numbers (0)   
  }
  countUsed = 0; // initialize countUsed to be 0

}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
  //It is called automatically
}

void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help
  char addx;

  while(fin>> Gtable[countUsed].vertexName){// IF I CAN READ THE NAME

    fin>> Gtable[countUsed].outDegree;
    for(int i = 0; i< Gtable[countUsed].outDegree; i++){
      fin>>addx;
   

      ///////

      
      ( Gtable[countUsed].adjacentOnes).addRear(addx); // this is a slist function from HW3


       //      cout<<"the value of addx: "<<addx<<endl;

      //////
    }
    countUsed++;
  }
  fin.close();






}
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows and include the number of edges at the top 

 int degtot = 0;
 for(int i = 0; i<countUsed; i++){// untill countused so that unused slots will not print
   
   degtot = degtot + Gtable[i].outDegree; //adding the degree


  }
  cout<<"The number of edges are: "<<degtot<<endl;


  cout<<"VName Out Visit Adjacent"<<endl;
  cout<<"------------------------"<<endl;

  for(int i = 0; i<countUsed; i++){// untill countused so that unused slots will not print



    cout<< Gtable[i].vertexName; //printing the vertex name
    cout<<"      "<< Gtable[i].outDegree<<"    "; //printing outdegree
    cout<< Gtable[i].visit<<"      ";
    (Gtable[i].adjacentOnes).displayAll();//printing adjacent

  }

}

int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop

    int a;
    a = int(V);//converting into integer
   // cout<<"The value of a: "<<a<<endl;
   //   V = a;
   //   V = char(a);

    a = a - 65;
   // cout<<"The value of new a: "<<a<<endl;
   // cout<<"the value of V in out: " <<V<<endl;
    if(Gtable[a].vertexName == V){//if vertex name found 

      int deg;
      deg =  Gtable[a].outDegree;
      //      cout<<deg<<" edges comes out to: ";
      
      return Gtable[a].outDegree;
    }
    else{ throw BadVertex();}//throw error
    

}

slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop


  //  cout<<"the value of V in adj: " <<V<<endl;
  
  int a;
  a =  int(V);
  // V = char(a);
  a = a - 65;  
  if(Gtable[a].vertexName == V){//if vertex name found
    slist adj;
    //    adj =  Gtable[a].adjacentOnes;
    (Gtable[a].adjacentOnes).displayAll();
    //    cout<<adj<<endl;
    return Gtable[a].adjacentOnes;
  }else{throw BadVertex();}//throw error


}



void dgraph::visit(int N, char V)
{

  int a;
  a = int(V);
  a = a - 65;


  if(V == Gtable[a].vertexName){

    Gtable[a].visit = N;

  }


}

bool dgraph::isMarked(char M)
{
  
  int a;
  a = int(M);
  a = a - 65;


  if(Gtable[a].vertexName == M){

    if(Gtable[a].visit != 0){

      return true;
    }else{ return false;}

  }

}
