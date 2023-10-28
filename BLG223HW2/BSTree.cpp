#include <iostream>
#include "BSTree.h"
using namespace std;

BinSTree::BinSTree() { //constructor for Binary search tree
  this -> root = NULL;
}

void BinSTree::remove(int chrom_order, int pos_order, char alt_base) { // it will be recursively used with the remove function in the bstnode.h
  if (this -> root -> get_chrom_order() == chrom_order && this -> root -> get_pos_order() == pos_order && this -> root -> get_alt_base() == alt_base) {
    if (this -> root -> get_left() != NULL) {
      BSTNode * t = this -> root;
      this -> root = this -> root -> get_left();
      BSTNode * p = this -> root; // p node to get the rightest of tree
      while (p -> get_right() != NULL)
        p = p -> get_right();
      p -> set_right(t -> get_right()); // update the tree
      delete t;
    } else {
      BSTNode * t = this -> root;
      this -> root = this -> root -> get_right();
      delete t;
    }
  } else this -> root -> remove(chrom_order, pos_order, alt_base);
}

bool BinSTree::contains(int chrom_order, int pos_order, char alt_base) {
  if (this -> root == NULL)
    return false;
  BSTNode * temp = root;
  while (temp != NULL) {
    if (temp -> get_chrom_order() > chrom_order) { // chrom order is smaller so we should go left
      temp = temp -> get_left();
    } else if (temp -> get_chrom_order() < chrom_order) { // chrom order is bigger so we should go left
      temp = temp -> get_right();
    } else if (temp -> get_chrom_order() == chrom_order) { // if chrom orders are same we should now start to check pos orders
      if (temp -> get_pos_order() > pos_order) {
        temp = temp -> get_left(); // pos order is smaller so go left
      } else if (temp -> get_pos_order() < pos_order) {
        temp = temp -> get_right(); // pos order is bigger so go right
      } else if (temp -> get_pos_order() == pos_order && temp -> get_alt_base() == alt_base) {
        return true;  //node is found
      }
    } else {
      return true;
    }
  }
  return false;

}

void BinSTree::add(int chrom_order, int pos_order, char alt_base) {
  BSTNode * n = new BSTNode(chrom_order, pos_order, alt_base); // declearing a new bsnode
  if (this -> root == NULL) { //  tree is empty
    root = n;
    return;
  }
  BSTNode * temp = root;
  while (temp != NULL) {
    if (temp -> get_chrom_order() > chrom_order) { // if the chrom order is smaller, first null checking and then setting the left node.
      if (temp -> get_left() == NULL) {
        temp -> set_left(n);
        return;
      }
      temp = temp -> get_left();
    } else if (temp -> get_chrom_order() < chrom_order) { // if the chrom order is bigger, first null checking and then setting the right node.
      if (temp -> get_right() == NULL) {
        temp -> set_right(n);
        return;
      }
      temp = temp -> get_right();
    } else if (temp -> get_chrom_order() == chrom_order) { // if the chrom numbers are same we should start checking position orders
      if (temp -> get_pos_order() > pos_order) { // pos order is smaller go left
        if (temp -> get_left() == NULL) {
          temp -> set_left(n);
          return;
        }
        temp = temp -> get_left();
      } else if (temp -> get_pos_order() < pos_order) { //pos order is bigger so go right
        if (temp -> get_right() == NULL) {
          temp -> set_right(n);
          return;
        }
        temp = temp -> get_right();
      } else { // node is already exist, delete the node.
        delete n;
        return;
      }
    }
  }

}

void BinSTree::inorder_traverse(BSTNode * n) { // inorder traversing for bs tree

  if (n != NULL) {
    this -> inorder_traverse(n -> get_left()); // recursively going left 
    cout << n -> get_chrom_order() << " " << n -> get_pos_order() << " " << n -> get_alt_base() << ",";
    this -> inorder_traverse(n -> get_right()); // recursively going right 
  }

}
void BinSTree::printInOrder() {
  this -> inorder_traverse(this -> root);
  cout << endl;
}