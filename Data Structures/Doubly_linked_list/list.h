// push_front(data): Inserts an element at the beginning of the list. +
// pop_front(): Removes the first element of the list. +
// push_back(data): Inserts an element at the end of the list. +
// pop_back(): Removes the last element of the list. +
// insert_after(prev_node, data): Inserts an element after a given node.+
// erase_after(prev_node): Removes the node after a given node.+
// clear(): Removes all elements from the list.+
// is_empty(): Checks if the list is empty.+
// front(): Returns the first element of the list.+

// reverse(): Reverses the list.

// merge(other_list): Merges another list into the current list.+
// print_list(): Prints all elements of the list.+
// sort(): Sorts the elements++
// unique(): Removes consecutive duplicate elements+

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <map>


template <typename T>

class list{
    private:
        struct node{
            node(T data, node* next = nullptr, node* prev = nullptr): data(data), next(next), prev(prev){}
            T data;
            node* next;
            node* prev;
        };

        node* head;
        node* tail;
    public:

        list():head(nullptr), tail(nullptr){}

        list(int size, T data):head(nullptr), tail(nullptr){
            for(int i = 0; i < size; ++i){
                push_back(data);
            }
        }

        list(const list<T>& other){
            node* other_tmp = other.head;
            while(other_tmp){
                push_back(other_tmp->data);
                other_tmp = other_tmp->next;
            }
        }

        list(list<T>&& other){
            head = other.head;
            tail = other.tail;
            other.head = other.tail = nullptr;
        }

        void push_front(T data){
            if(head != nullptr){
                node* new_node = new node(data,head);
                head->prev = new_node;
                head = new_node;
            }else{
                head = tail = new node(data);
            }
        }

        void pop_front(){

            if (head) {
                node* tmp = head;
                head = head->next;
                if (head) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
                    delete tmp;
                }

        }

        void push_back(T data){
            if(tail){
                tail->next = new node(data, nullptr, tail);
                tail = tail->next;
            }else{
                head = tail = new node(data);
            }
        }

        void pop_back(){
            if(tail){
                node* tmp = tail;
                tail = tail->prev;
                if(tail){
                    tail->next = nullptr;
                }else{
                    head = nullptr;
                }
                delete tmp;
            }
        }

        node* search(T data){

            node* current = head;
            while(current){
                if(current->data == data){
                    return current;
                }
                current = current->next;
            }

            return nullptr;
        }

        void insert_after(node* prev_node, T data){
            if(prev_node){
                node* tmp = prev_node->next;
                if(tmp){
                    node* new_node = new node(data, tmp, prev_node);
                    prev_node->next = new_node;
                    tmp->prev = new_node;
                }else{
                    prev_node->next = new node(data, nullptr, prev_node);
                }
            }else{
                throw std::runtime_error("Invalid node");
            }
        }

        void erase_after(node* prev_node){
                if(prev_node->next){
                    node* tmp = prev_node->next->next;
                    if(tmp){
                        delete prev_node->next;
                        prev_node->next = tmp;
                        tmp->prev = prev_node;
                    }else{
                        delete prev_node->next;
                        prev_node->next = nullptr;
                    }
                }else{
                    throw std::runtime_error("Invalid node");
                }
            
        }

        int size() const {
        int count = 0;
        node* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

        void print_list(){
            node* current = head;
            while(current){
                std::cout << current->data << " ";
                current = current->next;
            }
        }

        bool is_empty(){
            return head == nullptr;
        }

        T front(){
            return head->data;
        }

        void merge(list& other){

            if(this == &other){
                return;
            }

           if(tail){
            if(other.head){
                tail->next = other.head;
                other.head->prev = tail;
                tail = other.tail;
            }
           }else{
                head = other.head;
                tail = other.tail;
           }

           other.tail = other.head = nullptr;
            
        }

        void clear(){
            while(head){
                pop_front();
            }
        }

        void unique(){

        if(head == nullptr){
            return;
        }

        node* current = head;
        std::map<T, int> count;

        while(current){
            ++count[current->data];
            current = current->next;
        }

        current = head;
        node* next = current->next;
        node* prev = nullptr;
        node* tmp;

        while(current && next){

            if(count[current->data] > 1){

                    --count[current->data]; 

                    tmp = current;
                    next->prev = prev;

                    if(prev){
                        prev->next = next;
                    }else{
                        head = next;
                    }

                    current = next;
                    next = current->next;


                    delete tmp; 

            }else{
                    prev = current;
                    current = next;
                    next = current->next;
            }
        }
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        node* current = head;
        while (current) {
            node* min = current;
            node* next = current->next;

            while (next) {
                if (next->data < min->data) {
                    min = next;
                }
                next = next->next;
            }

            if (min != current) {
                std::swap(current->data, min->data);
            }
            current = current->next;
        }
    }

    void reverse() {

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    node* current = head;
    node* next = nullptr;
    node* prev = nullptr;

    while (current) {

        next = current->next;

        current->next = prev;
        current->prev = next;


        prev = current;
        current = next;

    }

    node* tmp = head;
    head = tail;
    tail = tmp;

    if (head) {
        head->prev = nullptr;
    }
}

        ~list(){
            clear();
        }

};

#endif