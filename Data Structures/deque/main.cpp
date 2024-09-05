#include <iostream>
#include <string>
#include <vector>
#include "deque.h"

int main() {
    // 1. Test constructors with int type
    deque<int> dq1;  // Default constructor
    deque<int> dq2(5, 10);  // Fill constructor: deque of 5 elements, each initialized to 10
    deque<int> dq3(5);  // Fill constructor: deque of 5 elements, default initialized
    std::vector<int> vec = {1, 2, 3, 4, 5};
    deque<int> dq4(vec.begin(), vec.end());  // Range constructor
    deque<int> dq5(dq2);  // Copy constructor
    deque<int> dq6(std::move(dq3));  // Move constructor
    deque<int> dq7{1, 2, 3, 4, 5};  // Initializer list constructor

    std::cout << "Testing constructors (int type):" << std::endl;
    std::cout << "dq2 size: " << dq2.size() << ", dq2 contains: ";
    for (auto it = dq2.begin(); it != dq2.end(); ++it) {
        std::cout << *it << " ";  // Should print five 10s
    }
    std::cout << std::endl;

    std::cout << "dq4 size: " << dq4.size() << ", dq4 contains: ";
    for (auto it = dq4.begin(); it != dq4.end(); ++it) {
        std::cout << *it << " ";  // Should print 1, 2, 3, 4, 5 in any order
    }
    std::cout << std::endl;

    std::cout << "dq5 size: " << dq5.size() << ", dq5 contains: ";
    for (auto it = dq5.begin(); it != dq5.end(); ++it) {
        std::cout << *it << " ";  // Should print five 10s
    }
    std::cout << std::endl;


    // 2. Test constructors with std::string type
    deque<std::string> dq_str1;
    deque<std::string> dq_str2(3, "hello");  // Fill constructor
    deque<std::string> dq_str3{"apple", "banana", "cherry"};  // Initializer list constructor


    std::vector<std::string> vec_str = {"foo", "bar", "baz"};
    deque<std::string> dq_str4(vec_str.begin(), vec_str.end());  // Range constructor



    std::cout << "\nTesting constructors (std::string type):" << std::endl;
    std::cout << "dq_str2 size: " << dq_str2.size() << ", dq_str2 contains: ";
    for (auto it = dq_str2.begin(); it != dq_str2.end(); ++it) {
        std::cout << *it << " ";  // Should print three "hello"s
    }
    std::cout << std::endl;

    std::cout << "dq_str3 size: " << dq_str3.size() << ", dq_str3 contains: ";
    for (auto it = dq_str3.begin(); it != dq_str3.end(); ++it) {
        std::cout << *it << " ";  // Should print "apple", "banana", "cherry" in any order
    }
    std::cout << std::endl;

    // 3. Test assignment operators
    dq1 = dq2;  // Copy assignment
    std::cout << "\ndq1 after copy assignment from dq2: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should print five 10s
    }
    std::cout << std::endl;

    dq1 = std::move(dq4);  // Move assignment
    std::cout << "dq1 after move assignment from dq4: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should print 1, 2, 3, 4, 5 in any order
    }
    std::cout << std::endl;

    dq1 = {6, 7, 8};  // Initializer list assignment
    std::cout << "dq1 after initializer list assignment: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should print 6, 7, 8 in any order
    }
    std::cout << std::endl;

    // 4. Test element access
    std::cout << "\nTesting element access:" << std::endl;
    std::cout << "dq1 size: " << dq1.size() << ", dq1 front: " << dq1.front() << ", dq1 back: " << dq1.back() << std::endl;

    // 5. Test modifiers
    std::cout << "\nTesting modifiers:" << std::endl;
    dq1.push_back(9);
    std::cout << "After push_back(9), dq1 contains: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should include 9
    }
    std::cout << std::endl;

    dq1.push_front(5);
    std::cout << "After push_front(5), dq1 contains: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should include 5
    }
    std::cout << std::endl;

    dq1.pop_back();
    std::cout << "After pop_back(), dq1 size: " << dq1.size() << std::endl;

    dq1.pop_front();
    std::cout << "After pop_front(), dq1 size: " << dq1.size() << std::endl;

    // 6. Test insert
    dq1.insert(dq1.begin() + 1, 99);  // Insert single element
    std::cout << "After insert(99), dq1 contains: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";  // Should include 99
    }
    std::cout << std::endl;

    // 7. Test iterators
    std::cout << "\nTesting iterators:" << std::endl;
    std::cout << "dq1 elements using iterator: ";
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "dq1 elements using reverse_iterator: ";
    for (auto rit = dq1.rbegin(); rit != dq1.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 8. Test other operations
    std::cout << "\nTesting other operations:" << std::endl;
    std::cout << "dq1 size: " << dq1.size() << std::endl;
    dq1.clear();
    std::cout << "After clear(), dq1 size: " << dq1.size() << std::endl;

    return 0;
}
