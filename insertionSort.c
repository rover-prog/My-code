#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int sizeOfArray);
void printArray(int *arr, int sizeOfArray);
void scanArray(int *arr, int sizeOfArray);
void assignArray(int *arr, int sizeOfArray);
void insertionSort(int *arr, int sizeOfArray);

int main()
{ 
    int size;
    int *nums;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    nums = createArray(size);
    assignArray(nums, size);
    printf("The Array before sorting\n");
    printArray(nums, size);
    printf("The Array after sorting\n");
    insertionSort(nums, size);
    printArray(nums, size);
    free(nums);

    return 0;
}
int *createArray(int sizeOfArray)
{
    return (int *)malloc(sizeof(int) * sizeOfArray);
}
void printArray(int *arr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void scanArray(int *arr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter the number[%d]: ", (i + 1));
        scanf("%d", &arr[i]);
    }
}
void assignArray(int *arr, int sizeOfArray)
{
    srand(time(NULL));
    for (int i = 0; i < sizeOfArray; i++)
    {
        arr[i] = rand() % 100;
    }
}
void insertionSort(int *arr, int sizeOfArray)
{
    for (int i = 1; i < sizeOfArray; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
