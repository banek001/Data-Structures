// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  name = "";
  sname = "";
  position = "";
  stars = "";
  record = "";
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aname, string asname, string aposition, string astars, string arecord)
{
  key = akey;
  name = aname;
  sname = asname;
  position = aposition;
  stars = astars;
  record = arecord;

}

int el_t::getkey()
{
  return key;
}
 
void el_t::setkey(int akey)
{
  key = akey;
}

string el_t::getname()
{
  return name;
}

void el_t::setname(string aname)
{
  name = aname;
}

  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os <<"Cop ID: "<< E.key<<endl;
  os <<"Cop Name: " << E.name<< " " << E.sname <<endl;
  os <<"Cop Position: " <<E.position <<endl;
  os <<"Cop stars: "<<E.stars<<endl;
  os <<"Record: "<<E.record<<endl;
 
  return os;  
}  
