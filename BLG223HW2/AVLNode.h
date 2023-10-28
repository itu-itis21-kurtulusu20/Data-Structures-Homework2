#include<iostream>

using namespace std;

class Node {
  private:

    Node * left,
  * right;
  int height;
  int chrom_order;
  int pos_order;
  char alt_base;
  public: Node(int, int, char);
  Node * get_left();
  Node * get_right();
  void set_left(Node * );
  void set_right(Node * );
  int get_height();
  void set_height(int);
  int get_chrom_order();
  void set_chrom_order(int);
  int get_pos_order();
  void set_pos_order(int);
  char get_alt_base();
  void set_alt_base(char);
};