#include <iostream>

void swap(float *a, int *b) {
    float temp = *a;   // Store the value of *a
    *a = (float)(*b);  // Assign the integer value to the float pointer
    *b = (int)temp;    // Assign the float value (cast to int) to the integer pointer
}

int partition(int* arr, int low, int high){
    
    int pivot = arr[low];

    int i = 0;
    int j = high;

    while(i < j){

        do{
            ++i;
        }while(arr[i] < pivot);

        do{
            --j;
        }while(arr[j] > pivot);

        for(int i = 0 ; i < high; ++i){
            std::cout << " " << arr[i];
        }

        std::cout << std::endl;


        if(i < j){
            std::swap(arr[i], arr[j]);
        }

    }

    swap(&arr[j], &arr[low]);
    
    for(int i = 0 ; i < high; ++i){
        std::cout << " " << arr[i];
    }

    std::cout << std::endl;

    return j;
}

void quick_sort(int* arr, int low, int high){

    if(low < high){

        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi);
        quick_sort(arr, pi + 1, high);
    }
}


int main(){

    int arr[] = {11, 21, 89, 34, 41, 22, 1};

    const int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Dont sorted Array ---> ";
    for(int i = 0 ; i < size; ++i){
        std::cout << " " << arr[i];
    }

    std::cout << std::endl;

    quick_sort(arr, 0 , size);

    std::cout << "Sorted Array ---> ";
    for(int i = 0 ; i < size; ++i){
        std::cout << " " << arr[i];
    }

    std::cout << std::endl;

    return 0;
}