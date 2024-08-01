#include "Printer.h"
#include <iostream>

int main() {
    PrinterQueue printerQueue;

    std::cout << "Enqueuing print jobs..." << std::endl;
    printerQueue.enqueue("Document1", 10);
    printerQueue.enqueue("Document2", 5);
    printerQueue.enqueue("Document3", 15);

    std::cout << "\nCurrent queue size: " << printerQueue.size() << std::endl;

    std::cout << "\nPeeking next job in the queue..." << std::endl;
    printerQueue.peek();

    std::cout << "\nDequeuing and printing jobs..." << std::endl;
    printerQueue.dequeue();
    printerQueue.dequeue();
    printerQueue.dequeue();

    std::cout << "\nCurrent queue size: " << printerQueue.size() << std::endl;
    printerQueue.peek();

    return 0;
}