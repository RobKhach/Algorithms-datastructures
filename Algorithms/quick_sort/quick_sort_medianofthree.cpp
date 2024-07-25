#include <iostream>

int MedianOfThree(int* arr, int left, int right){

    int mid = left + (right - left) / 2;

    if(arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);
    if(arr[left] > arr[right])
        std::swap(arr[left], arr[right]);
    if(arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    return mid;
}

int partition(int* arr, int left, int right){
    
    int pivotindex = MedianOfThree(arr, left, right);
    int pivotvalue = arr[pivotindex];

    std::swap(arr[pivotindex], arr[right]);

    int storeIndex = left;

    for(int i = left; i < right; ++i){
        if(arr[i] < pivotvalue){
            std::swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }

    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

void quick_sort(int* arr, int left, int right){

    if(left < right)
    {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }

}

int main(){

    int arr[] = {3, 4, 2, 1, 2, 1, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 7, 7 ,1, 1, 1 };
    int size = sizeof(arr) / sizeof(int);

    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    quick_sort(arr,0, size);
    std::cout << std::endl;

     for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }



    return 0;
}