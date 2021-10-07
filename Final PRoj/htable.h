// CS311 Yoshii - Hash Table header DO NOT CHANGE!!! 
// ------------------------------------------------

#include "slist.h"

const int TSIZE = 47;  // 47 slots ; a prime number 

class htable
{
 private:
 slist table[TSIZE]; // each node of slist is el_t 
                          // as defined in elem.h
 int hash(int, string);  // private hash function

 public:
  htable();
  ~htable();
  class BadKey{};
  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(int, string); // finds an element based on key and returns it
  void displayTable(ostream&); // displays the table with slot#s
  //  void saveTable(ostream&);
  int deleteIt(el_t);//to delete with given key

};
