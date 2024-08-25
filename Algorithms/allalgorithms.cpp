#include <iostream>

void bubble_sort(std::vector<int>& arr){
    bool flag = true;
    for(int i = 0; i < arr.size() - 1; ++i){

        for(int j = 0; j < arr.size() - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }

        if(flag){
            break;
        }else{
            flag = true;
        }
    }
}

void selection_sort(std::vector<int>& arr){
    for(int i = 0; i < arr.size() - 1; ++i){
        int min = i;
        for(int j = i + 1; j < arr.size(); ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[min], arr[i]);
    }
}

void insertion_sort(std::vector<int>& arr){
    for(int i = 1; i < arr.size(); ++i){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

bool binary_search(std::vector<int>& arr, int left, int right, int target){
    if(left > right){
        return false;
    }

    int mid = left + (right - left) / 2;
    if(arr[mid] == target){ return true;}
    else if(arr[mid] > target){return binary_search(arr, left, mid - 1, target);}
    else{return binary_search(arr, mid + 1, right, target);}
   
}

void counting_sort(std::vector<int>& arr){
    int max = arr[0];
    for(int i = 1; i < arr.size(); ++i){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    std::vector<int> count(max + 1, 0);
    for(int i = 0; i < arr.size(); ++i){
        ++count[arr[i]];
    }

    for(int i = 0; i < count.size() - 1; ++i){
        count[i + 1] += count[i];
    }

    std::vector<int> out(arr.size());
    for(int i = 0; i < arr.size(); ++i){
        out[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    arr = out;
}

void merge(std::vector<int>& arr, int first, int mid, int last){

    int size_left = mid - first + 1;
    int size_right = last - mid;
    std::vector<int> left(size_left);
    std::vector<int> right(size_right);

    int i = 0;
    while(i < size_left){
        left[i] = arr[first + i];
        ++i;
    }

    int j = 0;
    while(j < size_right){
        right[j] = arr[mid + 1 + j];
        ++j;
    }

    int k = first;
    j = 0;
    i = 0;
    while(i < size_left && j < size_right){
        if(left[i] > right[j]){
            arr[k++] = right[j++];
        }else{
            arr[k++] = left[i++];   
        }
    }

    while(i < size_left){
        arr[k++] = left[i++];
    }

    while(j < size_right){
        arr[k++] = right[j++];
    }
}

void merge_sort(std::vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1,right);
        merge(arr, left, mid, right);
    }
}

void print(std::vector<int>& arr){
    for(int i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void shafl(std::vector<int>& arr){
    int i = 0;
    int j = arr.size() - 1;

    while(i < j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i += 2; --j;
    }
}

int main(){

    std::vector<int> arr{1, 5, 3, 8, 4, 9, 2, 99, 77, 22};

    std::cout << "Dont sorted array -- >";
    print(arr);

    std::cout << "Sorted array by Bubble sort-- >";
    bubble_sort(arr);
    print(arr);

    std::cout << "Dont sorted array -- >";
    shafl(arr);
    print(arr);

    std::cout << "Sorted array by Selection sort-- >";
    selection_sort(arr);
    print(arr);

    std::cout << "Dont sorted array -- >";
    shafl(arr);
    print(arr);

    std::cout << "Sorted array by Insertion sort-- >";
    insertion_sort(arr);
    print(arr);

    std::cout << "Arr contains 99? -- >";
    std::cout << (binary_search(arr, 0, arr.size() - 1, 99)?"Yes":"No") << std::endl;

    std::vector<int> arr1{5, 5, 5, 5, 5, 4, 4, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1};
    std::cout << "Dont sorted array -- >";
    shafl(arr1);
    print(arr1);

    std::cout << "Sorted array by Counting sort-- >";
    counting_sort(arr1);
    print(arr1);

    std::cout << "Dont sorted array -- >";
    shafl(arr);
    print(arr);

    std::cout << "Sorted array by Merge sort-- >";
    merge_sort(arr, 0, arr.size() - 1);
    print(arr);




}