using namespace std;
#include <iostream>
#include <vector>
void combine( vector<int> A, vector<int> B, vector<int> &R );
// Must use the algorithm that is in the notes! 

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Kunal Banekar
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int ia = 0;
  int ib = 0;
  int ir = 0;


  //** // be careful -- R comes in as an empty vector with no slots so you have to use push_back

  
  while(ia< A.size() && ib < B.size()){

    if(A[ia] < B[ib]){//checking if element in array A is less than array B 
      R.push_back(A[ia]); // storing element of A in R
      ia = ia + 1; //increment ia
    }
    
    else{// if not
      R.push_back(B[ib]);  // storing element of B in R
      ib = ib + 1; //increment ib
    }
    cout << "comparison" << endl;      
    ir = ir + 1; //increment ir

  }//end of loop
  
  while(ia < A.size()){//while the pointer is less than the size of array A
    R[ir] = A[ia];
    R.push_back(A[ia]);  // storing element of A in R
    ia = ia + 1; //increment ia
    ir = ir + 1; //increment ir

  }

  while(ib < B.size()){//while the pointer is less than the size of array B
    R[ir] = B[ib];
    R.push_back(B[ib]);  // storing element of B in R
    ib = ib + 1; //increment ib
    ir = ir + 1; //increment ir

  }
  
  
}//end of function




int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3

  combine(L1, L2, L3);// calling the combine function 
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
