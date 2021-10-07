//CS311 Yoshii 
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: KUNAL VILAS BANEKAR
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To evaluate postfix expressions
//Algorithm: taking a string from the user. reading every element in the string and coverting into inetgers and doing the operations as asked.catching errors if any. after doing the operations displaying the top element and whatever is left in the stack
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 


	 if(item == '0' || item == '1' || item == '2'||item == '3' || item == '4' || item == '5'||item == '6' || item == '7' || item == '8'||item == '9')
	   //if the string contains number covert into integers
	   {

	     postfixstack.push(int(item) - 48);
	   }
	 else if(item == '+' || item == '-' || item == '*')//if the string contains operations 
	   {
	     postfixstack.pop(box2);//popping in box2
	     postfixstack.pop(box1);//popping in box1

	     switch(item)
	       {
	       case '+': postfixstack.push(box1 + box2);//does addition of two integers
		 break;

	       case '-': postfixstack.push(box1 - box2);//does substraction of two integers
		 break;

	       case '*': postfixstack.push(box1 * box2);////does multiplication of two integers
		 break;

	       }
	   }
	 else
	   {
	     throw "Invalid Input";//throwing a string
	   }
       }
	 
	 
        // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
     catch (stack::Overflow)//catching overflow 
       {
	 cout<<"ERROR: Too many Operands";
	 exit(1);
       }
     
     catch (stack::Underflow)//catching underflow
       {
	 cout<<"ERROR: Too Few Operands";
	 exit(1);
       }
     
     catch (char const* errormsg ) // for invalid item case
       {
	 cout<<"ERROR: Invalid Input";
	 exit(1);
       }
     
      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  cout<<"------------------------------"<<endl;
  int looked;
  postfixstack.topElem(looked);//looking for top element
  cout<<"The Top Element is: "<<looked<<endl;//printing top element
  postfixstack.pop(looked);//popping out the looked element

 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.

  postfixstack.displayAll();//displaying whatever is left in the stack

  return 0;
}// end of the program
