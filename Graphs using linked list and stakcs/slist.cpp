// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Kunal Vilas Banekar
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{// cout << "slist constructor:" << endl;}
}

// positions always start at 1

int slist::search(el_t key){
  Node *P = Front;
  int pos = 1;


  //  if(!isEmpty()){
  //while(P->Elem != key){

  //	cout<<"Hey! You are in Search"<<endl;
    
  while(P != NULL){// search throughout the list
    if(P->Elem == key){//if elem found

	cout<<"you are inside If"<<endl;
	cout<<"Element was found in: "<<pos<<endl;
	return pos;
    }
    else{// if not

	pos++;
	P = P->Next;//go to next 
	cout<<"you are inside else and the pos is: "<<pos<<endl;
      }
      
  } 
  //}else{
  cout<<"Element was not found!"<<endl;
  //return 0;
  //}



}

// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos){

  if(pos>Count || pos==0){throw OutOfRange();}//if pos is greater than count

  else{
    Node *P;
    P = Front;
    for(int i = 1; i < pos; i++){ //go untill that position
      P = P->Next;//go to next
    }
    P->Elem = element;// put that elem in that position

  }



}

bool slist::operator==(const slist& OtherOne)
{

  /*  Rear = NULL;
  Front =NULL;
  Count = 0;
  */
  // if not the same length, return false
  //  cout<<"this count: "<<this->Count<<" Other count "<< OtherOne.Count <<endl;
  if(this->Count != OtherOne.Count){return false;}//if count is not equal return false


  // if the same lengths check each node to see if the elements are the same
  else{// check each elem
  
    Node *Q;
    Q = this->Front;//store value of Front in Q 
    Node *P;
    P = OtherOne.Front;//store value of Front in P 
    //        cout<<"Inside else"<<endl;
	//cout<<"This is P: "<<P<<endl;;
	//cout<<"Value of this: "<<this->Front->Elem<<endl;    
    for(int i = 0; i<Count; i++){// for count times
      //cout<<"Value of i"<<i<<endl;
      //cout<<"This is for  P: "<<P->Elem<<endl;;
      //cout<<"Value of for this: "<<this->Front->Elem<<endl;
 

      if(Q->Elem != P->Elem){return false;}// if elem not equal return false
     
       //this->Front = Front->Next;
      Q = Q->Next;  // go next
      P = P->Next;//go next
	//OtherOne.Front = P;
	      
    }
    return true;
  }

}

