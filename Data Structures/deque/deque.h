#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cstddef>
#include <memory>
#include <vector>
#include <type_traits>
#include <concepts>

template <typename U>
concept iter = requires(U it){
    {*it};
    {++it};
    {--it};
};

template <typename T, typename Allocator = std::allocator<T>>
class deque{

    public:

        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;

        using value_type = T;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = std::allocator_traits<Allocator>::pointer;
        using const_pointer = std::allocator_traits<Allocator>::const_pointer;
        using iterator = iterator;
        using const_iterator = const_iterator;
        using reverse_iterator = reverse_iterator;
        using const_reverse_iterator = const_reverse_iterator;

    public:

        class iterator{
            private:

                pointer current;
                const_pointer right_start;
                const_pointer left_start;
                const_pointer right_end;
                const_pointer left_end;

            protected:

            bool current_in_range() const;
            bool current_in_left() const;
            bool current_in_right() const;

            public:

            iterator();
            iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end);
            iterator(const iterator& other);

            reference operator*();
            const_reference operator*() const;
            reference operator[](difference_type n);
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);

            iterator& operator+=(difference_type n);
            iterator& operator-=(difference_type n);
            iterator operator+(difference_type n) const;
            iterator operator-(difference_type n) const;
            difference_type operator-(const iterator& other) const;

            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other)const;
            bool operator<(const iterator& other) const;
            bool operator>(const iterator& other) const;
            bool operator<=(const iterator& other) const;
            bool operator>=(const iterator& other) const;

        };

        class const_iterator{
            private:

            iterator iter;

            public:

            const_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end);

            const_reference operator*() const;
            const_reference operator[](difference_type n) const;
 
            const_iterator& operator++();
            const_iterator operator++(int);
            const_iterator& operator--();
            const_iterator operator--(int);

            const_iterator operator+(difference_type n);
            const_iterator operator-(difference_type n);
            difference_type operator-(const iterator& other) const;

            bool operator==(const const_iterator& other) const;
            bool operator!=(const const_iterator& other)const;
            bool operator<(const const_iterator& other) const;
            bool operator>(const const_iterator& other) const;
            bool operator<=(const const_iterator& other) const;
            bool operator>=(const const_iterator& other) const;

        };

        class reverse_iterator{
            private:
            
            iterator iter;

            public:

            reverse_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end);

            reference operator*();
            reference operator[](difference_type n);
 
            reverse_iterator& operator++();
            reverse_iterator operator++(int);
            reverse_iterator& operator--();
            reverse_iterator operator--(int);

            reverse_iterator operator+(difference_type n);
            reverse_iterator operator-(difference_type n);
            difference_type operator-(const reverse_iterator& other) const;

            bool operator==(const reverse_iterator& other) const;
            bool operator!=(const reverse_iterator& other)const;
            bool operator<(const reverse_iterator& other) const;
            bool operator>(const reverse_iterator& other) const;
            bool operator<=(const reverse_iterator& other) const;
            bool operator>=(const reverse_iterator& other) const;

        };

        class const_reverse_iterator{
            private:

                const_iterator iter;

            public:

            const_reverse_iterator(pointer current, const_pointer left_start, const_pointer left_end, const_pointer right_start, const_pointer right_end);

            const_reference operator*() const;
            const_reference operator[](difference_type n) const;
 
            const_reverse_iterator& operator++();
            const_reverse_iterator operator++(int);
            const_reverse_iterator& operator--();
            const_reverse_iterator operator--(int);

            const_reverse_iterator operator+(difference_type n);
            const_reverse_iterator operator-(difference_type n);
            difference_type operator-(const const_reverse_iterator& other) const;

            bool operator==(const const_reverse_iterator& other) const;
            bool operator!=(const const_reverse_iterator& other)const;
            bool operator<(const const_reverse_iterator& other) const;
            bool operator>(const const_reverse_iterator& other) const;
            bool operator<=(const const_reverse_iterator& other) const;
            bool operator>=(const const_reverse_iterator& other) const;
        };

    private:

    bool odd(size_type num)const;
    int get_balance() const;
    void balance_deque();
    void copy_other(const deque& other, const Allocator& alloc = Allocator());
    void move_other(deque&& other, const Allocator& alloc = Allocator());
    void initialize(std::initializer_list<value_type> init, const Allocator& alloc = Allocator());

    private:

    T* left;
    T* right;

    size_type left_size;
    size_type right_size;

    size_type left_capacity;
    size_type right_capacity;

    Allocator allocator;

    public:

        deque();
        explicit deque(size_type count, const T& value, const Allocator& alloc = Allocator());
        explicit deque(size_type count, const Allocator& alloc = Allocator());
        
        template <iter InputIt>
        explicit deque(InputIt first, InputIt last, const Allocator& alloc = Allocator());
        deque(const deque& other);
        deque(const deque& other , const Allocator& alloc);
        deque(deque&& other);
        deque(deque&& other, const Allocator& alloc);
        deque(std::initializer_list<T> init, const Allocator& alloc = Allocator());

        ~deque();


        deque& operator=(const deque& other);
        deque& operator=(deque&& other) noexcept;
        deque& operator=(std::initializer_list<value_type> ilist);

        void assign(size_type count, const T& value);
        template <iter InputIt>
        void assign(InputIt first, InputIt last);
        void assign(std::initializer_list<T> ilist);


        allocator_type get_allocator() const;


        reference at(size_type pos);
        const_reference at(size_type pos) const;
        reference operator[](size_type pos);
        const_reference operator[](size_type pos) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;


        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void shrink_to_fit();

        void clear() noexcept;

        iterator insert(iterator pos, const T& value);
        iterator insert(iterator pos, T&& value);
        iterator insert(iterator pos, size_type count, const T& value);
        template <iter InputIt>
        iterator insert(iterator pos, InputIt first, InputIt last);
        iterator insert(iterator pos, std::initializer_list<T> ilist);

        template <class... Args>
        iterator emplace(iterator pos, Args&&... args);

        iterator erase(iterator pos);
        iterator erase(iterator first, iterator last);

        void push_back(const T& value);
        void push_back(T&& value);

        template <class... Args>
        reference emplace_back(Args&&... args);

        void pop_back();

        void push_front(const T& value);
        void push_front(T&& value);

        template<class... Args>
        reference emplace_front(Args&&... args);

        void pop_front();

        void resize(size_type count);
        void resize(size_type count, const T& value);

        void swap(deque& other) noexcept;

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
};

#include "deque.hpp"

#endif