#ifndef STACK_H
#define STACK_H

#include "../Dynamic_Array/dynamic_array.h"
#include <iostream>

template <typename T>
class Stack{
    private:
        dynamic_array<T> stack;
    public:

        void push(T data){
            stack.push_back(data);
        }

        void pop(){
            stack.pop_back();
        }

        T top(){
            if(!isempty()){
                return stack.top();
            }else{
                throw std::runtime_error("Stack is empty");
            }
        }

        bool isempty(){
            return stack.isempty();
        }
};


#endif