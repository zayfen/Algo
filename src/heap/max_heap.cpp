
#include <iostream>
#include <string>
#include "../_common_models/common.hpp"
#include "../_utils/tree_travel.hpp"

namespace Algo {
  using Algo::Node;
  
  template<typename T>
  class MaxHeap {
  public:
    MaxHeap() {
      root = nullptr;
      nodeToInsert = root;
    }


    MaxHeap(T root) {
      initRoot(&root);
    }

  
    void insert(T* node) {
      if (root == nullptr) {
        initRoot(node);
        return;
      }

      Node<T>* swimNode = nullptr;
      nodeToInsert = findNodeToInsert();
      if (!nodeToInsert->left) {
        nodeToInsert->left = new Node<T>(*node);
        nodeToInsert->left->setParent(nodeToInsert);
        swimNode = nodeToInsert->left;
      } else if (!nodeToInsert->right) {
        nodeToInsert->right = new Node<T>(*node);
        nodeToInsert->right->setParent(nodeToInsert);
        swimNode = nodeToInsert->right;
      }
      swim(swimNode);
    }

    

    T* getRoot() {
      return &root->value;
    }

    Node<T>* getRootNode() {
      return root;
    }

    T* deleteRoot() {
      
    }
  
  private:
    void initRoot(T* node) {
      if (root == nullptr) {
        root = new Node<T>(*node);
        nodeToInsert = root;
      }
    }

    Node<T>* findNodeToInsert(void) {
      const std::vector< Node<int>* > &vec =  Algo::breadthFirstTravel<int>(root);
      for (auto i : vec) {
        if (i->left && i->right) {
          continue;
        }
        nodeToInsert = i;
        break;
      }
      return nodeToInsert;
    }

    void swim(Node<T>* node) {
      Node<T>* stepNode = node;
      while (stepNode &&
             stepNode->parent &&
             ((stepNode->value) > (stepNode->parent->value))) {

        stepNode = switchNodes(stepNode, stepNode->parent);
      }
    }

    Node<T>* switchNodes (Node<T>* childNode, Node<T>* parentNode) {
      if (childNode->parent != parentNode) {
        std::cerr << "childNode is not real child of parentNode" << std::endl;
        return nullptr;
      }

      T val = childNode->value;
      childNode->value = parentNode->value;
      parentNode->value = val;
      return parentNode;
    }

    virtual ~MaxHeap() {
      
    }

  private:
    Node<T>* root;
    Node<T>* nodeToInsert;
  };
  
}

int main(void) {
  Algo::MaxHeap<int>* mh = new Algo::MaxHeap<int>(10);
  std::cout << "root value is " << *mh->getRoot() << std::endl;

  int a = 110;
  mh->insert(&a);
  std::cout << "root value is " << *mh->getRoot() << std::endl;

  int b = 100;
  mh->insert(&b);
  std::cout << "root value is " << *mh->getRoot() << std::endl;

  using Algo::Node;
  const std::vector< Node<int>* > &vec = Algo::breadthFirstTravel<int>(mh->getRootNode());

  for (auto i : vec) {
    std::cout << i->value << "  ";
  }

  return 0;
}

