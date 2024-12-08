#include <iostream>
#include <string>

#include "binaryTree.h"

// Read a tree of type t assuming "N" as the null value
// read n paths and call t.path() for each one of them
template <typename T>
void read() {
  BTree<T> t;
  t.read("N");

  int n;
  std::cin >> n;
  for (int i = 0; i<n; i++) {
    int k;
    std::cin >> k;
    std::cout << "t.nodesLevel(" << k << ") = " << t.nodesLevel(k) << std::endl;
  }
}

int main() {

  std::string type;
  std::cin >> type;
  if (type == "int") read<int>();
  else if (type == "string") read<std::string>();
  
  return 0;
}