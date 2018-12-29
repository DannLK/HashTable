// Daniel Lok - Hashtable header file
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


// In this example
// name: string that you want to hash
// drink: key associated with string name

class Hashtable{
private:
  static const int tableSize = 4;

  struct item{
    string name;
    string drink;
    item* next;
  };

  //Array of linked lists
  item* Hashing[tableSize];

public:
  Hashtable();
  int hash(string key);
  void AddItem(string name, string drink);
  int NumberOfItemsInIndex(int index);
  // Prints items in each bucket and how many linked lists elements the bucket has.
  void PrintTable();
  //i.e Searching for key
  string FindDrink(string name);
  void RemoveItem(string name);
};
