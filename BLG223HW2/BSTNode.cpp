#include "BSTNode.h"

#include <stdlib.h>


BSTNode::BSTNode(int chrom_order, int pos_order, char alt_base) { //constructor for binary search tree
  this -> chrom_order = chrom_order;
  this -> pos_order = pos_order;
  this -> alt_base = alt_base;
  this -> left = NULL;
  this -> right = NULL;
}
void BSTNode::set_left(BSTNode * left) { //setter for left
  this -> left = left;
}

void BSTNode::set_right(BSTNode * right) { //setter for right
  this -> right = right;
}

void BSTNode::set_chrom_order(int chrom_order) { //setter for chromosom order
  this -> chrom_order = chrom_order;
}
void BSTNode::set_pos_order(int pos_order) {//setter for position order
  this -> pos_order = pos_order;
}
void BSTNode::set_alt_base(char alt_base) {//setter for alternative base
  this -> alt_base = alt_base;
}
BSTNode * BSTNode::get_left() {//getter for left
  return this -> left;
}
BSTNode * BSTNode::get_right() {//getter for right
  return this -> right;
}
int BSTNode::get_chrom_order() {//getter for chromosom order
  return this -> chrom_order;
}
int BSTNode::get_pos_order() {//getter for position order
  return this -> pos_order;
}
char BSTNode::get_alt_base() {//getter for alternative base
  return this -> alt_base;
}
BSTNode ** BSTNode::get_left_addr() {//getter for left address
  return & (this -> left);
}
BSTNode ** BSTNode::get_right_addr() {//setter for right address
  return & (this -> right);
}

void BSTNode::remove(int chrom_order, int pos_order, char alt_base) {
  if (this -> get_chrom_order() != chrom_order) {
    if (this -> get_chrom_order() > chrom_order) // if we wanted node's chrom order is smaller we will check the left subtree
      if (this -> left != NULL && this -> left -> get_chrom_order() == chrom_order && this -> left -> get_pos_order() == pos_order && this -> left -> get_alt_base() == alt_base) {
        BSTNode * left_child = this -> left -> left;//left and right children
        BSTNode * right_child = this -> left -> right;
        delete this -> left;
        if (left_child != NULL) {
          this -> left = left_child;
          BSTNode * t = this -> left; // temporarily t node for going to the rightest of tree
          while (t -> right != NULL)
            t = t -> right;
          t -> right = right_child;
        } else this -> left = right_child;
      }
    else if (this -> left != NULL)
      this -> left -> remove(chrom_order, pos_order, alt_base); // recursively going left
    else return;
    else if (this -> get_chrom_order() < chrom_order) // chrom order is bigger so we should check right subtree.
      if (this -> right != NULL && this -> right -> get_chrom_order() == chrom_order && this -> right -> get_pos_order() == pos_order && this -> right -> get_alt_base() == alt_base) {
        BSTNode * left_child = this -> right -> left; //left and right children
        BSTNode * right_child = this -> right -> right;
        delete this -> right;
        if (left_child != NULL) {
          this -> right = left_child;
          BSTNode * t = this -> right; // temporarily t node for going the rightest of tree.
          while (t -> right != NULL)
            t = t -> right;
          t -> right = right_child;
        } else this -> right = right_child;
      }
    else if (this -> right != NULL)
      this -> right -> remove(chrom_order, pos_order, alt_base); // recursively going right
    else return;

  } else {
    if (this -> get_pos_order() > pos_order) // if the chromosom orders are same we should check position numbers, wanted nodes' smaller (checking left)
      if (this -> left != NULL && this -> left -> get_chrom_order() == chrom_order && this -> left -> get_pos_order() == pos_order && this -> left -> get_alt_base() == alt_base) {
        BSTNode * left_child = this -> left -> left;
        BSTNode * right_child = this -> left -> right;
        delete this -> left;
        if (left_child != NULL) {
          this -> left = left_child;
          BSTNode * t = this -> left; // temporarily t node for going the rightest of tree.
          while (t -> right != NULL)
            t = t -> right;
          t -> right = right_child;
        } else this -> left = right_child;
      }
    else if (this -> left != NULL)
      this -> left -> remove(chrom_order, pos_order, alt_base);
    else return;
    else if (this -> get_pos_order() < pos_order) // pos order is bigger so we should check right subtree.
      if (this -> right != NULL && this -> right -> get_chrom_order() == chrom_order && this -> right -> get_pos_order() == pos_order && this -> right -> get_alt_base() == alt_base) {
        BSTNode * left_child = this -> right -> left; //left and right children
        BSTNode * right_child = this -> right -> right;
        delete this -> right;
        if (left_child != NULL) {
          this -> right = left_child;
          BSTNode * t = this -> right;
          while (t -> right != NULL) // temporarily t node for going the rightest of tree.
            t = t -> right;
          t -> right = right_child;  //update the tree
        } else this -> right = right_child;
      }
    else if (this -> right != NULL)
      this -> right -> remove(chrom_order, pos_order, alt_base);
    else return;
  }

}