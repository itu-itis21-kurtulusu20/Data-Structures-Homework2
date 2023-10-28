class BSTNode {
  private: int chrom_order;
  int pos_order;
  char alt_base;
  BSTNode * left;
  BSTNode * right;

  public: void remove(int, int, char);
  BSTNode(int, int, char);
  void set_left(BSTNode * );
  void set_right(BSTNode * );
  void set_chrom_order(int);
  void set_pos_order(int);
  void set_alt_base(char);
  BSTNode * get_left();
  BSTNode * get_right();
  BSTNode ** get_left_addr();
  BSTNode ** get_right_addr();
  int get_chrom_order();
  int get_pos_order();
  char get_alt_base();
};