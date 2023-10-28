#include "BSTree.h"

#include "AVLTree.h"

#include "LinkedList.h"

#include <iostream>

#include <vector>

#include <fstream>

#include <sstream>

#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

string file_gt = "gt.txt";
string file_predict = "predict.txt";

void print_ds_menu();
void print_operation_menu();
bool perform_operation(char);

void list_struct_operator(int choice_op, LinkedList * lground, LinkedList * lpredict) {
  if (choice_op == '1') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        lground -> add_node(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Ground truth data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '2') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        lpredict -> add_node(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Prediction data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '3') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();

    lpredict -> add_node(chrom_order, pos_order, alt_base);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was added in " <<
      duration.count() << " ms" << endl;

  } else if (choice_op == '4') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    bool ifcontains = lpredict -> contains(chrom_order, pos_order, alt_base);

    auto start = high_resolution_clock::now();
    if (ifcontains == true) {
      lpredict -> remove_node(chrom_order, pos_order, alt_base);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast < milliseconds > (stop - start);
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was deleted in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be deleted because it could not be found" << endl;
    }
  } else if (choice_op == '5') {
    auto start = high_resolution_clock::now();
    lpredict -> print_list();
     auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
         cout << "Listing is done in " <<
        duration.count() << " ms" << endl;
  } else if (choice_op == '6') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();
    bool ifcontains = lpredict -> contains(chrom_order, pos_order, alt_base);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    if (ifcontains == true) {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was found in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be found" << endl;
    }
  } else {
    return;
  }
}
void avl_struct_operator(int choice_op, AVLTree * avt_gt, AVLTree * avt_predict) {
  if (choice_op == '1') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        avt_gt -> addNode(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Ground truth data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '2') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        avt_predict -> addNode(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Prediction data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '3') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();

    avt_predict -> addNode(chrom_order, pos_order, alt_base);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was added in " <<
      duration.count() << " ms" << endl;

  } else if (choice_op == '4') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    bool ifcontains = avt_predict -> contains(chrom_order, pos_order, alt_base);

    auto start = high_resolution_clock::now();
    if (ifcontains == true) {
      avt_predict -> removeNode(chrom_order, pos_order, alt_base);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast < milliseconds > (stop - start);
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was deleted in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be deleted because it could not be found" << endl;
    }
  } else if (choice_op == '5') {
    avt_predict -> inorder();
  } else if (choice_op == '6') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();
    bool ifcontains = avt_predict -> contains(chrom_order, pos_order, alt_base);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    if (ifcontains == true) {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was found in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be found" << endl;
    }
  }
  else if(choice_op == '7'){

  }
   else {
    return;
  }
}
void bst_struct_operator(int choice_op, BinSTree * bst_gt, BinSTree * bst_predict) {
  if (choice_op == '1') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        bst_gt -> add(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Ground truth data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '2') {
    auto start = high_resolution_clock::now();
    std::ifstream inFile(file_gt);
    if (!inFile.is_open()) {
      std::cout << "ERROR: The File Cannot be Opened" << std::endl;
      return;
    }

    std::string line;
    std::getline(inFile, line); // Skip the header line
    int lineCount = 0;

    while (std::getline(inFile, line)) {
      lineCount++;
      std::istringstream iss(line);
      int chrom, pos;
      char altBase;

      if (iss >> chrom >> pos >> altBase) {
        bst_predict -> add(chrom, pos, altBase);
      } else {
        std::cout << "ERROR: Invalid line format at line " << lineCount << ": " << line << std::endl;
        inFile.close();
        return;
      }
    }

    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << "Prediction data structure was created from file in: " <<
      duration.count() << " ms" << endl;
  } else if (choice_op == '3') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();

    bst_predict -> add(chrom_order, pos_order, alt_base);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was added in " <<
      duration.count() << " ms" << endl;

  } else if (choice_op == '4') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    bool ifcontains = bst_predict -> contains(chrom_order, pos_order, alt_base);

    auto start = high_resolution_clock::now();
    if (ifcontains == true) {
      bst_predict -> remove(chrom_order, pos_order, alt_base);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast < milliseconds > (stop - start);
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was deleted in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be deleted because it could not be found" << endl;
    }
  } else if (choice_op == '5') {
    bst_predict -> printInOrder();
  } else if (choice_op == '6') {
    cout << "Enter the CHROM POS and ALT BASE information with a space in between: ";
    int chrom_order, pos_order;
    char alt_base;
    cin >> chrom_order >> pos_order >> alt_base;
    auto start = high_resolution_clock::now();
    bool ifcontains = bst_predict -> contains(chrom_order, pos_order, alt_base);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast < milliseconds > (stop - start);
    if (ifcontains == true) {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "was found in " <<
        duration.count() << " ms" << endl;
    } else {
      cout << chrom_order << " " << pos_order << " " << alt_base << " " << "could not be found" << endl;
    }
  } else {
    return;
  }
}

int main() {
  bool end = false;
  char choice_ds, choice_op;

  print_ds_menu();
  cin >> choice_ds;

  if (choice_ds == '1') //Binary Search Tree Selection
  {
    BinSTree * bst_gt = new BinSTree();
    BinSTree * bst_predict = new BinSTree();
    while (!end) {
      print_operation_menu();
      cin >> choice_op;
      if (choice_op == '0') {
        break;
      }
      bst_struct_operator(choice_op, bst_gt, bst_predict);
    }

  } else if (choice_ds == '2') //AVL Tree Selection
  {
    AVLTree * avt_gt = new AVLTree();
    AVLTree * avt_predict = new AVLTree();
    while (!end) {
      print_operation_menu();
      cin >> choice_op;
      if (choice_op == '0') {
        break;
      }
      avl_struct_operator(choice_op, avt_gt, avt_predict);
    }
  } else if (choice_ds == '3') //Linked List Selection
  {
    LinkedList * lground = new LinkedList();
    LinkedList * lpredict = new LinkedList();
    while (!end) {
      print_operation_menu();
      cin >> choice_op;
      if (choice_op == '0') {
        break;
      }
      list_struct_operator(choice_op, lground, lpredict);
    }
  } else {
    cout << "Error: You have entered an invalid choice" << endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void print_ds_menu() {
  cout << "Choose a data structure" << endl;
  cout << "1: Binary Search Tree" << endl;
  cout << "2: AVL Tree" << endl;
  cout << "3: Unsorted Singly Linked List" << endl;
  cout << "Enter a choice {1,2,3}:";
}

void print_operation_menu() {
  cout << "Choose an operation" << endl;
  cout << "1: Create ground truth data structure from file" << endl;
  cout << "2: Create prediction data structure from file" << endl;
  cout << "3: Add a variant prediction" << endl;
  cout << "4: Delete a variant prediction" << endl;
  cout << "5: List predictions" << endl;
  cout << "6: Search a prediction variant from predictions" << endl;
  cout << "7: Calculate true positive variant count" << endl;
  cout << "0: Exit" << endl;
  cout << "Enter a choice {1,2,3,4,5,6,7,0}:";
}