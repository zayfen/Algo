#ifndef _TREE_TRAVEL_HPP__
#define _TREE_TRAVEL_HPP__

#include <queue>
#include <vector>

#include "../_common_models/common.hpp"

namespace Algo {
  using Algo::Node;


  /**
   * 广度优先遍历二叉树
   *
   */
  template<typename T>
  const std::vector< Node<T>* >&  breadthFirstTravel(Node<T>* root) {
    using Queue = std::queue< Node<T>* >;
    using Vector = std::vector< Node<T>* >;

    // if (root == nullptr) {
    //   return nullptr;
    // }

    Vector* result = new Vector();
    Queue queue;
    if (root == nullptr) {
      return *result;
    }
    
    queue.push(root);
    while (!queue.empty()) {
      Node<T>* node = queue.front();
      result->push_back(node);
      queue.pop();
      if (node->left) {
        queue.push(node->left);
      }
      if (node->right) {
        queue.push(node->right);
      }
    }
    return *result;
  }


}

#endif //
