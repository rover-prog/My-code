#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int* createArray(int size);
void printArray(int* arr, int size);
void scanArray(int* arr, int size);
void assignRandomValue(int* arr, int size);
void swap(int* a, int* b);
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);
void heapSort(int arr[], int n);

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = createArray(size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    assignRandomValue(arr, size);
    printf("Array with random values:\n");
    printArray(arr, size);

    heapSort(arr, size);
    printf("Array after heap sort:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}

// Function definitions

// Function to create a dynamic array
int* createArray(int size) {
    return (int*)malloc(size * sizeof(int));
}

// Function to print the array
void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to scan values into the array
void scanArray(int* arr, int size) {
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to assign random values to the array
void assignRandomValue(int* arr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random values between 0 and 99
    }
}

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build heap function
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

