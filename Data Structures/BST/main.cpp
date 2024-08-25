#include <iostream>
#include "bst.h"

int main() {
    
    BST<int> tree;

    // Test adding elements
    std::cout << "Adding elements to the BST:\n";
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(18);

    // Test inorder traversal (should print sorted order)
    std::cout << "Inorder traversal: ";
    tree.inorderTraverse();
    std::cout << "\n";

    // Test height of the tree
    std::cout << "Height of the tree: " << tree.getHeight() << "\n";

    // Test number of nodes
    std::cout << "Number of nodes: " << tree.getNumberOfNodes() << "\n";

    // Test get root data
    std::cout << "Root data: " << tree.getRootData() << "\n";

    // Test contains function
    std::cout << "Tree contains 7: " << tree.contains(7) << "\n";
    std::cout << "Tree contains 20: " << tree.contains(20) << "\n";

    // Test remove function
    std::cout << "Removing 10 from the BST:\n";
    tree.remove(10);
    std::cout << "Inorder traversal after removing 10: ";
    tree.inorderTraverse();
    std::cout << "\n";

    // Test iterative traversals
    std::cout << "Iterative inorder traversal: ";
    tree.inorderTraverse_i();
    std::cout << "\n";

    std::cout << "Iterative preorder traversal: ";
    tree.preorderTraverse_i();
    std::cout << "\n";

    std::cout << "Iterative postorder traversal: ";
    tree.postorderTraverse_i();
    std::cout << "\n";

    std::cout << "Iterative reverse inorder traversal: ";
    tree.rev_inorderTraverse_i();
    std::cout << "\n";

    std::cout << "Level order traversal: ";
    tree.levelorder_i();
    std::cout << "\n";

    // Test recursive traversals
    std::cout << "Recursive inorder traversal: ";
    tree.inorderTraverse();
    std::cout << "\n";

    std::cout << "Recursive preorder traversal: ";
    tree.preorderTraverse_r();
    std::cout << "\n";

    std::cout << "Recursive postorder traversal: ";
    tree.postorderTraverse_r();
    std::cout << "\n";

    std::cout << "Recursive reverse inorder traversal: ";
    tree.rev_inorderTraverse_r();
    std::cout << "\n";

    std::cout << "Level order traversal (recursive): ";
    tree.levelorder_r();
    std::cout << "\n";

    // Test clearing the tree
    std::cout << "Clearing the BST:\n";
    tree.clear();
    std::cout << "Inorder traversal after clearing: ";
    tree.inorderTraverse();
    std::cout << "\n";

    return 0;
}
