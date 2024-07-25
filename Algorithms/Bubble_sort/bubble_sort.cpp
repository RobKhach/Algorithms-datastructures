#include <iostream>
#include <chrono>

void bubble_sort(std::vector<int> arr, int size){

    bool swaped;
    for(std::size_t i = 0; i < size - 1; ++i){
        swaped = false;

        for(std::size_t j = 0; j < size - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            swaped = true;
            }
        }

        if(!swaped){
            break;
        }

    }

}

void print(std::vector<int> arr, int size, std::string word = ""){
    
    std::cout << word ;
    
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main(){

    const int size = 20000;
    std::vector<int> arr(size);
    std::generate(arr.begin(), arr.end(), std::rand);

    // int arr[] = {1, 2, 34, 0 , 99, 44, 3, 22, 33, 24};
    // int size = sizeof(arr) / sizeof(int);

    
    print(arr, size, "Dont sorted array --> ");

    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    print(arr, size, "Sorted array with bubble sort --> ");


    std::cout << "Time taken by bubbleSort: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}