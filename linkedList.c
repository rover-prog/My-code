#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *Link;
} Node;
typedef struct linkedList
{
    int Length;
    Node *Head;
    Node *Tail;
} linkedList;

void printLinkedList(linkedList *a);
void insertFirst(linkedList *a, int data);
void insertLast(linkedList *a, int data);
void deleteFirst(linkedList *a);
void deleteLast(linkedList *a);
void deleteNode(linkedList *a, int index);
linkedList *initiateList();

int main()
{
    linkedList *startNode = initiateList();
    insertLast(startNode, 50);
    insertFirst(startNode, 40);
    insertFirst(startNode, 30);
    insertFirst(startNode, 20);
    insertFirst(startNode, 10);
    insertLast(startNode, 100);
    printLinkedList(startNode);

    deleteFirst(startNode);
    printLinkedList(startNode);

    deleteLast(startNode);
    printLinkedList(startNode);

    int index = 0;
    scanf("%d", &index);
    deleteNode(startNode, index);
    printLinkedList(startNode);

    return 0;
}

void printLinkedList(linkedList *a)
{
    Node *tempNode = a->Head;
    while (tempNode != NULL)
    {
        printf("%d -> ", tempNode->Data);
        tempNode = tempNode->Link;
    }
    printf("NULL\n");
}
void insertFirst(linkedList *a, int data)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->Data = data;
    newNode->Link = a->Head;
    a->Head = newNode;
    (a->Length)++;
    if (a->Length == 1)
    {
        a->Tail = a->Head;
    }
}
void insertLast(linkedList *a, int data)
{
    if (a->Length == 0)
    {
        insertFirst(a, data);
    }
    else
    {
        Node *newNode = (Node *)calloc(sizeof(Node), 1);
        newNode->Data = data;
        newNode->Link = NULL;
        a->Tail->Link = newNode;
        a->Tail = newNode;
        (a->Length)++;
    }
}
linkedList *initiateList()
{
    linkedList *a = calloc(sizeof(linkedList), 1);
    return a;
}
void deleteFirst(linkedList *a)
{
    if (a->Head == NULL)
    {
        return;
    }

    Node *temp = a->Head;
    a->Head = a->Head->Link;
    free(temp);
    (a->Length)--;
    if (a->Length == 0)
    {
        a->Tail = NULL;
    }
}
void deleteNode(linkedList *a, int index)
{
    if (a->Length <= index || index < 0)
    {
        printf("Invalid index of Node.\n");
        return;
    }
    else if (index == 0)
    {
        deleteFirst(a);
    }
    else if (index == a->Length - 1)
    {
        deleteLast(a);
    }
    else
    {
        Node *target, *prev;
        prev = a->Head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->Link;
        }
        target = prev->Link;
        prev->Link = target->Link;
        a->Length--;
        free(target);
    }
}
void deleteLast(linkedList *a)
{
    if (a->Length <= 1)
    {
        deleteFirst(a);
    }
    else
    {
        Node *temp;
        temp = a->Head;
        for (int i = 0; i < a->Length - 2; i++)
        {
            temp = temp->Link;
        }
        temp->Link = NULL;
        free(a->Tail);
        a->Tail = temp;
        a->Length--;
    }
}