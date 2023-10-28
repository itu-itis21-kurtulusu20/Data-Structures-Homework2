#include "AVLTree.h"
#include <vector>

AVLTree::AVLTree() {
  root = nullptr;
}

int AVLTree::height(Node * N) { //function that returns the given node's height, will be used in the rotations when we balance the tree.
  if (N == nullptr)
    return 0;
  return N -> get_height();
}

int AVLTree::max(int a, int b) { // function that returns two integers bigger one. will be used in the rotation functions.
  return (a > b) ? a : b;
}

Node * AVLTree::rightRotate(Node * y) { // right rotation for balancing
  Node * x = y -> get_left();
  Node * T2 = x -> get_right();
  x -> set_right(y);
  y -> set_left(T2);
  y -> set_height(max(height(y -> get_left()), height(y -> get_right())) + 1);
  x -> set_height(max(height(x -> get_left()), height(x -> get_right())) + 1);
  return x; // new root
}

Node * AVLTree::leftRotate(Node * x) {  // left rotation for balancing
  Node * y = x -> get_right();
  Node * T2 = y -> get_left();
  y -> set_left(x);
  x -> set_right(T2);
  x -> set_height(max(height(x -> get_left()), height(x -> get_right())) + 1);
  y -> set_height(max(height(y -> get_left()), height(y -> get_right())) + 1);
  return y; // new root
}

int AVLTree::getBalance(Node * N) { // function that returns the given nodes' left and right height differences. will be used when we add a new node.
  if (N == nullptr)
    return 0;
  return height(N -> get_left()) - height(N -> get_right());
}

Node* AVLTree::addNode(Node* node, int chrom_order, int pos_order, char alt_base) {
    // Create a new node if the tree is empty
    if (node == nullptr)
        return new Node(chrom_order, pos_order, alt_base);

    Node* curr = node;
    Node* parent = nullptr;
    bool insertLeft = false;

    // Traverse the tree iteratively to find the appropriate position for insertion
    while (curr != nullptr) {
        parent = curr;

        if (chrom_order < curr->get_chrom_order() ||
            (chrom_order == curr->get_chrom_order() && pos_order < curr->get_pos_order())) {
            curr = curr->get_left();
            insertLeft = true;
        }
        else if (chrom_order > curr->get_chrom_order() ||
                 (chrom_order == curr->get_chrom_order() && pos_order > curr->get_pos_order())) {
            curr = curr->get_right();
            insertLeft = false;
        }
        else {
            delete node;  // Node with the attributes already exists, no need to insert
        }
    }

    // Create a new node and set the appropriate child of the parent
    Node* newNode = new Node(chrom_order, pos_order, alt_base);
    if (insertLeft)
        parent->set_left(newNode);
    else
        parent->set_right(newNode);

    // Update the height of the parent node
    parent->set_height(1 + max(height(parent->get_left()), height(parent->get_right())));

    // Check the balance and perform rotations if necessary
    int balance = getBalance(parent);

    // Left Left Case
    if (balance > 1 && chrom_order < parent->get_left()->get_chrom_order())
        return rightRotate(parent);

    // Right Right Case
    if (balance < -1 && chrom_order > parent->get_right()->get_chrom_order())
        return leftRotate(parent);

    // Left Right Case
    if (balance > 1 && chrom_order > parent->get_left()->get_chrom_order()) {
        parent->set_left(leftRotate(parent->get_left()));
        return rightRotate(parent);
    }

    // Right Left Case
    if (balance < -1 && chrom_order < parent->get_right()->get_chrom_order()) {
        parent->set_right(rightRotate(parent->get_right()));
        return leftRotate(parent);
    }

    return node;
}

