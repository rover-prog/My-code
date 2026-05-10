#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int sizeOfArray);
void printArray(int *arr, int sizeOfArray);
void scanArray(int *arr, int sizeOfArray);
void assignArray(int *arr, int sizeOfArray);
int partition(int *arr, int start, int end);
void quickSort(int *arr, int start, int end);

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
    quickSort(nums, 0, size - 1);
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
int partition(int *arr, int start, int end)
{
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= arr[end])
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}
