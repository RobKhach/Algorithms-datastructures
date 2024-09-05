#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "deque.h"

template <typename T, typename Allocator>
deque<T, Allocator>::iterator::iterator(){}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator::iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end) : current(current), left_start(left_start), right_start(right_start), left_end(left_end), right_end(right_end) {}

template <typename T, typename Allocator>
deque<T ,Allocator>::iterator::iterator(const iterator& other){
    current = other.current;
    left_start = other.left_start;
    left_end = other.left_end;
    right_start = other.right_start;
    right_end = other.right_end;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::current_in_range() const{
    if(((current < left_start) && (current >= left_end)) || ((current >= right_start) && (current < right_end))){
        return true;
    }else{
        return false;
    }
}


template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::current_in_left() const{
    if(current < left_start && current >= left_end){
        return true;
    }else{
        return false;
    }
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::current_in_right() const{
    if(current >= right_start && current < right_end){
        return true;
    }else{
        return false;
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::iterator::operator*(){
    if(current_in_range()){
        return *current;
    }else{
        throw std::out_of_range("Iterator in dereference is out of range");
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::iterator::operator*() const{
    if(current_in_range()){
        return *current;
    }else{
        throw std::out_of_range("Iterator in dereference is out of range");
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T,Allocator>::iterator::operator[](difference_type n){
    int i = 0;
    while(i < n){
        ++(*this);
        ++i;
    }
    return *(*this);
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator& deque<T, Allocator>::iterator::operator++() {
    if (current_in_left()) {
        if(current != left_end) {
            --current;
        }else{
            current = const_cast<pointer>(right_start);
        }
    }else if(current_in_right()) {
        ++current;
    } else if(current == left_end && right_start == nullptr){
        current = const_cast<pointer>(left_end - 1);
    }else{
        throw std::out_of_range("Iterator out of range in operator++");
    }

    return *this;
}


template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::iterator::operator++(int){
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator& deque<T, Allocator>::iterator::operator--() {
    if(current_in_right()){
        if(current != right_start){
            --current;
        }else{
            current = const_cast<pointer>(left_end);
        }
    }else if(current_in_left()){
        ++current;
    }else if(current == right_end){
        --current;
    }else{
        throw std::out_of_range("Iterator out of range in operator--");
    }

    return *this;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::iterator::operator--(int){
    iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator& deque<T, Allocator>::iterator::operator+=(difference_type n){
    int i = 0;
    while(i < n){
        ++(*this);
        ++i;
    }
    return *this;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator& deque<T, Allocator>::iterator::operator-=(difference_type n){
    int i = 0;
    while(i < n){
        --(*this);
        ++i;
    }
    return *this;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T,Allocator>::iterator::operator+(difference_type n) const{
    iterator tmp = *this;
    int i = 0;
    while(i < n){
        ++tmp;
        ++i;
    }

    return tmp;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T,Allocator>::iterator::operator-(difference_type n) const{
    iterator tmp = *this;
    int i = 0;
    while(i < n){
        --tmp;
        ++i;
    }

    return tmp;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::operator==(const iterator& other) const{
    return current == other.current;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::operator<(const iterator& other) const{
    if(current_in_left() && other.current_in_left()){
        return current > other.current;
    }else if(current_in_right() && other.current_in_right()){
        return current < other.current;
    }else if(current_in_left() && other.current_in_right()){
        return true;
    }else {
        return false;
    }
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::operator>(const iterator& other) const{
    if(current_in_left() && other.current_in_left()){
        return current < other.current;
    }else if(current_in_right() && other.current_in_right()){
        return current > other.current;
    }else if(current_in_left() && other.current_in_right()){
        return false;
    }else {
        return true;
    }
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::operator<=(const iterator& other) const{
    return *this < other || *this == other;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::iterator::operator>=(const iterator& other) const{
    return *this > other || *this == other;
}

template <typename T,typename Allocator>
deque<T, Allocator>::difference_type deque<T, Allocator>::iterator::operator-(const iterator& other) const{
    
    if(*this == other){
        return 0;
    }else if(*this < other){
        std::ptrdiff_t i = 0;
        iterator tmp = other;
        while(tmp != *this){
            --i;
            --tmp;
        }

        return i;
    }else{
        std::ptrdiff_t i = 0;
        iterator tmp = *this;
        while(tmp != other){
            ++i;
            --tmp;    
        }
        return i;
    }
}

template <typename T, typename Allocator>
bool deque<T,Allocator>::iterator::operator!=(const iterator& other) const{
    return this->current != other.current;
}

// ###########################################

template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator::const_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end) : iter(current, left_start, left_end, right_start, right_end) {}

template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator& deque<T, Allocator>::const_iterator::operator++(){
    ++iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator deque<T, Allocator>::const_iterator::operator++(int){
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator& deque<T, Allocator>::const_iterator::operator--(){
    --iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator deque<T, Allocator>::const_iterator::operator--(int){
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}


template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::const_iterator::operator*() const{
    return *iter;  
}
template <typename T, typename Allocator>
deque<T,Allocator>::const_iterator deque<T,Allocator>::const_iterator::operator+(difference_type n){
    iter += n;
    return *this;
}

template <typename T, typename Allocator>
deque<T,Allocator>::const_iterator deque<T,Allocator>::const_iterator::operator-(difference_type n){
    iter -= n;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::difference_type deque<T,Allocator>::const_iterator::operator-(const iterator& other) const{
    std::ptrdiff_t dif = iter - other.iter;
    return dif;
}


template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T,Allocator>::const_iterator::operator[](difference_type n) const{
    int i = 0;
    iterator tmp = iter;
    while(i < n){
        ++tmp;
        ++i;
    }
    return *tmp;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator==(const const_iterator& other) const{
    return iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator!=(const const_iterator& other) const{
    return iter != other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator<(const const_iterator& other) const{
    return iter < other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator>(const const_iterator& other) const{
    return iter > other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator<=(const const_iterator& other) const{
    return iter < other.iter || iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_iterator::operator>=(const const_iterator& other) const{
    return iter > other.iter || iter == other.iter;
}

//####################################################
template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator::reverse_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end) : iter(current, left_start, left_end, right_start, right_end) {}

template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator& deque<T, Allocator>::reverse_iterator::operator++(){
    --iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator deque<T, Allocator>::reverse_iterator::operator++(int){
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator& deque<T, Allocator>::reverse_iterator::operator--(){
    ++iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator deque<T, Allocator>::reverse_iterator::operator--(int){
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}


template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::reverse_iterator::operator*(){
    return *iter;
}
template <typename T, typename Allocator>
deque<T,Allocator>::reverse_iterator deque<T,Allocator>::reverse_iterator::operator+(difference_type n){
    iter -= n;
    return *this;
}

template <typename T, typename Allocator>
deque<T,Allocator>::reverse_iterator deque<T,Allocator>::reverse_iterator::operator-(difference_type n){
    iter += n;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::difference_type deque<T,Allocator>::reverse_iterator::operator-(const reverse_iterator& other) const{
    
    std::ptrdiff_t dif = iter - other.iter;
    return dif;
}


template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T,Allocator>::reverse_iterator::operator[](difference_type n){
    int i = 0;
    iterator tmp = iter;
    while(i < n){
        --tmp;
        ++i;
    }
    return *tmp;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator==(const reverse_iterator& other) const{
    return iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator!=(const reverse_iterator& other) const{
    return iter != other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator<(const reverse_iterator& other) const{
    return iter < other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator>(const reverse_iterator& other) const{
    return iter > other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator<=(const reverse_iterator& other) const{
    return iter < other.iter || iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::reverse_iterator::operator>=(const reverse_iterator& other) const{
    return iter > other.iter || iter == other.iter;
}
//#####################################################

template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end) : iter(current, left_start, left_end, right_start, right_end) {}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator& deque<T, Allocator>::const_reverse_iterator::operator++(){
    --iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::const_reverse_iterator::operator++(int){
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator& deque<T, Allocator>::const_reverse_iterator::operator--(){
    ++iter;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::const_reverse_iterator::operator--(int){
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}


template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::const_reverse_iterator::operator*() const{
    return *iter;
}
template <typename T, typename Allocator>
deque<T,Allocator>::const_reverse_iterator deque<T,Allocator>::const_reverse_iterator::operator+(difference_type n){
    iter -= n;
    return *this;
}

template <typename T, typename Allocator>
deque<T,Allocator>::const_reverse_iterator deque<T,Allocator>::const_reverse_iterator::operator-(difference_type n){
    iter += n;
    return *this;
}
template <typename T, typename Allocator>
deque<T, Allocator>::difference_type deque<T,Allocator>::const_reverse_iterator::operator-(const const_reverse_iterator& other) const{
    
    std::ptrdiff_t dif = iter - other.iter;
    return dif;
}


template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T,Allocator>::const_reverse_iterator::operator[](difference_type n) const{
    int i = 0;
    iterator tmp = iter;
    while(i < n){
        ++tmp;
        ++i;
    }
    return *tmp;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const{
    return iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const{
    return iter != other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const{
    return iter < other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const{
    return iter > other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const{
    return iter < other.iter || iter == other.iter;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const{
    return iter > other.iter || iter == other.iter;
}

//######################################################
template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::begin(){
    if(left_size != 0){
        return iterator(left + left_size - 1, left + left_size , left, right, right + right_size );
    }else{
        return iterator(right, left + left_size, left, right, right + right_size);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::end(){
    if(right_size != 0){
        return iterator(right + right_size, left + left_size, left, right, right + right_size);
    }else{
        return iterator(right, left + left_size, left, right, right - right_size);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator deque<T, Allocator>::cbegin()const{
    if(left_size != 0){
        return const_iterator(left + left_size - 1, left + left_size, left, right, right + right_size);
    }else{
        return const_iterator(right, left + left_size, left, right, right + right_size);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_iterator deque<T, Allocator>::cend()const{
    if(right_size != 0){
        return const_iterator(right + right_size, left + left_size, left, right, right + right_size);
    }else{
        return const_iterator(left - 1, left + left_size, left, right, right + right_size);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rbegin(){
    if(right_size != 0){
        return reverse_iterator(right + right_size - 1, left + left_size, left, right, right + right_size );
    }else{
        return reverse_iterator(left , left + left_size, left, right, right + right_size);
    }
}



template <typename T, typename Allocator>
deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rend(){
    if(left_size != 0){
        return reverse_iterator(left + left_size , left + left_size, left, right, right + right_size);
    }else{
        return reverse_iterator(right - 1, left + left_size, left, right, right + right_size);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::crbegin()const{
    if(right_size != 0){
        return const_reverse_iterator(right + right_size - 1, left + left_size, left, right, right + right_size );
    }else{
        return const_reverse_iterator(left , left + left_size, left, right, right + right_size);
    }
}



template <typename T, typename Allocator>
deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::crend()const{
    if(left_size != 0){
        return const_reverse_iterator(left + left_size , left + left_size, left, right, right + right_size);
    }else{
        return const_reverse_iterator(right - 1, left + left_size, left, right, right + right_size);
    }
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::odd(size_type num) const{
    return num % 2 ? true : false;
}

template <typename T, typename Allocator>
int deque<T, Allocator>::get_balance() const{
    return right_size - left_size;
}



template <typename T, typename Allocator>
void deque<T, Allocator>::balance_deque() {
    int balance = get_balance();

    while (balance < -1 || balance > 1) {
        if (balance < -1) {  
            if (right_size == right_capacity) {
                resize((left_capacity + right_capacity) * 2);
            }
            
            right[right_size] = left[left_size - 1]; 
            ++right_size;
            --left_size;
            
        } else if (balance > 1) {  
            if (left_size == left_capacity) {
                resize((left_capacity + right_capacity) * 2);
            }
            
            left[left_size] = right[right_size - 1]; 
            ++left_size;
            --right_size;
        }
        
        balance = get_balance();
    }
}


template <typename T, typename Allocator>
void deque<T, Allocator>::copy_other(const deque& other, const Allocator& alloc){
    allocator = alloc;
    left_capacity = other.left_capacity;
    right_capacity = other.right_capacity;

    if(left || right){
        allocator.deallocate(left, left_capacity);
        allocator.deallocate(right, right_capacity);
    }

    left_size = right_size = 0;

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    auto it = other.cbegin();
    while(it != other.cend()){
        push_back(*it);
        ++it;
    }
}

template <typename T, typename Allocator>
void deque<T, Allocator>::move_other(deque&& other, const Allocator& alloc){
    left = other.left;
    right = other.right;
    left_capacity = other.left_capacity;
    right_capacity = other.right_capacity;
    left_size = other.left_size;
    right_size = other.right_size;
    allocator = alloc;

    other.left = nullptr;
    other.right = nullptr;
    other.left_capacity = 0;
    other.right_capacity = 0;
    other.left_size = 0;
    other.right_size = 0;
}
// template <typename T, typename Allocator>
// void deque<T, Allocator>::initialize(std::initializer_list<value_type> init, const Allocator& alloc){

//     if(left || right){
//         allocator.deallocate(left, left_capacity);
//         allocator.deallocate(right, right_capacity);
//     }

//     size_type count = init.size();

//     if(odd(count)){
//         left_capacity = 1 + count / 2;
//         right_capacity = count / 2;
//     }else{
//         left_capacity = count / 2;
//         right_capacity = count / 2;
//     } 

//     allocator = alloc;

//     left = allocator.allocate(left_capacity);
//     right = allocator.allocate(right_capacity);

//     auto it = init.begin();
//     while(it != init.end()){
//         push_back(*it);
//         ++it;
//     }
  
// }

template <typename T, typename Allocator>
void deque<T, Allocator>::initialize(std::initializer_list<value_type> init, const Allocator& alloc) {
    allocator = alloc;

    if (left && left_capacity > 0) {
        allocator.deallocate(left, left_capacity);
    }
    if (right && right_capacity > 0) {
        allocator.deallocate(right, right_capacity);
    }

    left_size = right_size = 0;

    size_type count = init.size();

    if (odd(count)) {
        left_capacity = 1 + count / 2;
        right_capacity = count / 2;
    } else {
        left_capacity = count / 2;
        right_capacity = count / 2;
    }

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    for (auto it = init.begin(); it != init.end(); ++it) {
        push_back(*it);
    }
}



template <typename T, typename Allocator>
void deque<T, Allocator>::push_back(const T& value){

    ++right_size;
    *(end() - 1) = value;

    if((left_size == left_capacity) || (right_size == right_capacity)){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();

}

template <typename T, typename Allocator>
void deque<T, Allocator>::push_back(T&& value){
    push_back(value);
}

template <typename T, typename Allocator>
void deque<T, Allocator>::push_front(const T& value){

    ++left_size;;
    *(begin()) = value;

    if((left_size == left_capacity) || (right_size == right_capacity)){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();

}

template <typename T, typename Allocator>
void deque<T, Allocator>::push_front(T&& value){
    push_front(value);
}

template <typename T, typename Allocator>
void deque<T, Allocator>::resize(size_type count){


        std::vector<value_type> vec;
        vec.reserve(left_size + right_size);

        int i = 0;
        while(i < left_size){
            vec.push_back(left[i++]);
        }

        i = 0;

        while(i < right_size){
            vec.push_back(right[i++]);
        }

        allocator.deallocate(left, left_capacity);
        allocator.deallocate(right, right_capacity);

        left_size = right_size = 0;
    
    if(odd(count)){
        left_capacity = 1 + count / 2;
        right_capacity = count / 2;
    }else{
        left_capacity = right_capacity = count / 2;
    }

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    auto it = vec.begin();
    while(it != vec.end()){
        push_back(*it);
        ++it;
    }

    }


template <typename T, typename Allocator>
void deque<T, Allocator>::resize(size_type count, const T& value){

        allocator.deallocate(left, left_capacity);
        allocator.deallocate(right, right_capacity);

        left_size = right_size = 0;
    
    if(odd(count)){
        left_capacity = 1 + count / 2;
        right_capacity = count / 2;
    }else{
        left_capacity = right_capacity = count / 2;
    }

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    int i = 0;
    while(i++ < count){
        push_back(value);
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque() : left(nullptr), right(nullptr), left_size(0), right_size(0), left_capacity(0) ,right_capacity(0){}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(size_type count, const T& value,const Allocator& alloc){
        
    if(odd(count)){
        left_capacity = left_size = 1 + count / 2;
        right_capacity = right_size = count / 2;
    }else{
        left_capacity = left_size = count / 2;
        right_capacity = right_size = count / 2;
    }

    allocator = alloc;

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    auto it = begin();
    while (it != end()){
        *it = value;
        ++it;
    }

}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(size_type count, const Allocator& alloc){
    
    if(odd(count)){
        left_capacity = 1 + count / 2;
        right_capacity = count / 2;
    }else{
        left_capacity = right_capacity = count / 2;
    }

    allocator = alloc;

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    left_size = right_size = 0;
}


template <typename T, typename Allocator>
template <iter InputIt>
deque<T, Allocator>::deque(InputIt first, InputIt last, const Allocator& alloc)
    : allocator(alloc), left(nullptr), right(nullptr), left_size(0), right_size(0), left_capacity(0), right_capacity(0) {  

    std::vector<value_type> vec(first, last);  

    size_type total_size = vec.size();
    if (odd(total_size)) {
        left_capacity = (total_size + 1) / 2;
        right_capacity = total_size / 2;
    } else {
        left_capacity = right_capacity = total_size / 2;
    }

    left = allocator.allocate(left_capacity);
    right = allocator.allocate(right_capacity);

    for (const auto& element : vec) {
        push_back(element);  
    }
}


template <typename T, typename Allocator>
deque<T, Allocator>::deque(const deque& other)
{
    left = right = nullptr;
    copy_other(other);    
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(const deque& other , const Allocator& alloc){
    left = right = nullptr;
    copy_other(other, alloc);
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(deque&& other){
    move_other(std::move(other));
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(deque&& other , const Allocator& alloc){
    move_other(std::move(other), alloc);
}

template <typename T, typename Allocator>
deque<T,Allocator>::deque(std::initializer_list<T> init, const Allocator& alloc){
    initialize(init, alloc);
}

template <typename T, typename Allocator>
void deque<T, Allocator>::clear() noexcept{
    if(left || right){
        allocator.deallocate(left, left_capacity);
        allocator.deallocate(right, right_capacity);

        left = right = nullptr;

        left_capacity = right_capacity = 0;
        left_size = right_size = 0;
    }
}

template <typename T, typename Allocator>
deque<T, Allocator>::~deque(){
    clear();
}

template <typename T, typename Allocator>
deque<T, Allocator>& deque<T, Allocator>::operator=(const deque& other){
    if(this != &other){
        copy_other(other);
    }
    return *this;

}

template <typename T, typename Allocator>
deque<T, Allocator>& deque<T, Allocator>::operator=(deque&& other) noexcept{
    if(this != &other){
        move_other(std::move(other));
    }

    return *this;

}

template <typename T, typename Allocator>
deque<T, Allocator>& deque<T, Allocator>::operator=(std::initializer_list<value_type> ilist){
    initialize(ilist);
    return *this;
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::empty() const{
    return left_size == 0 ? true : false;
}

template <typename T, typename Allocator>
deque<T, Allocator>::size_type deque<T, Allocator>::size() const{
    return left_size + right_size;
}

template <typename T, typename Allocator>
deque<T, Allocator>::size_type deque<T, Allocator>::max_size() const{
    return left_capacity + right_capacity;
}

template <typename T, typename Allocator>
deque<T, Allocator>::allocator_type deque<T, Allocator>::get_allocator() const{
    return allocator;
}



template <typename T, typename Allocator>
void deque<T, Allocator>::pop_back(){
    right_size--;

    balance_deque();

}

template <typename T, typename Allocator>
void deque<T, Allocator>::pop_front(){
    left_size--;

    balance_deque();

}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::at(size_type pos){
    auto it = begin();
    return *(it + pos);
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::at(size_type pos) const{
    auto it = cbegin();

    return *(it + pos);
}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::operator[](size_type pos){
    int i = 0;
    auto it = begin();
    while(i < pos && it != end()){
        ++it;
        ++i;
    }

    return *it;
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::operator[](size_type pos) const{
    int i = 0;
    auto it = cbegin();
    while(i < pos && it != cend()){
        ++it;
        ++i;
    }

    return *it;
}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::front(){
    return *(begin());
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::front() const{
    return *(cbegin());
}

template <typename T, typename Allocator>
deque<T, Allocator>::reference deque<T, Allocator>::back(){
    return *(end() - 1);
}

template <typename T, typename Allocator>
deque<T, Allocator>::const_reference deque<T, Allocator>::back() const{
    return *(cend() - 1);
}

template <typename T, typename Allocator>
void deque<T, Allocator>::swap(deque& other) noexcept{

    deque tmp = other;
    other = *this;
    *this = tmp;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::shrink_to_fit() {
    T* new_left = allocator.allocate(left_size);
    T* new_right = allocator.allocate(right_size);

    int i = 0;
    while(i < left_size){
        new_left[i] = left[i];
        ++i;
    }

    i = 0;
    while(i < right_size){
        new_right[i] = right[i];
        ++i;
    }

    

    allocator.deallocate(left, left_capacity);
    allocator.deallocate(right, right_capacity);

    left = new_left;
    right = new_right;
    left_capacity = left_size;
    right_capacity = right_size;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::assign(size_type count, const T& value){
    while(count != 0){
        push_back(value);
        --count;
    }
}

template <typename T, typename Allocator>
template <iter InputIt>
void deque<T, Allocator>::assign(InputIt first, InputIt last){
    while(first != last){
        push_back(*first);
        ++first;
    }
}

template <typename T, typename Allocator>
void deque<T, Allocator>::assign(std::initializer_list<T> ilist){
    for(auto& it : ilist){
        push_back(it);
    }

}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator pos, const T& value){
    
    if(left_size == left_capacity || right_size == right_capacity){
        resize((left_capacity + right_capacity) * 2);
    }

    ++right_size;

    auto it = end() - 1;
    while(it > pos){
       *it = *(it - 1);
       --it;
    }
    *it = value;

    balance_deque();


    return it;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator pos,T&& value){
    
    ++right_size;

    auto it = end() - 1;
    while(it > pos){
       *it = *(it - 1);
       --it;
    }
    *it = value;

    if(left_size == left_capacity || right_size == right_capacity){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();


    return pos;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator pos, size_type count, const T& value){
    
    if(left_size + right_size + count >= left_capacity + right_capacity){
        resize((left_size + right_size + count) * 2);
    }

    int i = 0;
    
    while(i < count){

        ++right_size;
        auto it = end() - 1;

        while(it > pos){
            *it = *(it - 1);
            --it;
        }

        *it = value;
        ++i;
    }

    balance_deque();


    return pos;

}

template <typename T, typename Allocator>
template <iter InputIt>
deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator pos, InputIt first, InputIt last){
    auto it  = first;
    while(it != last){

        ++right_size;
        auto it2 = end() - 1;

        while(it2 > pos){
            *it2 = *(it2 - 1);
            --it2;
        }

        //std::cout << "debug ";

        *it2 = *it;


        if(left_size == left_capacity || right_size == right_capacity){
            resize((left_capacity + right_capacity) * 2);
        }

        ++it;


    }

    balance_deque();


    return pos;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator pos, std::initializer_list<T> ilist){
    if(left_size + right_size + ilist.size() >= left_capacity + right_capacity){
        resize((left_size + right_size + ilist.size()) * 2);
    }

    auto lit = ilist.begin();
    while(lit != ilist.end()){
        
        ++right_size;
        auto it = end() - 1;
        while(it > pos){
            *it = *(it - 1);
            --it;
        }

        *it = *lit;
        ++lit;
    }

    balance_deque();

    return pos;
}

template <typename T, typename Allocator>
template <class... Args>
deque<T, Allocator>::iterator deque<T, Allocator>::emplace(iterator pos, Args&&... args){
    
    ++right_size;
    auto it = end() - 1;

    while(it > pos){
        *it = *(it - 1);
        --it;
    }

    *it = T(std::forward<Args>(args)...);

    if(left_size == left_capacity || right_size == right_capacity){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();

    return it;
}

template <typename T, typename Allocator>
template <class... Args>
deque<T, Allocator>::reference deque<T, Allocator>::emplace_back(Args&&... args){
    
    ++right_size;
    auto it = end() - 1;

    *it = T(std::forward<Args>(args)...);

    if(left_size == left_capacity || right_size == right_capacity){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();


    return *it;
}

template <typename T, typename Allocator>
template <class... Args>
deque<T, Allocator>::reference deque<T, Allocator>::emplace_front(Args&&... args){
    
    ++left_size;
    auto it = begin();

    *it = T(std::forward<Args>(args)...);

    if(left_size == left_capacity || right_size == right_capacity){
        resize((left_capacity + right_capacity) * 2);
    }

    balance_deque();

    return *it;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::erase(iterator pos){

    auto it = pos;
    while(it < end() - 1){
        *it = *(it + 1);
        ++it;
    }

    if(right_size){
            --right_size;
        }else{
            --left_size;
    }

    balance_deque();


    return it;
}

template <typename T, typename Allocator>
deque<T, Allocator>::iterator deque<T, Allocator>::erase(iterator first, iterator last){

    while(first != last){

        auto it = first;
        while(it < end() - 1){
            *it = *(it + 1);
            ++it;
        }

        if(right_size){
            --right_size;
        }else{
            --left_size;
        }

        ++first;

    }

    balance_deque();

    return --first;
}



#endif