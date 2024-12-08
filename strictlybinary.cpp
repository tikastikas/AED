#include <iostream>
#include <string>

#include "binaryTree.h"

// Read a tree of type t assuming "N" as the null value
// call t.strict() method and write its output
template <typename T>
void read() {
  BTree<T> t;
  t.read("N");

  std::cout << "t.strict() = " << (t.strict()?"true":"false") << std::endl;
}

int main() {

  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    std::string type;
    std::cin >> type;
    if (type == "int") read<int>();
    else if (type == "string") read<std::string>();
  }
  
  return 0;
}