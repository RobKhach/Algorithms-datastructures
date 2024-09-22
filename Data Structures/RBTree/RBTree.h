#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>



#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&node) {
        Node *right_child = node->right;
        node->right = right_child->left;

        if (node->right != nullptr) {
            node->right->parent = node;
        }

        right_child->parent = node->parent;

        if (node->parent == nullptr) {
            root = right_child;
        } else if (node == node->parent->left) {
            node->parent->left = right_child;
        } else {
            node->parent->right = right_child;
        }

        right_child->left = node;
        node->parent = right_child;
    }

    void rotateRight(Node *&node) {
        Node *left_child = node->left;
        node->left = left_child->right;

        if (node->left != nullptr) {
            node->left->parent = node;
        }

        left_child->parent = node->parent;

        if (node->parent == nullptr) {
            root = left_child;
        } else if (node == node->parent->left) {
            node->parent->left = left_child;
        } else {
            node->parent->right = left_child;
        }

        left_child->right = node;
        node->parent = left_child;
    }

    void fixInsert(Node *&node) {
        Node *parent = nullptr;
        Node *grandparent = nullptr;

        while (node != root && node->color != BLACK && node->parent->color == RED) {
            parent = node->parent;
            grandparent = node->parent->parent;

            if (parent == grandparent->left) {
                Node *uncle = grandparent->right;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else {
                Node *uncle = grandparent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void fixDelete(Node *&node) {
        if (node == nullptr) return;

        if (node == root) {
            root = nullptr;
            return;
        }

        if (node->color == RED || (node->left != nullptr && node->left->color == RED) || (node->right != nullptr && node->right->color == RED)) {
            Node *child = node->left != nullptr ? node->left : node->right;

            if (node == node->parent->left) {
                node->parent->left = child;
                if (child != nullptr) child->parent = node->parent;
                child->color = BLACK;
                delete (node);
            } else {
                node->parent->right = child;
                if (child != nullptr) child->parent = node->parent;
                child->color = BLACK;
                delete (node);
            }
        } else {
            Node *sibling = nullptr;
            Node *parent = nullptr;
            Node *ptr = node;
            ptr->color = BLACK;
            while (ptr != root && ptr->color == BLACK) {
                parent = ptr->parent;
                if (ptr == parent->left) {
                    sibling = parent->right;
                    if (sibling->color == RED) {
                        sibling->color = BLACK;
                        parent->color = RED;
                        rotateLeft(parent);
                    } else {
                        if ((sibling->left != nullptr && sibling->left->color == BLACK) && (sibling->right != nullptr && sibling->right->color == BLACK)) {
                            sibling->color = RED;
                            if (parent->color == RED) {
                                parent->color = BLACK;
                            } else {
                                parent->color = BLACK;
                            }
                            ptr = parent;
                        } else {
                            if (sibling->right != nullptr && sibling->right->color == BLACK) {
                                sibling->left->color = BLACK;
                                sibling->color = RED;
                                rotateRight(sibling);
                                sibling = parent->right;
                            }
                            sibling->color = parent->color;
                            parent->color = BLACK;
                            sibling->right->color = BLACK;
                            rotateLeft(parent);
                            break;
                        }
                    }
                } else {
                    sibling = parent->left;
                    if (sibling->color == RED) {
                        sibling->color = BLACK;
                        parent->color = RED;
                        rotateRight(parent);
                    } else {
                        if ((sibling->left != nullptr && sibling->left->color == BLACK) && (sibling->right != nullptr && sibling->right->color == BLACK)) {
                            sibling->color = RED;
                            if (parent->color == RED) {
                                parent->color = BLACK;
                            } else {
                                parent->color = BLACK;
                            }
                            ptr = parent;
                        } else {
                            if (sibling->left != nullptr && sibling->left->color == BLACK) {
                                sibling->right->color = BLACK;
                                sibling->color = RED;
                                rotateLeft(sibling);
                                sibling = parent->left;
                            }
                            sibling->color = parent->color;
                            parent->color = BLACK;
                            sibling->left->color = BLACK;
                            rotateRight(parent);
                            break;
                        }
                    }
                }
            }
            if (node == node->parent->left) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }
            delete (node);
            root->color = BLACK;
        }
    }

    Node* BSTInsert(Node* root, Node *node) {
        if (root == nullptr) return node;

        if (node->data < root->data) {
            root->left = BSTInsert(root->left, node);
            root->left->parent = root;
        } else if (node->data > root->data) {
            root->right = BSTInsert(root->right, node);
            root->right->parent = root;
        }

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* ptr = node;
        while (ptr->left != nullptr) ptr = ptr->left;
        return ptr;
    }

    void inorderHelper(Node* root) {
        if (root == nullptr) return;

        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    RedBlackTree() { root = nullptr; }

    void insert(const int &data) {
        Node *node = new Node(data);
        root = BSTInsert(root, node);
        fixInsert(node);
    }

    void deleteNode(int data) {
        Node* node = searchTreeHelper(this->root, data);
        if (node != nullptr) {
            fixDelete(node);
        }
    }

    Node* searchTreeHelper(Node* node, int key) {
        if (node == nullptr || key == node->data) {
            return node;
        }
        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    Node* search(int data) {
        return searchTreeHelper(root, data);
    }

    int findMin() {
        return minValueNode(root)->data;
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};

// Example usage


#endif