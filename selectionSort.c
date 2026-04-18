#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int sizeOfArray);
void printArray(int *arr, int sizeOfArray);
void scanArray(int *arr, int sizeOfArray);  
void assignArray(int *arr, int sizeOfArray);
void selectionSort(int *arr, int sizeOfArray);
// function for selection sort

int main()
{
    int sizeOfArray;
    int *nums;
    printf("Enter the size of the array: ");
    scanf("%d", &sizeOfArray);
    nums = createArray(sizeOfArray);
    assignArray(nums, sizeOfArray);
    printf("The Array before sorting\n");
    printArray(nums, sizeOfArray);
    printf("The Array after sorting\n");
    selectionSort(nums, sizeOfArray);
    printArray(nums, sizeOfArray);
    free(nums);

    return 0;
}
int *createArray(int sizeOfArray)
{
    return (int *)malloc(sizeOfArray * (sizeof(int)));
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
        printf("Enter the number[%d]: ");
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
void selectionSort(int *arr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < sizeOfArray; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}