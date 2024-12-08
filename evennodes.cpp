#include <iostream>
#include <string>

#include "binaryTree.h"

// Read a tree of ints assuming "N" as the null value
// call t.countEven() method and write its output
void read() {
  BTree<int> t;
  t.read("N");

  std::cout << "t.countEven() = " << t.countEven() << std::endl;
}

int main() {

  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) read();
  
  return 0;
}