/**
 * 二叉树的先序遍历
 **/

#include <stack>
#include <vector>
#include <iostream>

#include "../_common_models/common.hpp"

using namespace Algo;

namespace Algo {

  namespace Tree {
    std::vector<Node<int>*> pre_order_traversal (Node<int>* treeRoot) {
      std::stack< Node<int>* > stack;
      std::vector< Node<int>* > vec;

      if (treeRoot != nullptr) {
        stack.push(treeRoot);
      }

      while (!stack.empty()) {
        std::cout << "stack size: " << stack.size() << std::endl;

        // get top element, and save it to vector
        Node<int>* node = stack.top();
        vec.push_back(node);
        std::cout << "node: " << node->value << std::endl;

        // pop top node
        stack.pop();

        // push right-node of node
        if (node->right != nullptr) {
          stack.push(node->right);
        }

        // push left-node of node
        if (node->left != nullptr) {
          stack.push(node->left);
        }

      } //

      return vec;
    }


  } // namespace tree

} // namespace Algo


// test code

int main (void) {
  // build tree

  Node<int>* root = new Node<int>(10);
  root->left = new Node<int>(20);
  root->left->left = new Node<int>(30);
  root->left->right = new Node<int>(40);
  root->left->right->left = new Node<int>(50);
  root->left->right->right = new Node<int>(60);

  root->right = new Node<int>(70);
  root->right->right = new Node<int>(80);
  root->right->right->left = new Node<int>(90);
  std::cout << "tree built" << std::endl;

  auto vec = Algo::Tree::pre_order_traversal(root);
  std::cout << "vector got" << std::endl;
  for (auto node : vec) {
    std::cout << node->value << " ";
  }

  // mirror tree
  for (auto node : vec) {
    Node<int>* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
  }

  auto vec2 = Algo::Tree::pre_order_traversal(root);
  std::cout << "vector2 got" << std::endl;
  for (auto node : vec2) {
    std::cout << node->value << " ";
  }

}
