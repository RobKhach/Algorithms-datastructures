#include <iostream>

void insertion_sort(std::vector<int>& arr){

    for(std::size_t i = 1; i < arr.size(); ++i){

        int key = arr[i];
        
        std::size_t j = i - 1;
        while((j >= 0) && (arr[j] < key)){
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = key;

    }

}

int main(){

    std::vector<int> arr{3,2,1,3,4,5,2,19,88,23,1555,0};
 
    for(std::size_t i = 0; i < arr.size(); ++i){

    std::cout << "Not sorted array -> " << arr[i] << std::endl;
   
   }
    
    insertion_sort(arr);

    for(std::size_t i = 0; i < arr.size(); ++i){

    std::cout << "Sprted array -> " << arr[i] << std::endl;

    }

    return 0;
}
