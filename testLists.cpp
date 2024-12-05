// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Example of how to use a the SinglyLinkedList<T> class
// Last update: 20/10/2024
// -------------------------------------------------------------

#include <iostream>

#include "singlyLinkedList.h"

template <typename T>
void print(SinglyLinkedList<T> & lst){
  std::cout << lst.toString() << std::endl;
}
  

int main(){
  // Create a list of integers
  SinglyLinkedList<int> list;

  // writing the list (at the start it is empty)
  print(list);

  // Checking whether it is empty
  std::cout << "isEmpty? " << list.isEmpty() << std::endl;
      
  // insert the numbers 1 to 5 at the end
  for (int i=1; i<=5; i++)
         list.addLast(i);  
  print(list);

  // insert the numbers 6 to 10 at the front of the list
  for (int i=6; i<=10; i++)
    list.addFirst(i);
  print(list);

  // checking the size of the list
  std::cout << "size = " <<  list.size() << std::endl;

  // Removing the first element
  list.removeFirst();
  print(list);

  // Removing the last element
  list.removeLast();
  print(list);

  // Checking whether it is empty
  std::cout << "isEmpty? " << list.isEmpty() << std::endl;

  // Writing the first and the last elements
  std::cout << "getFirst() = " << list.getFirst() << std::endl;
  std::cout << "getLast() = " <<  list.getLast() << std::endl;

  return 0;
}
