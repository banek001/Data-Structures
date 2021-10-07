using namespace std;
#include <iostream>
#include <math.h>
int binarySearch(int L[], int x, int first, int last) ;
//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Kunal Vilas Banekar
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
//This returns the slot number in which x was found
//or -1
int binarySearch(int L[], int x, int first, int last) 
{
  //** be sure to check for first == last to
  //   end the recursion 

  if(first <= last){  

    int middle = floor ((first + (last - first)/2)); //getting the middle of the array

    if(first < last)
      cout << "comparing against an element in slot " << middle << endl;         

    if(x == L[middle])   {  
      return middle; // if the element is in the middle
    }

    if (x < L[middle]){
      last = middle -1;// if the element is less than the midle
      return binarySearch(L, x, first, last);//updating the variables
    }

    else {
      first = middle +1;//if the element is greater tha the middle
      return binarySearch(L, x, first, last);//updating the variables
    }

  }
  
  else   return -1;// returning -1 if the lement is not in the array
}


int main()
{ int A[10];
  int e;  // to look for this
  int myfirst = 0;
  int mylast = 9;
  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A

  int respos = binarySearch(A, e, myfirst, mylast);// storing the information of the found variable 

  if (respos == -1) cout << "Element not found" << endl; //if element not found
  else cout << "Found it in position " << respos+1 << endl;// adding 1 to adjust slot as position

}
