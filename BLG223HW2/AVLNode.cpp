#include "AVLNode.h"
// Constructor for avl tree node, initiliazing the basic attributes, pointing left and right to null and setting height to 1. 
Node::Node(int chrom_order, int pos_order, char alt_base) { 
  this -> chrom_order = chrom_order;
  this -> pos_order = pos_order;
  this -> alt_base = alt_base;
  this -> left = this -> right = nullptr;
  this -> height = 1;
}
Node * Node::get_left() { //getter for left child
  return this -> left;
}
Node * Node::get_right() { //getter for right child
  return this -> right;
}
void Node::set_left(Node * left) { //setter for left child
  this -> left = left;
}
void Node::set_right(Node * right) { //setter for left child
  this -> right = right;
}
int Node::get_chrom_order() { //getter for chromosom order
  return this -> chrom_order;
}
void Node::set_chrom_order(int chrom_order) { //setter for chromosom order
  this -> chrom_order = chrom_order;
}
int Node::get_pos_order() { //getter for position order
  return this -> pos_order;
}
void Node::set_pos_order(int pos_order) { //setter for position order
  this -> pos_order = pos_order;
}
char Node::get_alt_base() { //getter for alternative base
  return this -> alt_base;
}
void Node::set_height(int height) { //setter for height
  this -> height = height;
}
int Node::get_height() { //getter for height
  return this -> height;
}
void Node::set_alt_base(char alt_base) { // setter for alternative base
  this -> alt_base = alt_base;
}