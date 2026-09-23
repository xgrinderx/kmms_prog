#include <iostream>
#include <utility>

void my_sort(int* arr, int size);
void heap_s(int* arr, int n, int i);

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Вводите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    int* original = new int[size];
    for (int i = 0; i < size; ++i) {
        original[i] = arr[i];
    }
    my_sort(arr, size);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << original[i] << (i + 1 < size ? ", " : "");
    }
    std::cout << std::endl;
    std::cout << "Отсортированный: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i + 1 < size ? ", " : "");
    }
    std::cout << std::endl;
    delete[] original;
    delete[] arr;
    return 0;
}

void heap_s(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heap_s(arr, n, largest);
    }
}

void my_sort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heap_s(arr, size, i);
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heap_s(arr, i, 0);
    }
}