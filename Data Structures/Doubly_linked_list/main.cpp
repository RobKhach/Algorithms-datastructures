#include <iostream>
#include "list.h"

int main() {
    // Testing with int
    list<int> intList;

    // Testing push_front and push_back
    intList.push_front(3);
    intList.push_back(5);
    intList.push_front(1);
    intList.push_back(7);
    std::cout << "List after push_front and push_back: ";
    intList.print_list(); // Expected: 1 3 5 7
    std::cout << std::endl;

    // Testing pop_front and pop_back
    intList.pop_front();
    intList.pop_back();
    std::cout << "List after pop_front and pop_back: ";
    intList.print_list(); // Expected: 3 5
    std::cout << std::endl;

    // Testing insert_after and erase_after
    auto node3 = intList.search(3);
    intList.insert_after(node3, 4);
    std::cout << "List after insert_after (3, 4): ";
    intList.print_list(); // Expected: 3 4 5
    std::cout << std::endl;
    intList.erase_after(node3);
    std::cout << "List after erase_after (3): ";
    intList.print_list(); // Expected: 3 5
    std::cout << std::endl;

    // Testing clear and is_empty
    intList.clear();
    std::cout << "List after clear: ";
    intList.print_list(); // Expected: empty
    std::cout << std::endl;
    std::cout << "List is empty: " << (intList.is_empty() ? "yes" : "no") << std::endl; // Expected: yes

    // Testing merge
    list<int> list1;
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);

    list<int> list2;
    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);

    list1.merge(list2);
    std::cout << "List after merge: ";
    list1.print_list(); // Expected: 1 3 5 2 4 6
    std::cout << std::endl;

    // Testing unique
    list1.push_back(6);
    list1.push_back(6);
    list1.push_back(7);
    list1.unique();
    std::cout << "List after unique: ";
    list1.print_list(); // Expected: 1 3 5 2 4 6 7
    std::cout << std::endl;

    // Testing sort
    list1.push_back(0);
    list1.push_back(8);
    list1.push_back(3);
    list1.sort();
    std::cout << "List after sort: ";
    list1.print_list(); // Expected: 0 1 2 3 3 4 5 6 7 8
    std::cout << std::endl;

    // Testing reverse
    list1.reverse();
    std::cout << "List after reverse: ";
    list1.print_list(); // Expected: 8 7 6 5 4 3 3 2 1 0
    std::cout << std::endl;

    // Testing with std::string
    list<std::string> stringList;
    stringList.push_back("cat");
    stringList.push_back("dog");
    stringList.push_back("bird");
    stringList.push_back("cat");
    stringList.push_back("dog");

    std::cout << "String list: ";
    stringList.print_list(); // Expected: cat dog bird cat dog
    std::cout << std::endl;

    stringList.unique();
    std::cout << "String list after unique: ";
    stringList.print_list(); // Expected: cat dog bird
    std::cout << std::endl;

    stringList.reverse();
    std::cout << "String list after reverse: ";
    stringList.print_list(); // Expected: bird dog cat
    std::cout << std::endl;

    stringList.sort();
    std::cout << "String list after sort: ";
    stringList.print_list(); // Expected: bird cat dog
    std::cout << std::endl;

    return 0;
}
