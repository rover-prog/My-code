#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int size;
    int top;
} Stack;

void push(Stack *stk, int data);
int pop(Stack *stk);
int isFull(Stack *stk);
int isEmpty(Stack *stk);
Stack *init(int size);
void displayStack(Stack *stk);

int main()
{
    // Menu
    int n = 1;
    Stack *stk = NULL;
    while (n)
    {
        printf("\n\t<Menu>\n");
        printf("Init/Reset stack: 1\nPush: 2\nPop: 3\nDisplay: 4\nResize(Double): 5\nExit: 6\n");
        int operation = 0;
        printf("##Enter operation: ");
        if ((scanf("%d", &operation) != 1))
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int size, data;
        int *temp;
        switch (operation)
        {
        case 1:
            if (stk != NULL)
            {

                free(stk->arr);
                free(stk);
                stk = NULL;
            }
            printf("Enter size: ");
            scanf("%d", &size);
            stk = init(size);
            break;
        case 2:
            if (!stk)
            {
                printf("Start stack first\n");
                continue;
            }
            if (isFull(stk))
            {
                printf("The stack-overflow\n");
            }
            else
            {
                printf("Enter data for push: ");
                scanf("%d", &data);
                push(stk, data);
            }
            break;
        case 3:
            if (!stk || isEmpty(stk))
            {
                printf("The stack-underflow\n");
            }
            else
            {
                printf("The data after pop: %d\n", pop(stk));
            }
            break;
        case 4:
            if (stk != NULL)
            {
                printf("===Display===\n");
                displayStack(stk);
            }
            else
            {
                printf("Start stack\n");
            }
            break;
        case 5:
            if (!stk)
                break;
            temp = realloc(stk->arr, 2 * stk->size * sizeof(int));
            if (temp == NULL)
            {
                printf("Reallocation failed.\n");
            }
            else
            {
                stk->arr = temp;
                stk->size *= 2;
                printf("The new size: %d", stk->size);
            }
            break;
        case 6:
            n = 0;
            break;
        }
    }
    if (stk != NULL)
    {
        free(stk->arr);
        free(stk);
    }
    return 0;
}
void push(Stack *stk, int data)
{
    stk->arr[++(stk->top)] = data;
}
int pop(Stack *stk)
{
    return stk->arr[(stk->top)--];
}
int isFull(Stack *stk)
{
    return (stk->top == stk->size - 1);
}
int isEmpty(Stack *stk)
{
    return (stk->top == -1);
}
Stack *init(int size)
{
    Stack *stk = (Stack *)calloc(sizeof(Stack), 1);
    int *arr = (int *)calloc(sizeof(int), size);
    stk->arr = arr;
    stk->top = -1;
    stk->size = size;
    return stk;
}
void displayStack(Stack *stk)
{
    if (isEmpty(stk))
    {
        printf("The stack is empty\n");
        return;
    }

    for (int i = stk->top; i >= 0; i--)
    {
        printf("| %d |\n", stk->arr[i]);
    }
}