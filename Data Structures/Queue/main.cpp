#include <iostream>
#include "queue.h"

void test_int_queue() {
    Queue<int> intQueue;
    
    // Test enqueue
    std::cout << "Enqueuing 1, 2, 3 to intQueue" << std::endl;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    
    std::cout << "Size after enqueuing 3 elements: " << intQueue.size() << std::endl;

    // Test peek
    std::cout << "Peek front element: " << intQueue.peek() << std::endl;

    // Test dequeue
    intQueue.dequeue();
    std::cout << "Peek front element after one dequeue: " << intQueue.peek() << std::endl;
    std::cout << "Size after one dequeue: " << intQueue.size() << std::endl;

    intQueue.dequeue();
    std::cout << "Peek front element after second dequeue: " << intQueue.peek() << std::endl;
    std::cout << "Size after second dequeue: " << intQueue.size() << std::endl;

    intQueue.dequeue();
    std::cout << "Queue empty after dequeueing all elements: " << intQueue.isempty() << std::endl;
}

void test_string_queue() {
    Queue<std::string> stringQueue;

    // Test enqueue
    std::cout << "Enqueuing 'first', 'second', 'third' to stringQueue" << std::endl;
    stringQueue.enqueue("first");
    stringQueue.enqueue("second");
    stringQueue.enqueue("third");

    std::cout << "Size after enqueuing 3 elements: " << stringQueue.size() << std::endl;

    // Test peek
    std::cout << "Peek front element: " << stringQueue.peek() << std::endl;

    // Test dequeue
    stringQueue.dequeue();
    std::cout << "Peek front element after one dequeue: " << stringQueue.peek() << std::endl;
    std::cout << "Size after one dequeue: " << stringQueue.size() << std::endl;

    stringQueue.dequeue();
    std::cout << "Peek front element after second dequeue: " << stringQueue.peek() << std::endl;
    std::cout << "Size after second dequeue: " << stringQueue.size() << std::endl;

    stringQueue.dequeue();
    std::cout << "Queue empty after dequeueing all elements: " << stringQueue.isempty() << std::endl;
}

void test_double_queue() {
    Queue<double> doubleQueue;

    // Test enqueue
    std::cout << "Enqueuing 1.1, 2.2, 3.3 to doubleQueue" << std::endl;
    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(3.3);

    std::cout << "Size after enqueuing 3 elements: " << doubleQueue.size() << std::endl;

    // Test peek
    std::cout << "Peek front element: " << doubleQueue.peek() << std::endl;

    // Test dequeue
    doubleQueue.dequeue();
    std::cout << "Peek front element after one dequeue: " << doubleQueue.peek() << std::endl;
    std::cout << "Size after one dequeue: " << doubleQueue.size() << std::endl;

    doubleQueue.dequeue();
    std::cout << "Peek front element after second dequeue: " << doubleQueue.peek() << std::endl;
    std::cout << "Size after second dequeue: " << doubleQueue.size() << std::endl;

    doubleQueue.dequeue();
    std::cout << "Queue empty after dequeueing all elements: " << doubleQueue.isempty() << std::endl;
}

int main() {
    std::cout << "Testing Queue with int type" << std::endl;
    test_int_queue();

    std::cout << "\nTesting Queue with std::string type" << std::endl;
    test_string_queue();

    std::cout << "\nTesting Queue with double type" << std::endl;
    test_double_queue();

    return 0;
}
