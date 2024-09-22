#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTree.h"

template <typename T>
TreeNode<T>::TreeNode(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}


template <typename T>
RBTree<T>::RBTree(){
    nil = new TreeNode<T>(0);
    nil->color = BLACK;
    root = nil;
}
template <typename T>
void RBTree<T>::clear(TreeNode* current){
    if(current == nullptr){
        return;
    }

    clear(current->left);
    clear(current->right);
    delete current;

}

template <typename T>
RBTree<T>::~RBTree(){
    clear(root);
    delete nil;
}

#endif