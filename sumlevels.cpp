#include <iostream>
#include <string>
#include <vector>

#include "binaryTree.h"

// Read a tree of ints assuming "N" as the null value
// call t.sumLevels() method and write its output
void read() {
  BTree<int> t;
  t.read("N");

  std::cout << "t.sumLevels() = {";
  std::vector<int> sum = t.sumLevels();
  for (int i=0; i<(int)sum.size(); i++) {
    if (i>0) std::cout << ",";
    std::cout << sum[i];
  }
  std::cout << "}" << std::endl;
}

int main() {

  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) read();
  
  return 0;
}