#include "stack.h"
#include <iostream>
#include <string>

void test_int_stack() {
    Stack<int> int_stack;

    std::cout << "Testing int stack:" << std::endl;

    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    if (!int_stack.isempty()) {
        std::cout << "Top after pushing 1, 2, 3: " << int_stack.top() << std::endl;
    }

    int_stack.pop();
    if (!int_stack.isempty()) {
        std::cout << "Top after one pop: " << int_stack.top() << std::endl;
    }

    int_stack.pop();
    if (!int_stack.isempty()) {
        std::cout << "Top after two pops: " << int_stack.top() << std::endl;
    }

    int_stack.pop();
    std::cout << "Is empty after three pops: " << (int_stack.isempty() ? "true" : "false") << std::endl;

    std::cout << "Int stack test completed." << std::endl;
}

void test_double_stack() {
    Stack<double> double_stack;

    std::cout << "Testing double stack:" << std::endl;

    double_stack.push(1.1);
    double_stack.push(2.2);
    double_stack.push(3.3);
    if (!double_stack.isempty()) {
        std::cout << "Top after pushing 1.1, 2.2, 3.3: " << double_stack.top() << std::endl;
    }

    double_stack.pop();
    if (!double_stack.isempty()) {
        std::cout << "Top after one pop: " << double_stack.top() << std::endl;
    }

    double_stack.pop();
    if (!double_stack.isempty()) {
        std::cout << "Top after two pops: " << double_stack.top() << std::endl;
    }

    double_stack.pop();
    std::cout << "Is empty after three pops: " << (double_stack.isempty() ? "true" : "false") << std::endl;

    std::cout << "Double stack test completed." << std::endl;
}

void test_string_stack() {
    Stack<std::string> string_stack;

    std::cout << "Testing string stack:" << std::endl;

    string_stack.push("first");
    string_stack.push("second");
    string_stack.push("third");
    if (!string_stack.isempty()) {
        std::cout << "Top after pushing 'first', 'second', 'third': " << string_stack.top() << std::endl;
    }

    string_stack.pop();
    if (!string_stack.isempty()) {
        std::cout << "Top after one pop: " << string_stack.top() << std::endl;
    }

    string_stack.pop();
    if (!string_stack.isempty()) {
        std::cout << "Top after two pops: " << string_stack.top() << std::endl;
    }

    string_stack.pop();
    std::cout << "Is empty after three pops: " << (string_stack.isempty() ? "true" : "false") << std::endl;

    std::cout << "String stack test completed." << std::endl;
}

int main() {
    test_int_stack();
    test_double_stack();
    test_string_stack();

    std::cout << "All tests completed." << std::endl;
    return 0;
}
