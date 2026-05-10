#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
int *createArray(int size);
void scanArray(int *arr, int size);
void printArray(int *arr, int size);
void assignValueToArray(int *arr, int size);
void bubbleSort(int *arr, int count, bool vFlag);
int main()
{
    int *array;
    int size;
    bool vFlag = false;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    array = createArray(size);
    // assignValueToArray(array, size);
    scanArray(array, size);
    printArray(array, size);
    printf("The Array before sorting:\n");
    printArray(array, size);
    printf("Type 1 for turning step visuals otherwise 0: ");
    int temp;
    scanf("%d", &temp);
    if (temp != 0)
    {
        vFlag = true;
    }
    printf("The Array After sorting:\n");
    bubbleSort(array, size, vFlag);
    printArray(array, size);
    free(array);
    return 0;
}
int *createArray(int size)
{
    return (int *)calloc(sizeof(int), size);
}
void scanArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter Array element number[%d]", (i + 1));
        scanf("%d", &arr[i]);
    }
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void assignValueToArray(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 10);
    }
}
void bubbleSort(int *arr, int count, bool vFlag)
{

    for (int i = 0; i < count; i++)
    {
        bool swapFlag = true;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapFlag = false;
            }
        }
        if (swapFlag)
        {
            break;
        }
        if (vFlag)
        {
            printArray(arr, count);
        }
    }
}