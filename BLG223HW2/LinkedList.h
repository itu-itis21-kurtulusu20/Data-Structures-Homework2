
#include "ListNode.h"

class LinkedList {
  private: ListNode * head;
  ListNode * tail;
  ListNode * search(int, int, char);

  public: LinkedList();
  ~LinkedList();
  void add_node(int, int, char);
  void remove_node(int, int, char);
  void print_list();
  bool contains(int, int, char);
};
