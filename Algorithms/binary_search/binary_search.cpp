#include <iostream>

void insertion_sort(int* arr, int size)
{

    for(int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }

}


int binary_search(int* arr, int size, int target)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }else if(arr[mid] > target){
            end = mid - 1;

        }else{
            start = mid + 1;
        }
    }

    return -1;
}


int main(){

   // const int size = 7; 
    int arr[] = {100, 2, 77, 4, 1 , 6, 7};
    int size = sizeof(arr) / sizeof(int);

     for(int i = 0; i < size; ++i){
        std:: cout << arr[i] << " ";
    }

    std::cout << std::endl;

    insertion_sort(arr, size);
    for(int i = 0; i < size; ++i){
        std:: cout << arr[i] << " ";
    }

    std::cout << std::endl;

    int target = 0;
    std::cout << "Please enter Target --> " ;
    std::cin >> target;

    int index = binary_search(arr, size, target);
    
    if(index != -1){
        std::cout << "Index element --> " << index << std::endl; 
    }else{
        std::cout << "Target not found " << std::endl;
    }



    return 0;
}