// Singly Linked List Assignment
// Description
// A singly linked list is a data structure consisting of a sequence of elements, where each element (node) contains a value and a pointer to the next node in the sequence. The first node in the list is called the head, and the last node points to null (or None in Python), indicating the end of the list.
// Core Methods to Implement
// push_front(data): Inserts an element at the beginning of the list.
// pop_front(): Removes the first element of the list.
// insert_after(prev_node, data): Inserts an element after a given node.
// erase_after(prev_node): Removes the node after a given node.
// clear(): Removes all elements from the list.
// is_empty(): Checks if the list is empty.
// front(): Returns the first element of the list.
// reverse(): Reverses the list.
// merge(other_list): Merges another list into the current list.
// print_list(): Prints all elements of the list.
// sort(): Sorts the elements

// unique(): Removes consecutive duplicate elements
// search()

#include <stdexcept>
#include <map>

template <typename T>
struct Node{
    Node(T data, Node* next_ptr = nullptr): data(data), next(next_ptr){}
    T data;
    Node* next;
};

template <typename T>
class Slist{
    private:
        Node<T>* head = nullptr;
    
    public:
        //Constructors
        Slist(): head(nullptr){} // Default

        Slist(int size, T data)// Parametral with size-data
        {
            Node<T>* current;

            for(int i = 0; i < size; ++i){

                current = new Node<T>(data, head);
                head = current;
                
            }
        }
        Slist(const Slist<T>& other)//Copy constructor
        {
            this->head = new Node<T>(other.head->data);

            Node<T>* current = head;
            Node<T>* other_current = other.head->next;

            while(other_current){

                current->next = new Node<T>(other_current->next);
                current = current->next;
                other_current = other_current->next;

            }

        }

        Slist(const Slist<T>&& other)//Move Constructor
        {
            this->head = other.head;
            other.head = nullptr;
        }

        friend std::ostream& operator<<(std::ostream& os, const Slist<T>& list){
            Node<T>* current = list.front();
            while(current){
                os << current->data << " ";
                current = current->next;
            }

            return os;
        }

        void push_front(T data){
            Node<T>* new_node = new Node<T>(data, head);
            head = new_node;
        }

        void pop_front(){
            Node<T>* new_head = head->next;
            delete head;
            head = new_head;
        }

        void insert_after(Node<T>* prev_node, T data){
            if(prev_node){
                Node<T>* current_next = prev_node->next;
                prev_node->next = new Node<T>(data, current_next);
            }else{
                throw std::runtime_error("Invalid Node*");
            }
        }

        void erase_after(Node<T>* prev_node){
            if(prev_node && prev_node->next){
                Node<T>* tmp = prev_node->next;
                prev_node->next = prev_node->next->next;
                delete tmp;
            }else{
                throw std::runtime_error("Invalide Node or dont have next");
            }
        }

        void clear(){
            Node<T>* current = head;
            while(current){
                current = current->next;
                delete head;
                head = current;      
            }
        }

        int size() const {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

        bool isEmpty(){
            return head == nullptr;
        }

        Node<T>* front() const{
            return head; 
        }

        void reverse(){

            Node<T>* next = nullptr;
            Node<T>* prev = nullptr;
            Node<T>* current = head;

            while(current){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;
        }

        void merge(Slist<T>& other){

            Node<T>* current = head;
            while(current->next){
                current = current->next;
            }

            current->next = other.head;
            other.head = nullptr;

        }

        void print_list(){
            std::cout << *this;
        }

        void swap(Node<T>* first, Node<T>* second){
            T tmp = first->data;
            first->data = second->data;
            second->data = tmp;
        }

        void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node<T>* current = head;
        while (current) {
            Node<T>* min = current;
            Node<T>* next = current->next;

            while (next) {
                if (next->data < min->data) {
                    min = next;
                }
                next = next->next;
            }

            if (min != current) {
                swap(current, min);
            }
            current = current->next;
        }
    }

    bool search(T value){
        Node<T>* current = head;

        while(current){
            if(current->data == value){
                return true;
            }
            current = current -> next;

        }
        return false;
    }

    void unique(){

        if(head == nullptr){
            return;
        }

        Node<T>* current = head;
        std::map<T, int> count;

        while(current){
            ++count[current->data];
            current = current->next;
        }

        current = head;
        Node<T>* next = current->next;
        Node<T>* prev = head;
        Node<T>* tmp;

        while(current && next){
            if(count[current->data] > 1){
                
                    --count[current->data];
                    tmp = current;
                    prev->next = next;
                    prev = current;
                    current = next;
                    next = current->next;

                    if(head == tmp){
                        head = current;
                    }

                    
                    delete tmp;


            }else{
                    prev = current;
                    current = current->next;
                    next = current->next;
            }
        }
    }



};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Slist<T>& list){

            Node<T>* current = list.front();

            while(current){
                os << current->data << " ";
                current = current->next;
            }

            return os;
}