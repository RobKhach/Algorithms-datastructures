#include <iostream>
//[1, 100, 50, 1, 1, 50]
// []
void counting_sort(int* arr, int size){
    int max = 0;
    for(int i = 0; i < size; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
    }

     std::vector<int> count(max + 1, 0);

    // for(int i = 0; i < max + 1; ++i){
    //     count[i] = 0;
    // }

    for(int i = 0; i < size; ++i){
        ++count[arr[i]];
    }

         int index = 0;
        for(int j = 0; j <= max; ++j){
            if(count[j] != 0 ){
                for(int k = 0; k < count[j]; ++k){
                    arr[index] = j;
                    ++index;
                }
            }
        }
    
}

int main(){

    int arr[] = {3, 4, 2, 1, 2, 1, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 7, 7 ,1, 1, 1 };
    int size = sizeof(arr) / sizeof(int);

    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    counting_sort(arr, size);
    std::cout << std::endl;

     for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }


    return 0;
}