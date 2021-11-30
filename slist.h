#include <iostream>
#include <fstream>
#include <cmath> 

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

class Node {
public:
  Airport *data;
  Node *next;

  Node() {
    data = NULL;
    next = NULL;
  }

  Node (Airport *d) {
    this->data = d;
    this->next = NULL;
}
};

class Linked_List {
private:
  Node *head;
  
// Constructor
public:
  Linked_List();

// Destructor
  ~Linked_List();

  void add(Airport *value);

  void clear();

  bool equals(Linked_List list);

  Airport* get(int index);

  void insert(int index, Airport *value);

  void exchg(int index1, int index2);

  void swap(int index1, int index2);

  bool isEmpty();

  void remove(int index);

  void set(int index, Airport *value);

  int size();

  Linked_List sublist(int start, int length);

  std::string toString();

};