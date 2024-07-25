#include <iostream>
#include "dynamic_array.h"

void test_dynamic_array() {
    
    // Test default constructor
    std::cout << "Testing default constructor:" << std::endl;
    dynamic_array<int> arr1;
    std::cout << "Initial size: " << arr1.size() << ", capacity: " << arr1.capacity() << ", isEmpty: " << arr1.isempty() << std::endl;

    // Test constructor with capacity
    std::cout << "\nTesting constructor with capacity:" << std::endl;
    dynamic_array<int> arr2(10);
    std::cout << "Initial size: " << arr2.size() << ", capacity: " << arr2.capacity() << std::endl;

    // Test constructor with size and default value
    std::cout << "\nTesting constructor with size and default value:" << std::endl;
    dynamic_array<int> arr3(5, 3);
    std::cout << "Initial size: " << arr3.size() << ", capacity: " << arr3.capacity() << ", values: " << arr3 << std::endl;

    // Test push_back
    std::cout << "\nTesting push_back:" << std::endl;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    std::cout << "After push_back, size: " << arr2.size() << ", values: " << arr2 << std::endl;

    // Test pop_back
    std::cout << "\nTesting pop_back:" << std::endl;
    arr2.pop_back();
    std::cout << "After pop_back, size: " << arr2.size() << ", values: " << arr2 << std::endl;

    // Test insert
    std::cout << "\nTesting insert:" << std::endl;
    arr2.insert(1, 10);
    std::cout << "After insert, size: " << arr2.size() << ", values: " << arr2 << std::endl;

    // Test remove
    std::cout << "\nTesting remove:" << std::endl;
    arr2.remove(1);
    std::cout << "After remove, size: " << arr2.size() << ", values: " << arr2 << std::endl;

    // Test clear
    std::cout << "\nTesting clear:" << std::endl;
    arr2.clear();
    std::cout << "After clear, size: " << arr2.size() << ", capacity: " << arr2.capacity() << ", isEmpty: " << arr2.isempty() << std::endl;

    // Test include
    std::cout << "\nTesting include:" << std::endl;
    arr3.push_back(4);
    std::cout << "Array values: " << arr3 << std::endl;
    std::cout << "Include 4: " << arr3.include(4) << std::endl;
    std::cout << "Include 10: " << arr3.include(10) << std::endl;

    // Test emplace
    std::cout << "\nTesting emplace:" << std::endl;
    arr3.emplace(1, 9);
    std::cout << "After emplace, size: " << arr3.size() << ", values: " << arr3 << std::endl;

    // Test operator=
    std::cout << "\nTesting operator=:" << std::endl;
    dynamic_array<int> arr4 = arr3;
    std::cout << "Copied array values: " << arr4 << std::endl;

    // Test << operator
    std::cout << "\nTesting << operator:" << std::endl;
    std::cout << "Array values: " << arr3 << std::endl;

    // Test shrink_to_fit
    std::cout << "\nTesting shrink_to_fit:" << std::endl;
    arr3.shrink_to_fit();
    std::cout << "After shrink_to_fit, size: " << arr3.size() << ", capacity: " << arr3.capacity() << std::endl;

    // Test reserve
    std::cout << "\nTesting reserve:" << std::endl;
    arr3.reserve(20);
    std::cout << "After reserve, size: " << arr3.size() << ", capacity: " << arr3.capacity() << std::endl;

    // Additional test with std::string
    std::cout << "\nTesting with std::string:" << std::endl;
    dynamic_array<std::string> arr5;
    arr5.push_back("Hello");
    arr5.push_back("World");
    std::cout << "Array values: " << arr5 << std::endl;
}

int main() {
    test_dynamic_array();
    return 0;
}
