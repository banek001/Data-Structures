#include<iostream>
using namespace std;
int partition(int pivot, int a[], int f, int r);
// You may not change my code in any manner.  0 pts if you do!!!!!!
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Kunal Vilas Banekar
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left
  int right = r; // pointer from the right 

  while (left <= right)
    {
      // loop for finding out of place pairs and swap them
      // ** until the left and right cross
      if(a[left] < pivot){  //    if left OK, move left
	left++;//incrementing left to move the pointer towards right
      }
      else if(a[right] > pivot){  //    if right OK, move right
	right--;//decrementing right to move the pointer towards left
      }
      

      
      //    if both are bad, swap
      else if(left == right){// if pointers are equal to each other
	swap(a[left], a[right]);//swap
	left++;
	right--;
	
      }
      else if(a[left] > a[right]){//if the value at the left pointer is greater than the value at the right pointer
	swap (a[left], a[right]);//swap
	left++;
	right--;
      }
      
    }//end of while
  
  return left;// returning the value 
  // return the partition point where
  
  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case
  
  return right;// returning the value 
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
