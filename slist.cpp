#include "slist.h"
#include <iostream>
using namespace std;
/*
Class Library File
*/


Linked_List::Linked_List() {
    head = NULL;
  }

// Destructor
Linked_List::~Linked_List() {
    Node *ptr;
    for (ptr = head; head; ptr = head) {
      head = head->next;
      delete ptr;
    }
  }

// add(value)				//Adds a new value to the end of this list.
  void Linked_List::add(Airport *value) {
    Node *newNode = new Node(value);
    if (head == NULL) {
      head = newNode;
      return;
    }
    Node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }

  //get(index)				//Returns the element at the specified index in this list.
Airport* Linked_List::get(int index) {
  Node *current = head;
  if (index == 0) {
    return head->data;
  }
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current->data;
}


// clear()					//Removes all elements from this list.
  void Linked_List::clear() {
    Node *temp = head->next;
    while (temp != NULL) {
      head->next = temp->next;
      temp->next = NULL;
      free(temp);
      temp = head->next;
    }
  }

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool Linked_List::equals(Linked_List list) {
  Node *t1 = head;
  Node *t2 = list.head;
  while (t1 != nullptr) {
    if (t1->next != t2->next) {
      return false;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  return true;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void Linked_List::insert(int index, Airport *value) {
  Node *newNode = new Node(value);
  Node *current = head;
  for (int i = 0; i < index-1; i++) {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void Linked_List::exchg(int index1, int index2) {
  Node *current1 = head;
  Node *current2 = head;
  for (int i = 0; i < index1; i++) {
    current1 = current1->next;
  }
  for (int i = 0; i < index2; i++) {
    current2 = current2->next;
  }
  Airport *temp = current1->data;
  current1->data = current2->data;
  current2->data = temp;
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void Linked_List::swap(int index1, int index2) {
  if (index1 == index2) {
    return;
  }
  Node *p1 = NULL;
  Node *p2 = NULL;
  Node *current1 = head;
  Node *current2 = head;
  for (int i = 0; i < index1; i++) {
    p1 = current1;
    current1 = current1->next;
  }
  for (int i = 0; i < index2; i++) {
    p2 = current2;
    current2 = current2->next;
  }
  if (p1 != NULL)  {
    p1->next = current2;  
  } else {
    head = current2;
  } 

  if (p2 != NULL) {
    p2->next = current1;
  } else {
    head = current1;
  }
  Node *temp = current1->next;   
  current1->next = current2->next;   
  current2->next = temp;     
}    


// isEmpty()				//Returns true if this list contains no elements.
bool Linked_List::isEmpty() {
  if (head == NULL) {
    return true;
  }
  return false;
}

// remove(index)			//Removes the element at the specified index from this list.
void Linked_List::remove(int index) {
  Node *current = head;
  for (int i = 0; i < index-2; i++) {
    current = current->next;
  }
  Node *temp = current->next;
  current->next = temp->next;
  delete temp;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void Linked_List::set(int index, Airport *value) {
  Node *current = head;
  for (int i = 0; i < index-1; i++) {
    current = current->next;
  }
  current->data = value;
}

// size()					//Returns the number of elements in this list.
int Linked_List::size() {
  int count;
  Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
      count++;
    }
  return count;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
Linked_List Linked_List::sublist(int start, int length) {
  Linked_List newList = Linked_List();
  newList.head = head;
  Node *current = head;
  for (int i = 0; i < length; i++) {
    current = current->next;
    newList.add(current->data);
  }
  return newList;
}

// toString()				//Converts the list to a printable string representation.
std::string Linked_List::toString() {
  Node *current = head;
  string str = "";
  while (current != NULL) {
    str += current->Node::data->code;
    str += "\n";
    current = current->next;
  }
  return str;
} 