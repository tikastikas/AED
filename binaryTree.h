#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

template <class T> class BTree {
private:
  struct Node {
    T value;            
    Node *left, *right; 
  };

  Node *root;
  
public:

  BTree() {
    root = nullptr;
  }

  ~BTree() {
    destroy(root);
  }

  void destroy(Node *n) {
    if (n == nullptr) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  }
  
  int numberNodes() {
    return numberNodes(root);
  }   
  
  int numberNodes(Node *n) {
    if (n == nullptr) return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  int height() {
    return height(root);
  }
  
  int height(Node *n) {
    if (n == nullptr) return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }
  
  bool contains(const T & val) {
    return contains(root, val);
  }

  bool contains(Node *n, const T & val) {
    if (n == nullptr) return false;
    if (n->value == val) return true;
    return contains(n->left, val) || contains(n->right, val);
  }  

  void printPreOrder() {
    std::cout << "PreOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node *n) {
    if (n == nullptr) return;
    std::cout << " " << n->value;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  void printInOrder() {
    std::cout << "InOrder:";
    printInOrder(root);
    std::cout << std::endl;
  }

  void printInOrder(Node *n) {
    if (n == nullptr) return;
    printInOrder(n->left);
    std::cout << " " << n->value;
    printInOrder(n->right);
  }

  void printPostOrder() {
    std::cout << "PostOrder:";
    printPostOrder(root);
    std::cout << std::endl;
  }

  void printPostOrder(Node *n) {
    if (n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    std::cout << " " << n->value;
  } 

  void printBFS() {
    std::cout << "BFS:";

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *cur = q.front();
      q.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
      }
    }
    
    std::cout << std::endl;
  }

  void printDFS() {
    std::cout << "DFS:";

    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
      Node *cur = s.top();
      s.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        s.push(cur->left);
        s.push(cur->right);
      }
    }
    
    std::cout << std::endl;
  }


  void read(std::string null) {
    root = readNode(null);
  }
  
  Node *readNode(std::string null) {
    std::string buffer;
    std::cin >> buffer;
    if (buffer == null) return nullptr;
    Node *n = new Node;
    std::istringstream ss(buffer);
    ss >> n->value;
    n->left = readNode(null);
    n->right = readNode(null);    
    return n;
  }

  int numberLeafs() {
    return numberLeafs(root);
  }   
  
  int numberLeafs(Node *n) {
    int acc = 0;
    if (n->left == nullptr || n->right == nullptr) acc++;
    else return numberLeafs(n->left) + numberLeafs(n->right);
    return acc;
    }

  bool strict() {
    return strict(root);
  }

  bool strict(Node *n) {
    if (n->right != nullptr && n->left != nullptr) return strict(n->left) && strict(n->right);
    else if (n->right == nullptr && n->left == nullptr) return true;
    return false;
  }

  T & path(std::string s) {
    Node *n = root;
    if (s == "_") return n->value;
    for (char c : s) {
      if (c == 'L') n=n->left;
      else if (c == 'R') n=n->right;
    }
    return n->value;
  }

  int nodesLevel(int k) {
    return nodesLevel(k, 0, root);
  }

  int nodesLevel(int k, int depth, Node *n) {
    if (n == nullptr) return 0;
    if (depth==k) return 1;
    return nodesLevel(k, depth+1, n->left) + nodesLevel(k, depth+1, n->right);
  }

  int countEven() {
    return countEven(root);
  }

  bool isEven(int val) {
    if ((val % 2)==0) return true;
    return false;
  }

  int countEven(Node *n){
    if (n == nullptr) return 0;
    if (isEven(n->value)) return 1 + countEven(n->left) + countEven(n->right);
    return countEven(n->left) + countEven(n->right);
  }

  std::vector<int> sumLevels() {
    int h = height();
    std::vector<int> result(h+1, 0);
    sumLevels(0, root, result);
    return result;
  }
  void sumLevels(int depth, Node *n, std::vector <int>& result) {
    if (n == nullptr) return;
    result[depth] += n->value;
    sumLevels(depth + 1, n->left, result);
    sumLevels(depth + 1, n->right, result);
  }

  int sumTotal(Node *n){
    if (n == nullptr) return 0;
    return n->value + sumTotal(n->left) + sumTotal(n->right);
  }

  std::string maxSum(){
    Node *n = root;
    std::string s = "";
    while(n!=nullptr){
      if(sumTotal(n->left)>sumTotal(n->right)) {
        s+= 'L';
        n = n->left;
      } else if (sumTotal(n->left)<sumTotal(n->right)) {
        s+= 'R';
        n = n->right;
      } else {
        break;
      }
    }
    return s;
  }

};
#endif
