
#include <iostream>

#include <stdio.h>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() { //constructor for linked list
  head = NULL;
  tail = NULL;
}

LinkedList::~LinkedList() {//destructor for linked list
  if (head != NULL)
    delete head;
}

bool LinkedList::contains(int chrom_order, int pos_order, char alt_base) {

  ListNode * p = head;
  while (p != NULL) // starting from head and going next until the element is found
    if (p -> get_chrom_order() != chrom_order || p -> get_pos_order() != pos_order || p -> get_alt_base() != alt_base) {
      p = p -> get_next();
    }
  else {
    return true;
  }
  if (p == NULL)
    return false; // element is not found
}
//inserting a new node to the end of the list.
void LinkedList::add_node(int chrom_order, int pos_order, char alt_base) {
  ListNode * new_node = new ListNode(chrom_order, pos_order, alt_base); //declearing a new linked list node
  ListNode * p = head;
  if (head == NULL) { // if linked list is empty
    head = new_node;
    tail = new_node;
  } else {
    while (p -> get_next() != NULL) {
      p = p -> get_next(); // going to end of the list
    }
    p -> set_next(new_node); // inserting the new node
    tail = new_node;  // updating the tail 
    new_node -> set_next(NULL); //setting tails' next to NULL
  }
}
void LinkedList::remove_node(int chrom_order, int pos_order, char alt_base) {
  if (head == tail) { // if theres only one node 
    delete head;
    head = NULL;
    tail = NULL;
  } else {
    // finding the wanted node
    if (head -> get_chrom_order() == chrom_order && head -> get_pos_order() == pos_order && head -> get_alt_base() == alt_base) {
      ListNode * old_head = head; //if the head will be deleted
      head = head -> get_next();
      old_head -> set_next(NULL); 
      delete old_head;
    } else if (tail -> get_chrom_order() == chrom_order && tail -> get_pos_order() == pos_order && tail -> get_alt_base() == alt_base) {
      //if the tail will be deleted
      ListNode * p = head;
      while (p -> get_next() -> get_next()) {
        p = p -> get_next();
      }
      tail = p;
      delete tail -> get_next();
      tail -> set_next(NULL);
    } else {
      // if its not head nor tail we will search until we found the node
      ListNode * p = head;
      while (p -> get_next() -> get_chrom_order() != chrom_order || p -> get_next() -> get_pos_order() != pos_order || p -> get_next() -> get_alt_base() != alt_base) {
        p = p -> get_next();
      }
      ListNode * cur = p -> get_next();
      p -> set_next(cur -> get_next());
      cur -> set_next(NULL); // updating the previous node 
      delete cur;
    }
  }
}
void LinkedList::print_list() { 
  ListNode * p = head;
  while (p != tail) { // printing until the tail
    cout << p -> get_chrom_order() << " " << p -> get_pos_order() << " " << p -> get_alt_base() << ",";
    p = p -> get_next();
  }
  if (p != NULL) // printing the tail
    cout << p -> get_chrom_order() << " " << p -> get_pos_order() << " " << p -> get_alt_base();

}
