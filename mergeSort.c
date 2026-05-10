#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int sizeOfArray);
void printArray(int *arr, int sizeOfArray);
void scanArray(int *arr, int sizeOfArray);
void assignArray(int *arr, int sizeOfArray);
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

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
    mergeSort(nums, 0, size-1);
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
void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1];
    int right[n2];
    for (int i = start, j = 0; i <= mid, j < n1; i++, j++)
    {
        left[j] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid+1+i];
    }
    int k = start, i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}