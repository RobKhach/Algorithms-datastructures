#ifndef PRINTER_H
#define PRINTER_H

#include "../../Data Structures/Queue/queue.h"

class PrintJob {
public:
    int jobId;
    std::string jobName;
    int numberOfPages;

    PrintJob(int id, std::string name, int pages)
        : jobId(id), jobName(name), numberOfPages(pages) {}
};

class PrinterQueue {
private:
    Queue<PrintJob> queue;
    int nextJobId;

public:
    PrinterQueue() : nextJobId(1) {}

    void enqueue(const std::string& jobName, int numberOfPages) {
        PrintJob newJob(nextJobId++, jobName, numberOfPages);
        queue.enqueue(newJob);
        std::cout << "Enqueued: " << newJob.jobName << " with " << newJob.numberOfPages << " pages." << std::endl;
    }

    void dequeue() {
        if (!queue.isempty()) {
            PrintJob job = queue.peek();
            std::cout << "Printing Job ID: " << job.jobId << ", Name: " << job.jobName << ", Pages: " << job.numberOfPages << std::endl;
            queue.dequeue();
        } else {
            std::cout << "No print jobs in the queue." << std::endl;
        }
    }

    void peek() {
        if (!queue.isempty()) {
            PrintJob job = queue.peek();
            std::cout << "Next Job ID: " << job.jobId << ", Name: " << job.jobName << ", Pages: " << job.numberOfPages << std::endl;
        } else {
            std::cout << "No print jobs in the queue." << std::endl;
        }
    }

    bool isEmpty() {
        return queue.isempty();
    }

    size_t size() {
        return queue.size();
    }
};

#endif