void AVLTree::addNode(int chrom_order, int pos_order, char alt_base) {
    root = addNode(root, chrom_order, pos_order, alt_base);
}
// function that traverses the tree and prints it inorder way.
void AVLTree::inorder(Node * node) {
  if (node != nullptr) {
    inorder(node -> get_left());
    std::cout << node -> get_chrom_order()<<" "<< node -> get_pos_order()<<" "<< node -> get_alt_base()<<",";
    inorder(node -> get_right());
  }
}
Node * AVLTree::minValueNode(Node * node) { // function that returns the minimum of left or right child of a node. it will be used in removing.
  Node * current = node;
  while (current -> get_left() != nullptr)
    current = current -> get_left();
  return current;
}
Node * AVLTree::removeNode(Node * root, int chrom_order, int pos_order, char alt_base) {
  if (root == nullptr)
    return root;

  // If the node to be deleted is smaller than the root node,
  // then it lies in the left subtree
  if (chrom_order < root -> get_chrom_order() ||
    (chrom_order == root -> get_chrom_order() && pos_order < root -> get_pos_order()) ||
    (chrom_order == root -> get_chrom_order() && pos_order == root -> get_pos_order() && alt_base < root -> get_alt_base()))
    root -> set_left(removeNode(root -> get_left(), chrom_order, pos_order, alt_base));

  // If the node to be deleted is greater than the root node,
  // then it lies in the right subtree
  else if (chrom_order > root -> get_chrom_order() ||
    (chrom_order == root -> get_chrom_order() && pos_order > root -> get_pos_order()) ||
    (chrom_order == root -> get_chrom_order() && pos_order == root -> get_pos_order() && alt_base > root -> get_alt_base()))
    root -> set_right(removeNode(root -> get_right(), chrom_order, pos_order, alt_base));

  
  else {
    // Node with only one child or no child
    if ((root -> get_left() == nullptr) || (root -> get_right() == nullptr)) {
      Node * temp = root -> get_left() ? root -> get_left() : root -> get_right();

      // No child case
      if (temp == nullptr) {
        temp = root;
        root = nullptr;
      } else // One child case
        *
        root = * temp; // Copy the contents of the non-empty child

      delete temp;
    } else {
      // Node with two children: Get the inorder successor (smallest
      // in the right subtree)
      Node * temp = minValueNode(root -> get_right());

      // Copy the inorder successor's data to this node
      root -> set_chrom_order(temp -> get_chrom_order());
      root -> set_pos_order(temp -> get_pos_order());
      root -> set_alt_base(temp -> get_alt_base());

      // Delete the inorder successor
      root -> set_right(removeNode(root -> get_right(), temp -> get_chrom_order(), temp -> get_pos_order(), temp -> get_alt_base()));
    }
  }

  // If the tree had only one node then return
  if (root == nullptr)
    return root;

  // Update the height of the current node
  root -> set_height(1 + max(height(root -> get_left()), height(root -> get_right())));

  // Get the balance factor
  int balance = getBalance(root);

  // Balance the tree
  // Left Left Case
  if (balance > 1 && getBalance(root -> get_left()) >= 0)
    return rightRotate(root);

  // Left Right Case
  if (balance > 1 && getBalance(root -> get_left()) < 0) {
    root -> set_left(leftRotate(root -> get_left()));
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalance(root -> get_right()) <= 0)
    return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalance(root -> get_right()) > 0) {
    root -> set_right(rightRotate(root -> get_right()));
    return leftRotate(root);
  }

  return root;
}

void AVLTree::removeNode(int chrom_order, int pos_order, char alt_base) {
  root = removeNode(root, chrom_order, pos_order, alt_base);
}
void AVLTree::inorder() {
  inorder(root);
}
//function to search the avl tree to find a spesific node.
bool AVLTree::contains(Node * root, int chrom_order, int pos_order, char alt_base) {
  if (root == nullptr)
    return false;

  if (chrom_order < root -> get_chrom_order() ||
    (chrom_order == root -> get_chrom_order() && pos_order < root -> get_pos_order()) ||
    (chrom_order == root -> get_chrom_order() && pos_order == root -> get_pos_order() && alt_base < root -> get_alt_base())) //recursively go left.
    return contains(root -> get_left(), chrom_order, pos_order, alt_base);
  else if (chrom_order > root -> get_chrom_order() ||
    (chrom_order == root -> get_chrom_order() && pos_order > root -> get_pos_order()) ||
    (chrom_order == root -> get_chrom_order() && pos_order == root -> get_pos_order() && alt_base > root -> get_alt_base())) //recursively go right.
    return contains(root -> get_right(), chrom_order, pos_order, alt_base);
  else
    return true; // Node found
}

bool AVLTree::contains(int chrom_order, int pos_order, char alt_base) {
  return contains(root, chrom_order, pos_order, alt_base);
}

void compareinorder(Node* node, std::vector<Node*>& nodes) {
  if (node != nullptr) {
    compareinorder(node->get_left(), nodes);
    nodes.push_back(node);
    compareinorder(node->get_right(), nodes);
  }
}