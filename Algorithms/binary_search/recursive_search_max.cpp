#include <iostream>

void bubble_sort(int* arr, int size){

    bool swaped;
    for(int i = 0; i < size - 1; ++i){
        swaped = false;
        for(int j = 0; j < size - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }
        if(!swaped){
            break;
        }
    }
}

int rec_binary_search(int* arr, int left, int right, int target){
    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        return rec_binary_search(arr, left, mid - 1, target);
    }else{
        return rec_binary_search(arr, mid + 1, right, target);
    }
}

int main(){

    int arr[] = {8, 6, 5, 4, 2, 99, 88, 55, 10000};
    const int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    int element = 0;
    std::cout << "Please Enter elemend wich you want finde ---> ";
    std::cin >> element;

   std::cout << "Index of Element (if -1 element don't found) ---> " <<  rec_binary_search(arr, 0, size - 1, element) << std::endl;


    return 0;
}