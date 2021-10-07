// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Kunal Vilas Banekar
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{
  //  /***
  htable obj;
  el_t empty;
  int key = 0;
  string name = "";//[20];
  // Loop:  
  for(int i = 0; i<6; i++)
    {
      // Interactively add about 20 keys and names to the table,
      cout<<"Enter a key: ";
      cin>>key;
      cout<<"Enter a name: ";
      cin>>name;
      
      // making sure some of them  collide. (function add)

      
      // You can create el_t containing a key and name using a constructor.
      el_t elem(key, name);

      obj.add(elem);

    }
  
  
  // DisplayTable.
  obj.displayTable();
  
  int keypart =0;
  
  // Loop:
  while(keypart != -1)
    {
      
      // Interactively look up names using keys. (function find)
      cout<<"Enter a key you want to look for: ";
      cin>>keypart;
      
      // Cout the key + name if found else (blank element was returned i.e. key part is -1)
      if(keypart != -1)
	{
	  cout<<"befor fkeypart"<<endl;
	  el_t fkeypart = obj.find(keypart);
	  cout<<"after fkeypart"<<endl;
	  if(fkeypart == empty)
	    {
	      cout<<"inside if"<<endl;
	      cout <<keypart<<" :Not found!"<<endl;
	      //	      cout <<" :Not found!"<<endl;
	    }else{
	    cout<<"inside else"<<endl;
	    cout<< fkeypart<< " Found!" <<endl;
	    // cout<<" Found!" <<endl;
	    
	    // an error message. 
	  }
	  //  */
	}
      
    }
}
