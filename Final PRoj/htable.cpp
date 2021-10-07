// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Kunal Vilas Banekar
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include <fstream>

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key, string name)
{
  // **
  char ch;
  int a;
  int b = 0;
  int c = 0;
  for(int i = 0; i < 3; i++){
    //    cout<<"first value of i: "<<i<<endl;
    ch = name.at(i);


    a = int(ch);
    a = a - 97;
    // cout<<"alphabet: "<< ch<<" value of a: "<<a<<endl;   

    //    cout<<"valuev of i:"<<i<<" ";

    switch(i)
      {
      case 0:
	c = a * 100;
	b = b + c;
	break;

      case 1:
	c = a * 10;
	b = b + c;
	break;

      case 2:
	c = a * 1;
	b = b + c;
	break;

      default:
	cout<<"default"<<endl;
	break;





      }


    /*
    //    cout<<"value of a:"<<a<<endl;
    if(i = 0){
      c = a * 100;
      b = b + a;
    }
   if(i = 1){
      c = a * 10;
      b = b + a;
    }
    

   if(i = 2){
      c = a * 1;
      b = b + a;
    }
    */

    //    cout<<"value of i: "<<i<<"value of b: "<<b;
  }
  //  cout<<endl;
  // cout<<"value of b" <<b<<endl;
  int hkey;
  hkey = b + key;
  //cout<<"hkey: "<<hkey<<endl;
  int fkey = hkey % TSIZE;
  
  //  cout<<"fkey: "<<fkey<<" for key"<< key<<" "<<name<< " hkey value: "<<hkey<<" value for b: "<<b<<endl;
 

  return  fkey;
  // key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.getkey(), element.getname());  // hash with the key part
  //  ** Note that this means adding the element to a slist in the slot (addRear)

  table[slot].addRear(element);

  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey, string sname)
{ 
  int slot = hash(skey, sname); // hash with skey
 el_t selement;  // this is the element to look for in slist
 // ** // initialize selement with just the skey

  selement.setkey(skey);// = skey;
 // selement = skey;
 el_t Felement;
 // ** // call slist's search2 with selement which returns the found element 
 Felement = table[slot].search2(selement);
 
 // ** // return the found element from here (it could be blank)
 return Felement;
}

// displays the entire table with slot#s too
void htable::displayTable(ostream& fout)
{
  //  cout<<"ins just dip"<<endl;
  //  if(fout){
  for (int i = 0; i < 47; i++)
    { cout << i << ":" ;   
      //   ** // call slist's displayAll
      table[i].displayAll(fout);// display to the file or as requested

    }
  // }

}


/*
void htable::saveTable(ostream& fout)
{
  cout<<"in stable"<<endl;

  for (int i = 0; i < 37; i++)
    {// fout << i << ":" ;
      //   ** // call slist's displayAll
      //      table[i].displayAll();
    }
  llist k;
      if(!k.isEmpty()){
	cout<<"inside is empty"<<endl;
      Node *P;
      P = k.Front;
      cout<<"[ ";
	while(P != NULL){
	  cout<<P->Elem<<" ";
	  P = P->Next;
	}
      cout<<" ]"<<endl;
      }else{fout<<"";}// "[empty]" <<endl;}

      //      fout.close();







}
*/
int htable::deleteIt(el_t element) //to delete an element by the given key
{


  int slot = hash(element.getkey(), element.getname());  // hash with the key part


  /////////////////////////////////////////
  //  int slot = hash(skey); // hash with skey
  el_t selement;  // this is the element to look for in slist
  // ** // initialize selement with just the skey

  selement.setkey(slot);// = skey;
  // selement = skey;
  int Felement;
  // ** // call slist's search2 with selement which returns the found element
  Felement = table[slot].search(element);
  // cout<<"Felement: "<<Felement<<endl;


  //  if(Felement > -1){ 


  //  cout<<"Value of slot:"<<slot<<endl;


  if(Felement < 47){
  table[slot].deleteIth(Felement, element);

  return slot;
  }else{ throw BadKey();}
}
