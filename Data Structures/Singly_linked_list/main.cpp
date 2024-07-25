#include <iostream>
#include "singly_list.h"

int main() {
    Slist<int> list;

    // Test push_front
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    std::cout << "After push_front: ";
    list.print_list();  // Expected: 30 20 10
    std::cout << std::endl;

    // Test pop_front
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print_list();  // Expected: 20 10
    std::cout << std::endl;

    // Test insert_after
    Node<int>* first_node = list.front();
    list.insert_after(first_node, 15);
    std::cout << "After insert_after: ";
    list.print_list();  // Expected: 20 15 10
    std::cout << std::endl;

    // Test erase_after
    list.erase_after(first_node);
    std::cout << "After erase_after: ";
    list.print_list();  // Expected: 20 10
    std::cout << std::endl;

    // Test clear
    list.clear();
    std::cout << "After clear: ";
    list.print_list();  // Expected: (empty)
    std::cout << std::endl;

    // Test isEmpty
    std::cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;  // Expected: Yes

    // Test front
    list.push_front(5);
    std::cout << "Front element: " << list.front()->data << std::endl;  // Expected: 5

    // Test reverse
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    std::cout << "Before reverse: ";
    list.print_list();  // Expected: 30 20 10 5
    std::cout << std::endl;
    list.reverse();
    std::cout << "After reverse: ";
    list.print_list();  // Expected: 5 10 20 30
    std::cout << std::endl;

    // Test merge
    Slist<int> other_list;
    other_list.push_front(100);
    other_list.push_front(200);
    std::cout << "Other list before merge: ";
    other_list.print_list();  // Expected: 200 100
    std::cout << std::endl;
    list.merge(other_list);
    std::cout << "After merge: ";
    list.print_list();  // Expected: 5 10 20 30 200 100
    std::cout << std::endl;

    // Test sort
    list.push_front(25);
    list.push_front(15);
    list.push_front(35);
    std::cout << "Before sort: ";
    list.print_list();  // Expected: 35 15 25 5 10 20 30 200 100
    std::cout << std::endl;
    list.sort();
    std::cout << "After sort: ";
    list.print_list();  // Expected: 5 10 15 20 25 30 35 100 200
    std::cout << std::endl;

    // Test search
    std::cout << "Searching for 25: " << (list.search(25) ? "Found" : "Not Found") << std::endl;  // Expected: Found
    std::cout << "Searching for 300: " << (list.search(300) ? "Found" : "Not Found") << std::endl;  // Expected: Not Found

    // Test unique
    list.push_front(25);
    list.push_front(25);
    list.push_front(10);
    std::cout << "Before unique: ";
    list.print_list();  // Expected: 10 25 25 25 5 10 15 20 25 30 35 100 200
    std::cout << std::endl;
    list.unique();
    std::cout << "After unique: ";
    list.print_list();  // Expected: 10 5 15 20 25 30 35 100 200
    std::cout << std::endl;

    return 0;
}
