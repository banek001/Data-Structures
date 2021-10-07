// Project Client using a generic hash table
// Loading the data file has to happen here because
// generic htable should not know about the file
// format.
// Change everywhere it says **
// Must write / change @@ functions in htable.
// Must improve the user interface!

// Name: Kunal Vilas Banekar




#include "htable.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// ** Purpose of your program here
// to store Cops date and find the cop by given id


int main()
{
  htable T;  // generic hash table

  // All declarations happen outside switch
  int key;    // ** change
  string name;// ** change and add more
  string sname;
  string position;
  string stars;
  string record;
  el_t E;     // blank element

  // File info declared outside switch
  string fname;
  cout << "What is the input file?";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  ofstream fout ("newout.txt", ios::out);


  int ans = 0;
  while (ans != 7)
    {
      // *** change menu items to be descriptive
      cout << "MENU------------------ :"<<endl;
      cout << "1. Load data from a file" << endl;
      cout << "2. Display the table" << endl;
      cout << "3. Search using a key" << endl;
      cout << "4. Add a new entry" << endl;
      cout << "5. Delete an entry" << endl;
      cout << "6. Save data to a file" << endl;
      cout << "7. Exit" << endl;
      cout << "==>";
      cin >> ans;

      switch (ans)
	{

	case 1: // ** change element parts to yours
	  while (fin >> key >> name)
	    { fin>>sname>>position>>stars>>record;  
	      T.add(el_t(key, name, sname, position, stars, record));
	    } 
	  cout << "loaded data..." << endl; 
	  break;

	case 2:
	  T.displayTable(cout); //@@to display on screen
	  // T.saveTable(cout);
	  break;

	case 3: // ** change key to yours
	  cout << "Enter key to look for: ";
	  cin >> key; 
	  cin>>name;
	  E = T.find(key, name);
	  if (E == el_t()) /// blank
	    cout << "Not found" << endl;
          else cout << "Found " << E << endl;
	  break;

	case 4: // ** change element parts to yours
          cout << "Enter a key: "; cin >> key;
	  cout << "Enter a name: "; cin >> name;
	  cout<< "Enter a surname: "; cin >>sname;
	  cout<< "Enter a position: "; cin >> position;
	  cout<< "Enter satrs: "; cin>>stars;
	  cout<< "Enter a record: "; cin >> record;
	  cout << "In Slot: " << T.add(el_t(key, name, sname, position, stars, record));//to add new data in the slot
          cout << "  added." << endl;
	  break;
       
	case 5: // ** change key to yours
	  try{
	    cout << "Enter a key: "; cin >> key;
	    cout << "Enter a name: "; cin >> name;
	    
	    cout << "In Slot: " << T.deleteIt(el_t(key,name, "", "", "", "")); //@@to delete a given slot by id
	    cout << "  deleted." << endl;
	    
	  }catch(htable::BadKey){ cout<<" Id Not Found! "<<endl;}

          // ** what happens if the item was not found?// displays not found
	  break;
        
	case 6:
	  T.displayTable(fout);//sends data to a file
	  // T.saveTable(fout);
	  cout << "Sent data to newout" << endl; 
	  break;

        default:
	  cout << "No action" << endl;
	  break;
	}
    }// end of loop
  fin.close();
  fout.close();
}

