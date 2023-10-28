
#include <stdio.h>

#include "ListNode.h"

ListNode::ListNode(int chrom_order, int pos_order, char alt_base) { //constructor for linked list
  this -> chrom_order = chrom_order;
  this -> pos_order = pos_order;
  this -> alt_base = alt_base;
  this -> next = NULL;
}
ListNode::~ListNode() { //destructor for linked list
  if (this -> next != NULL)
    delete this -> next;
}
void ListNode::set_chrom_order(int chrom_order) { // setter for chromosom order
  this -> chrom_order = chrom_order;
}
void ListNode::set_pos_order(int pos_order) {// setter for position order
  this -> pos_order = pos_order;
}
void ListNode::set_alt_base(char alt_base) { // setter for alternative base
  this -> alt_base = alt_base;
}
int ListNode::get_chrom_order() {// getter for chromosom order
  return this -> chrom_order;
}
int ListNode::get_pos_order() {// getter for position order
  return this -> pos_order;
}
char ListNode::get_alt_base() {// getter for alternative base
  return this -> alt_base;
}
void ListNode::set_next(ListNode * next) { // setter for next
  this -> next = next;
}
ListNode * ListNode::get_next() { // getter for next
  return this -> next;
}
