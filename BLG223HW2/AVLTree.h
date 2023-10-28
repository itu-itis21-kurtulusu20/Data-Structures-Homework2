#include "AVLNode.h"
#include <vector>
class AVLTree {
  private: 
  public: AVLTree();
  Node * root;
  int height(Node * N);

  int max(int a, int b);

  Node * rightRotate(Node * y);

  Node * leftRotate(Node * x);

  int getBalance(Node * N);

  Node * addNode(Node * node, int chrom_order, int pos_order, char alt_base);

  void addNode(int chrom_order, int pos_order, char alt_base);

  Node * minValueNode(Node * node);

  Node * removeNode(Node * root, int chrom_order, int pos_order, char alt_base);
  void removeNode(int chrom_order, int pos_order, char alt_base);

  void inorder();
  void inorder(Node * node);
  bool contains(Node * root, int chrom_order, int pos_order, char alt_base);
  bool contains(int chrom_order, int pos_order, char alt_base);

void compareinorder(Node* node, std::vector<Node*>& nodes) ;

};