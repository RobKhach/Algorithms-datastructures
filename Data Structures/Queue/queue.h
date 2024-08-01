#ifndef QUEUE_H
#define QUEUE_H

#include "../Doubly_linked_list/list.h"
#include <iostream>

template <typename T>
class Queue{
    private:
        list<T> queue;
    public:
        void enqueue(T data){
            queue.push_back(data);
        }
        void dequeue(){
            queue.pop_front();
        }
        T peek(){
            if(!isempty()){
                return queue.front();
            }else{
                throw std::runtime_error("Queue is Empty");
            }
        }
        bool isempty(){
            return queue.is_empty();
        }
        size_t size(){
            return queue.size();
        }
};

#endif