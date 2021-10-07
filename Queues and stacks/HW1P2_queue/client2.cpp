//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Kunal Vilas Banekar
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: To generate strings with A, B, C
//Algorithm: store A, B, C in the queue. Remove the first element print it and add with the three strings and push it back in the queue. Same for B and C.
int main()

{ // ** "A", "B", "C" in the queue
  // ** while loop -- indefinitely
  queue possiblestrings;
  string emptyvar;
  //Storing A, B & C in the queue
  possiblestrings.add("A");
  possiblestrings.add("B");
  possiblestrings.add("C");

  //the three strings that will be added
  string one = "A";
  string two = "B";
  string three = "C";



  while(true)
    {
      try
	{ 
	    
	  //remove an elemnet
	  possiblestrings.remove(emptyvar);
	    
	  //display the element
	  cout<<emptyvar<<endl;

	  //add three strings
	  string phrase =  emptyvar + one;
	  possiblestrings.add(phrase);
	  
	  phrase = emptyvar + two;
	  possiblestrings.add(phrase);
	  
	  phrase = emptyvar + three;
	  possiblestrings.add(phrase);


	}
      //catching two errors, overflow and underflow
      catch (queue::Overflow)
	{
	  cout<<"Too many Operands";
	  exit(1);
	}
      
      catch (queue::Underflow)
	{
	  cout<<"Too few Operands";
	  exit(1);
	}
	
    }// end of loop

}

