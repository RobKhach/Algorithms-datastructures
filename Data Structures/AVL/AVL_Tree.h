#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <concepts>
#include <type_traits>
#include <iostream>

template <typename T, typename U>
concept SameAs = std::is_same_v<T, U>;

template <typename T, typename... Args>
concept AllSameAs = (SameAs<T, Args> && ...);


template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

template <arithmetic T>
class AVLTree{
    private:

        struct TreeNode{
            TreeNode* left;
            TreeNode* right;
            T value;
            int height;
            TreeNode(T val);
        };

    private:

        TreeNode* root;

    private:

        void copyTree(TreeNode* node);
        int getHeight(TreeNode* node) const;
        int getBalance(TreeNode* node) const;
        TreeNode* rightRotate(TreeNode* y);
        TreeNode* leftRotate(TreeNode* x);
        TreeNode* insert(TreeNode* node, const T& val);
        TreeNode* deleteNode(TreeNode* node, const T& val);
        TreeNode* minValueNode(TreeNode* node) const;
        TreeNode* maxValueNode(TreeNode* node) const;
        void inOrderTraverse(TreeNode* node) const;
        void preOrderTraverse(TreeNode* node) const;
        void postOrderTraverse(TreeNode* node) const;
        TreeNode* search(TreeNode* node, const T& val) const;
        void destroy(TreeNode* node);

    public:

        AVLTree();
        AVLTree(const AVLTree& other);
        AVLTree(AVLTree&& other);
        AVLTree(T val);
        AVLTree(std::initializer_list<T> list);
        template <AllSameAs<T>... Args>
        AVLTree(Args... args);
        ~AVLTree();

    public:

        AVLTree& operator=(const AVLTree& other);
        AVLTree& operator=(AVLTree&& other);
    
    public:

        int getHeight() const;
        int getBalance() const;
        void insert(const T& val);
        void remove(const T& val);
        bool search(const T& val) const;
        T minVal() const;
        T maxVal() const;
        void inorder() const;
        void postorder() const;
        void preorder() const;
        bool isEmpty() const;
        void clear();

};

#endif
