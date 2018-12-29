// Daniel Lok - Hashtable
// Looking at efficient ways of storing data.
// Time Complexity: O(1) if hashing function is good.
// Space Complexirty: O(N)

#include "Hashtable.h"

Hashtable::Hashtable(){
  for(int i = 0; i < tableSize; i++){
    Hashing[i] = new item;
    Hashing[i]->name = "empty";
    Hashing[i]->drink = "empty";
    Hashing[i]->next = NULL;
  }
}

int Hashtable::hash(string key){
  int hash = 0;
  int index;

  for(int i = 0; i < key.length(); i++){
    hash = (hash + (int) key[i]) * 13;
  }

  index = hash % tableSize;

  return index;
}

void Hashtable::AddItem(string name, string drink){
   int index = hash(name);

   if(Hashing[index]->name == "empty"){
   Hashing[index]->name = name;
   Hashing[index]->drink = drink;
 } else{
   item* Ptr = Hashing[index];
   item* n = new item;
   n->name = name;
   n->drink = drink;
   n->next = NULL;
      while(Ptr->next != NULL){
        Ptr = Ptr->next;
      }
  Ptr->next = n;
 }
}

int Hashtable::NumberOfItemsInIndex(int index){
  int count = 0;

  if(Hashing[index]->name == "empty"){
    return count;
  } else{
    count++;
    item* Ptr = Hashing[index];
    while(Ptr->next != NULL){
      count++;
      Ptr = Ptr->next;
    }
  }
  return count;
}

void Hashtable::PrintTable(){
  int num;
  for (int i = 0; i < tableSize; i++){
    num = NumberOfItemsInIndex(i);
    cout << "# of items in bucket " << i << ": " << num << endl;
    item* Ptr = Hashing[i];
    if(Ptr->name == "empty"){
      cout << "This bucket is empty." << endl;
    } else{
      while(Ptr != NULL){
        cout << Ptr->name << endl;
        cout << Ptr->drink << endl;
        Ptr = Ptr->next;
      }
    }
  }
}

string Hashtable::FindDrink(string name){
  int index = hash(name);
  item* Ptr = Hashing[index];

  if(Ptr->name == "empty"){
    string ans = name + " is not in this hash table";
    return ans;
  } else{
    while(Ptr != NULL){
      if(Ptr->name == name){
        return Ptr->drink;
      }
      Ptr = Ptr->next;
    }
    string ans = name + " is not in this hash table";
    return ans;
  }

}

void Hashtable::RemoveItem(string name){
  int index = hash(name);

  item* PointertoDelete;
  item* Pointer1;
  item* Pointer2;

  // If bucket has no items
  if(Hashing[index]->name == "empty"){
    cout << "Cannot delete " << name << "." << " " << name <<  " was not found in hashtable" << endl;
  }
  // If bucket only has 1 item and it matches name matches name given.
  else if(Hashing[index]->name == name && Hashing[index]->next == NULL){
    Hashing[index]->name = "empty";
    Hashing[index]->drink = "empty";

      cout << name << " has been removed from the hashtable" << endl;
  }
  //First linked list element matches name we want to delete and the linked list array
  // contains more than one element
  else if(Hashing[index]->name == name){
    PointertoDelete = Hashing[index];
    Hashing[index] = Hashing[index]->next;
    delete PointertoDelete;

    cout << name << " has been removed from the hashtable" << endl;
  }
  // bucket contains multiple items and first name is not a match
  else{
    Pointer1 = Hashing[index]->next;
    Pointer2 = Hashing[index];

    while(Pointer1 != NULL){
      if(Pointer1->name == name){
      //Debugging statements
//      cout << "Setting Pointer to Delete: " << endl;
        PointertoDelete = Pointer1;
//      cout << "Setting Pointer1" << endl;
        Pointer1 = Pointer1->next;
//      cout << "Setting Pointer2" << endl;
        Pointer2->next = Pointer1;
        delete PointertoDelete;

        cout << name << " has been removed from the hashtable" << endl;
        return;
      }

//     cout << "Incrementing P1" << endl;
      Pointer2 = Pointer1;
//     cout << "Incrementing P2" << endl;
      Pointer1 = Pointer1->next;
    }
        cout << "Cannot delete " << name << ". Key was not found in hashtable" << endl;

  }
}

int main(){
  Hashtable hash1;
  string nameToRemove;

  hash1.AddItem("Paul", "Locha");
  hash1.AddItem("Kim", "Iced Mocha");
  hash1.AddItem("Emma", "Strawberry Smoothy");
  hash1.AddItem("Annie", "Hot Chocolate");
  hash1.AddItem("Sarah", "Passion Tea");
  hash1.AddItem("Pepper", "Caramel Mocha");
  hash1.AddItem("Mike", "Chai Tea");
  hash1.AddItem("Steve", "Apple Cider");
  hash1.AddItem("Bill", "Root Beer");
  hash1.AddItem("Marie", "Skinny Latte");
  hash1.AddItem("Susan", "Water");
  hash1.AddItem("Joe", "Green Tea");

  hash1.PrintTable();
  //string KimsDrink = hash1.FindDrink("JimJoe");
  //cout << KimsDrink << endl;

  while(nameToRemove != "exit"){
    cout << "Type 'exit' to stop program" << endl;
    cout << "Remove: ";
    cin >> nameToRemove;
    if(nameToRemove != "exit"){
      hash1.RemoveItem(nameToRemove);
    }
  }

  cout << endl;
  cout << endl;
  hash1.PrintTable();

  return 0;
}
