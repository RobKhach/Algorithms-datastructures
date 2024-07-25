#include <iostream>

void merge(int* arr, int left, int mid, int right){
     
     int size_left = mid - left + 1;
     int size_right = right - mid;

     int* left_arr = new int[size_left];
     int* right_arr = new int[size_right];

     int i = 0;
     int j = 0;
     
     while(i < size_left){
        left_arr[i] = arr[i + left];
        ++i;
     }

     while(j < size_right){
        right_arr[j] = arr[mid + j + 1];
        ++j;
     }

     i = 0;
     j = 0;
     int k = left;

     while(i < size_left && j < size_right){
       
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            ++i;
        }else{
            arr[k] = right_arr[j];
            ++j;
        }

        ++k;
     }

     while(i < size_left){
        arr[k] = left_arr[i];
        ++i;
        ++k;
     }

     while(j < size_right){
        arr[k] = right_arr[j];
        ++j;
        ++k;
     }

    delete[] right_arr;
    delete[] left_arr;

}

void merge_sort(int* arr, int left, int right){

    if(left < right){
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

}

int main(){

    int arr[] = {99, 24 , 11, 76, 8, 63, 22};
    const int size = sizeof(arr) / sizeof(arr[0]);


    std::cout << "Dont sorted Array ---> ";
    for(int i = 0 ; i < size; ++i){
        std::cout << " " << arr[i];
    }

    std::cout << std::endl;

    merge_sort(arr, 0 , size);

     std::cout << "Sorted Array ---> ";
    for(int i = 0 ; i < size; ++i){
        std::cout << " " << arr[i];
    }

    std::cout << std::endl;




    return 0;
}