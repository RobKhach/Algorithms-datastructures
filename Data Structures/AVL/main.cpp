#include <iostream>
#include "AVL_Tree.hpp"

int main() {
    // Test default constructor
    AVLTree<int> tree1;
    tree1.insert(30);
    tree1.insert(20);
    tree1.insert(40);
    tree1.insert(10);
    tree1.insert(25);
    tree1.insert(35);
    tree1.insert(50);

    std::cout << "In-order traversal of tree1 (default constructor and insert): ";
    tree1.inorder();
    std::cout << std::endl;

    // Test constructor with an initial value
    AVLTree<int> tree2(15);
    tree2.insert(10);
    tree2.insert(20);

    std::cout << "In-order traversal of tree2 (constructor with initial value): ";
    tree2.inorder();
    std::cout << std::endl;

    // Test initializer list constructor
    AVLTree<int> tree3 = {5, 10, 15, 20, 25};
    std::cout << "In-order traversal of tree3 (initializer list constructor): ";
    tree3.inorder();
    std::cout << std::endl;

    // Test variadic constructor
    AVLTree<int> tree4(45, 55, 35, 65, 25);
    std::cout << "In-order traversal of tree4 (variadic constructor): ";
    tree4.inorder();
    std::cout << std::endl;

    // Test copy constructor
    AVLTree<int> tree5(tree3);
    std::cout << "In-order traversal of tree5 (copy of tree3): ";
    tree5.inorder();
    std::cout << std::endl;

    // Test move constructor
    AVLTree<int> tree6(std::move(tree4));
    std::cout << "In-order traversal of tree6 (moved from tree4): ";
    tree6.inorder();
    std::cout << std::endl;
    std::cout << "Is tree4 empty after move? " << (tree4.isEmpty() ? "Yes" : "No") << std::endl;

    // Test assignment operator (copy)
    AVLTree<int> tree7;
    tree7 = tree1;
    std::cout << "In-order traversal of tree7 (assigned from tree1): ";
    tree7.inorder();
    std::cout << std::endl;

    // Test assignment operator (move)
    AVLTree<int> tree8;
    tree8 = std::move(tree2);
    std::cout << "In-order traversal of tree8 (moved from tree2): ";
    tree8.inorder();
    std::cout << std::endl;
    std::cout << "Is tree2 empty after move? " << (tree2.isEmpty() ? "Yes" : "No") << std::endl;

    // Test search
    std::cout << "Searching for 25 in tree7: " << (tree7.search(25) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 60 in tree7: " << (tree7.search(60) ? "Found" : "Not Found") << std::endl;

    // Test minVal and maxVal
    try {
        std::cout << "Minimum value in tree7: " << tree7.minVal() << std::endl;
        std::cout << "Maximum value in tree7: " << tree7.maxVal() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test removal of nodes
    tree7.remove(25);  // Node with one child
    std::cout << "In-order traversal of tree7 after removing 25: ";
    tree7.inorder();
    std::cout << std::endl;

    tree7.remove(30);  // Node with two children
    std::cout << "In-order traversal of tree7 after removing 30: ";
    tree7.inorder();
    std::cout << std::endl;

    tree7.remove(10);  // Leaf node
    std::cout << "In-order traversal of tree7 after removing 10: ";
    tree7.inorder();
    std::cout << std::endl;

    // Test clear and isEmpty
    tree7.clear();
    std::cout << "Tree7 cleared. Is tree7 empty? " << (tree7.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "TEST FOR DIFFERENT TYPES\n";

     std::cout << "Testing with int type:" << std::endl;
    AVLTree<int> intTree = {30, 20, 40, 10, 25, 35, 50};
    intTree.inorder(); std::cout << std::endl;

    intTree.insert(45);
    intTree.remove(20);
    intTree.inorder(); std::cout << std::endl;

    std::cout << "Min: " << intTree.minVal() << ", Max: " << intTree.maxVal() << std::endl;

    // Test for float
    std::cout << "Testing with float type:" << std::endl;
    AVLTree<float> floatTree = {30.5f, 20.2f, 40.1f, 10.7f, 25.3f, 35.6f, 50.8f};
    floatTree.inorder(); std::cout << std::endl;

    floatTree.insert(45.9f);
    floatTree.remove(20.2f);
    floatTree.inorder(); std::cout << std::endl;

    std::cout << "Min: " << floatTree.minVal() << ", Max: " << floatTree.maxVal() << std::endl;

    // Test for double
    std::cout << "Testing with double type:" << std::endl;
    AVLTree<double> doubleTree = {30.55, 20.25, 40.15, 10.75, 25.35, 35.65, 50.85};
    doubleTree.inorder(); std::cout << std::endl;

    doubleTree.insert(45.95);
    doubleTree.remove(20.25);
    doubleTree.inorder(); std::cout << std::endl;

    std::cout << "Min: " << doubleTree.minVal() << ", Max: " << doubleTree.maxVal() << std::endl;

    // Test for char
    std::cout << "Testing with char type:" << std::endl;
    AVLTree<char> charTree = {'g', 'b', 'k', 'a', 'd', 'h', 'm'};
    charTree.inorder(); std::cout << std::endl;

    charTree.insert('i');
    charTree.remove('b');
    charTree.inorder(); std::cout << std::endl;

    std::cout << "Min: " << charTree.minVal() << ", Max: " << charTree.maxVal() << std::endl;

    // Test clear and isEmpty for all types
    std::cout << "Clearing all trees:" << std::endl;
    intTree.clear();
    floatTree.clear();
    doubleTree.clear();
    charTree.clear();

    std::cout << "Is intTree empty? " << (intTree.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is floatTree empty? " << (floatTree.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is doubleTree empty? " << (doubleTree.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is charTree empty? " << (charTree.isEmpty() ? "Yes" : "No") << std::endl;


    return 0;
}
