
#include <string>
#include <cassert>
#include <iostream>
#include <stdexcept>

#include "../_common_models/common.hpp"
#include "../_utils/tree_travel.hpp"


namespace Algo::Heap {
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
      size++;
    }

    

    T* getRoot() {
      return &root->value;
    }

    Node<T>* getRootNode() {
      return root;
    }

    T deleteRoot() {
      Node<T>* firstUnfilledNode = Algo::Utils::findBreadthFirstUnfilledNode<int>(root);
      if (firstUnfilledNode == nullptr) {
        throw std::runtime_error("No root");
      }

      Node<T>* leftNode = firstUnfilledNode;
      if (leftNode->left) { // due to unfillednode, so leftNode->right must be nullptr
        leftNode = leftNode->left;
      }

      T ret = root->value;

      // make leftNode parent pointer be nullptr
      Node<T>* p = leftNode->parent;
      if (p->left == leftNode) {
        p->left = nullptr;
      }
      if (p->right == leftNode) {
        p->right = nullptr;
      }
      leftNode->parent = nullptr;

      // 将leftNode的内容切换到root节点
      switchNodes(leftNode, root);
      // 先在leftNode中存放的是旧的rootNode中的值，所以delete it
      delete leftNode;

      size--;

      // 下沉root节点，重新使堆有序
      sink(root);

      return ret;
    }

    int getSize() {
      assert((size >= 0));
      return size;
    }

    bool empty() {
      assert((size >= 0));
      return size == 0;
    }

  private:
    void initRoot(T* node) {
      if (root == nullptr) {
        root = new Node<T>(*node);
        nodeToInsert = root;
        size ++;
      }
    }

    Node<T>* findNodeToInsert(void) {
      // here is a better way to find a node to insert child nodes
      Node<int>* n = Algo::Utils::findBreadthFirstUnfilledNode<int>(root);
      return n;
    }

    void swim(Node<T>* node) {
      Node<T>* stepNode = node;
      while (stepNode &&
             stepNode->parent &&
             ((stepNode->value) > (stepNode->parent->value))) {

        switchNodes(stepNode, stepNode->parent);
        stepNode = stepNode->parent;
      }
    }

    /**
     * 下沉节点
     *
     */
    void sink(Node<T>* node) {
      Node<T>* stepNode = node;
      Node<T>* maxChildNode = getMaxChildNode(stepNode);
      
      // this means both two childrend nodes of node is nullptr
      if (maxChildNode == nullptr) { 
        return;
      }

      while (stepNode && maxChildNode && stepNode->value < maxChildNode->value) {
        switchNodes(maxChildNode, stepNode);
        stepNode = maxChildNode;
        maxChildNode = getMaxChildNode(stepNode);
      }
    }


    Node<T>* getMaxChildNode(Node<T>* node) const {
      if (node == nullptr) {
        return nullptr;
      }
      Node<T>* maxChildNode = node->left;
      if (maxChildNode == nullptr || 
          (node->right && node->right->value > maxChildNode->value)) {
        if (node->right) {
          maxChildNode = node->right;
        }
      }
      return maxChildNode;
    }

    // 改变两个列表中的内容
    void switchNodes (Node<T>* childNode, Node<T>* parentNode) {
      
      T val = childNode->value;
      childNode->value = parentNode->value;
      parentNode->value = val;
    }

    virtual ~MaxHeap() {
      if (root) {
        delete root;
        root = nullptr;
        nodeToInsert = nullptr;
      }
    }

  private:
    Node<T>* root;
    Node<T>* nodeToInsert;
    int size = 0;
  };
  
}


// for test
int main(void) {
  Algo::Heap::MaxHeap<int>* mh = new Algo::Heap::MaxHeap<int>(10);
  std::cout << "root value is " << *mh->getRoot() << "  size is : " << mh->getSize() << std::endl;

  int a = 110;
  mh->insert(&a);
  std::cout << "root value is " << *mh->getRoot() << "  size is : " << mh->getSize() << std::endl;

  int b = 100;
  mh->insert(&b);
  std::cout << "root value is " << *mh->getRoot() << "  size is : " << mh->getSize() << std::endl;

  using Algo::Node;
  const std::vector< Node<int>* > &vec = Algo::Utils::breadthFirstTravel<int>(mh->getRootNode());

  for (auto i : vec) {
    std::cout << i->value << "  ";
  }

  // test delete
  int deletedValue = mh->deleteRoot();
  std::cout << "deletedValue is " << deletedValue << std::endl;
  std::cout << "root value is " << *mh->getRoot() << std::endl;
  std::cout << "root value is " << *mh->getRoot() << "  size is : " << mh->getSize() << std::endl;
  
  return 0;
}

