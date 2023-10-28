
class ListNode {
  private: int chrom_order;
  int pos_order;
  char alt_base;
  ListNode * next;
  public: ListNode(int, int, char);
  ~ListNode();
  void set_chrom_order(int);
  void set_pos_order(int);
  void set_alt_base(char);
  int get_chrom_order();
  int get_pos_order();
  char get_alt_base();
  void set_next(ListNode * );
  ListNode * get_next();


};