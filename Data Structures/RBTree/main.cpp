#include <iostream>
#include "RBTree.h"  // Include the header file

using namespace std;

int main() {
    // Create a Red-Black Tree instance
    RedBlackTree tree;

    // Insert nodes into the tree
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    // Print in-order traversal of the tree
    cout << "Inorder traversal of the Red-Black Tree: ";
    tree.inorder();

    // Search for a node
    int searchValue = 10;
    Node* searchResult = tree.search(searchValue);
    if (searchResult != nullptr) {
        cout << "Node with value " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Node with value " << searchValue << " not found in the tree." << endl;
    }

    // Find minimum value in the tree
    cout << "Minimum value in the Red-Black Tree: " << tree.findMin() << endl;

    // Delete a node from the tree
    int deleteValue = 18;
    cout << "Deleting node with value " << deleteValue << " from the Red-Black Tree." << endl;
    tree.deleteNode(deleteValue);

    // Print in-order traversal after deletion
    cout << "Inorder traversal after deleting " << deleteValue << ": ";
    tree.inorder();

    return 0;
}
