#include <iostream>
#include <stdexcept>

template <typename T>
class dynamic_array {
public:
    dynamic_array() {
        arr_size = 0;
        arr_capacity = 2;
        arr = new T[arr_capacity];
    }

    dynamic_array(int capacity) {
        arr_size = 0;
        this->arr_capacity = capacity;
        arr = new T[capacity];
    }

    dynamic_array(int size, T value) {
        arr_size = size;
        arr_capacity = size;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = value;
        }
    }

    dynamic_array(const dynamic_array<T>& other) {
        arr_size = other.arr_size;
        arr_capacity = other.arr_capacity;
        arr = new T[arr_capacity];
        for (int i = 0; i < arr_size; ++i) {
            arr[i] = other.arr[i];
        }
}

    void reserve(int new_capacity) {
        if (new_capacity > arr_capacity) {
            resize(new_capacity);
        } else {
            throw std::runtime_error("New capacities cannot be less than previous");
        }
    }

    int capacity() const {
        return arr_capacity;
    }

    bool include(T value) const {
        for (int i = 0; i < arr_size; ++i) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    void emplace(int index, T data) {
        if (index >= 0 && index < arr_size) {
            if (arr_size == arr_capacity) {
                resize(arr_capacity * 2);
            }
            for (int i = arr_size; i > index; --i) {
                arr[i] = arr[i - 1];
            }
            arr[index] = data;
            ++arr_size;
        } else {
            throw std::out_of_range("Index is out of range");
        }
    }

    dynamic_array<T>& operator=(const dynamic_array<T>& other) {
        if (this == &other) {
            return *this;
        }

        arr_size = other.arr_size;
        arr_capacity = other.arr_capacity;

        if (arr != nullptr) {
            delete[] arr;
        }

        arr = new T[arr_capacity];
        for (int i = 0; i < arr_size; ++i) {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            os << arr[i] << " ";
        }
        os << std::endl;
        return os;
    }

    void insert(int index, T data) {
        emplace(index, data);
    }

    void push_back(T data) {
        if (arr_size == arr_capacity) {
            resize(arr_capacity * 2);
        }
        arr[arr_size++] = data;
    }

    void pop_back() {
        if (arr_size > 0) {
            --arr_size;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= arr_size) {
            throw std::out_of_range("Invalid index");
        } else if (arr_size > 1) {
            for (int i = index; i < arr_size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --arr_size;
        } else {
            --arr_size;
        }
    }

    void clear() {

        if(arr != nullptr){
            delete[] arr;
            arr = nullptr;
        }
        arr_size = 0;
        arr_capacity = 0;
    }

    int size() const {
        return arr_size;
    }

    bool isempty() const {
        return arr_size == 0;
    }

    T& operator[](int index) const {
        if (index >= 0 && index < arr_size) {
            return arr[index];
        } else {
            throw std::out_of_range("Invalid index");
        }
    }

    void shrink_to_fit() {
        resize(arr_size);
    }

    ~dynamic_array() {
        clear();
    }

    T top(){
        if(!isempty()){
            return arr[--arr_size];
        }else{
            throw std::runtime_error("arr is empty");
        }
    }

private:
    void resize(int new_capacity) {
        if (new_capacity <= 0) {
            throw std::invalid_argument("New capacity must be greater than 0");
        }

        if (new_capacity == arr_capacity) {
            return;
        }

        T* tmp = new T[new_capacity];
        int elements_to_copy = (new_capacity < arr_size) ? new_capacity : arr_size;

        for (int i = 0; i < elements_to_copy; ++i) {
            tmp[i] = arr[i];
        }

        delete[] arr;
        arr = tmp;
        arr_capacity = new_capacity;
        if (arr_size > new_capacity) {
            arr_size = new_capacity;
        }
    }

    T* arr;
    int arr_size;
    int arr_capacity;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const dynamic_array<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        os << arr[i] << " ";
    }
    os << std::endl;
    return os;
}
