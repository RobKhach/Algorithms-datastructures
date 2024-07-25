#include <iostream>

void selection_sort(std::vector<int> arr){
    std::size_t size = arr.size();

    for(int i = 0; i < size - 1; ++i){
        int min_idx = i;
        for(int j = i + 1; j < size; ++j){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        } 
        std::swap(arr[i], arr[min_idx]);   
    }

}

void print(std::vector<int> arr, std::string word = ""){
    
    std::cout << word ;
    
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main(){

    const int size = 20000;
    std::vector<int> arr(size);
    std::generate(arr.begin(), arr.end(), std::rand);
    
    print(arr, "Dont sorted array --> ");

    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    print(arr, "Sorted array with selection sort --> ");


    std::cout << "Time taken by selection_sort: " << elapsed.count() << " seconds" << std::endl;


    return 0;
}