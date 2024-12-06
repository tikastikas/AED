#include <iostream>
#include <string>

#include "singlyLinkedList.h"

// Read n and then n elements to add to the list using addFirst, followed by
// Read q and then q queries pos val to call insert(pos,val)
template <typename T>
void read() {
  int n;
  std::cin >> n;
  SinglyLinkedList<T> lst;
  for (int i=0; i<n; i++) {
    T v;
    std::cin >> v;
    lst.addFirst(v);
  }
  std::cout << "lst = " << lst.toString() << " | size = " << lst.size() << std::endl;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    int pos;
    T v;
    std::cin >> pos >> v;
    std::cout << "lst.insert(" << pos << "," << v << ")" << std::endl;
    lst.insert(pos, v);
    std::cout << "lst = " << lst.toString() << " | size = " << lst.size() << std::endl;
  }
  std::cout << "-------------------------" << std::endl;
}

int main() {

  int n;
  std::cin >> n;
  for (int i=0; i<n; i++) {
    std::string type;
    std::cin >> type;
    if (type == "int") read<int>();
    else if (type == "char") read<char>();
    else if (type == "string") read<std::string>();
  }
  
  return 0;
}