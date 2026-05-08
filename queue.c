#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int rear;
    int front;
    int size;
    int count;
} Queue;

Queue *init(int size);
void enqueue(Queue *q, int data);
int dequeu(Queue *q);
void displayQueue(Queue *q);

int main()
{
    int n = 1;
    Queue *q = NULL;
    while (n)
    {
        printf("\n\t<Menu>\n");
        printf("1.Init/Reset Queue\n2.Enqueue\n3.Dequeu\n4.Display\n5.Exit\n");
        int option = 0;
        printf("##Enter option: ");
        if ((scanf("%d", &option)) != 1)
        {
            while (getchar() != '\n')
                ;
        }

        int size, data;
        int *temp = NULL;
        switch (option)
        {
        case 1:
            if (q != NULL)
            {

                free(q->arr);
                free(q);
                q = NULL;
            }
            printf("Enter size: ");
            scanf("%d", &size);
            q = init(size);
            break;

        case 2:
            if (!q)
            {
                printf("Init queue\n");
                continue;
            }
            if (q->count == q->size)
            {
                printf("Queue-overflow\n");
            }
            else
            {
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
            }
            break;
        case 3:
            if (!q || q->count == 0)
            {
                printf("Queue-underflow\n");
            }
            else
            {
                printf("Dequeue: %d\n", dequeu(q));
            }
            break;
        case 4:
            if (!q)
            {
                printf("Init\n");
            }
            else
            {
                displayQueue(q);
            }
            break;
        case 5:
            n = 0;
            break;
        }
    }
    if (q != NULL)
    {
        free(q->arr);
        free(q);
    }
    return 0;
}

Queue *init(int size)
{
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->arr = (int *)calloc(sizeof(int), size);
    q->count = 0;
    q->front = 0;
    q->size = size;
    q->rear = 0;
    return q;
}
void enqueue(Queue *q, int data)
{
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;
    q->count++;
}
int dequeu(Queue *q)
{
    int temp = q->arr[q->front];
    q->front = (q->front + 1) % q->size;
    q->count--;
    return temp;
}
void displayQueue(Queue *q)
{
    if (q->count == 0)
    {
        printf("The queue is empty\n");
        return;
    }
    printf("\n\t===Display==\n");
    for (int i = 0; i < q->count; i++)
    {
        int index = (q->front + i) % q->size;
        printf("| %d |\n", q->arr[index]);
    }
}