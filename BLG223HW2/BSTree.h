#include <list>

#include "BSTNode.h"

using namespace std;

class BinSTree {
  private: BSTNode * root;
  void inorder_traverse(BSTNode * );
  public: BinSTree();
  ~BinSTree();
  void add(int, int, char);
  bool contains(int, int, char);
  void remove(int, int, char);
  void printInOrder();
};