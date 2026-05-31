#include <iostream>
#include <windows.h>

void merge(int* arr, int left, int mid, int right, int* temp) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }


    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
}

void merge_sort_rec(int* arr, int left, int right, int* temp) {
    if (left >= right) return; 

    int mid = left + (right - left) / 2;
    merge_sort_rec(arr, left, mid, temp);
    merge_sort_rec(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
}


void merge_sort(int* arr, int size) {
    if (size <= 1) return;
    int* temp = new int[size];
    merge_sort_rec(arr, 0, size - 1, temp);
    delete[] temp; 
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Исходный массив: ";
    print_array(arr1, size1);
    merge_sort(arr1, size1);
    std::cout << "Отсортированный массив: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Исходный массив: ";
    print_array(arr2, size2);
    merge_sort(arr2, size2);
    std::cout << "Отсортированный массив: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Исходный массив: ";
    print_array(arr3, size3);
    merge_sort(arr3, size3);
    std::cout << "Отсортированный массив: ";
    print_array(arr3, size3);

    return 0;
}
