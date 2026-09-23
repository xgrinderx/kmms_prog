#include "sortings.hpp"
#include <utility>

void biv::heap(int* const arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}
void biv::heap_sort(int* const arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heap(arr, size, i);
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}