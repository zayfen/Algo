#ifndef _COMMON_HPP__
#define _COMMON_HPP__

namespace Algo {
  template<typename T>
  struct Node {
    // methods
    Node(T value) {
      this->value = value;
      this->left = nullptr;
      this->right = nullptr;
      this->parent = nullptr;
    }

    void setLeft(Node<T>* left) {
      this->left = left;
    }

    void setRight(Node<T>* right) {
      this->right = right;
    }

    void setParent(Node<T>* parent) {
      this->parent = parent;
    }
    
    // fields
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
  };
	
}


#endif // __COMMON_HPP__
