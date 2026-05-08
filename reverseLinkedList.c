#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int length;
} LinkedList;
LinkedList *initiateList();
void printLinkedList(LinkedList *a);
void insertFirst(LinkedList *a, int data);
void insertLast(LinkedList *a, int data);
void deleteFirst(LinkedList *a);
void deleteLast(LinkedList *a);
void reveseLinkedList(LinkedList *a);
int main()
{
    LinkedList *startNode = initiateList();
    insertLast(startNode, 50);
    insertFirst(startNode, 40);
    insertFirst(startNode, 30);
    insertFirst(startNode, 20);
    insertFirst(startNode, 10);
    insertLast(startNode, 100);
    printLinkedList(startNode);
    reveseLinkedList(startNode);
    printLinkedList(startNode);
    return 0;
}
void printLinkedList(LinkedList *a)
{
    Node *tempNode = a->head;
    while (tempNode != NULL)
    {
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->link;
    }
    printf("NULL\n");
}
void insertFirst(LinkedList *a, int data)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->data = data;
    newNode->link = a->head;
    a->head = newNode;
    (a->length)++;
    if (a->length == 1)
    {
        a->tail = a->head;
    }
}
void insertLast(LinkedList *a, int data)
{
    if (a->length == 0)
    {
        insertFirst(a, data);
    }
    else
    {
        Node *newNode = (Node *)calloc(sizeof(Node), 1);
        newNode->data = data;
        newNode->link = NULL;
        a->tail->link = newNode;
        a->tail = newNode;
        (a->length)++;
    }
}
LinkedList *initiateList()
{
    LinkedList *a = calloc(sizeof(LinkedList), 1);
    return a;
}
void deleteFirst(LinkedList *a)
{
    if (a->head == NULL)
    {
        return;
    }

    Node *temp = a->head;
    a->head = a->head->link;
    free(temp);
    (a->length)--;
    if (a->length == 0)
    {
        a->tail = NULL;
    }
}

void reveseLinkedList(LinkedList *a)
{
    Node *curr = a->head;
    Node *prev = NULL;
    Node *next = curr->link;
    a->tail = a->head;
    while (next != NULL)
    {
        curr->link = prev;
        prev = curr;
        curr = next;
        next = curr->link;
    }
    curr->link = prev;
    a->head = curr;
}