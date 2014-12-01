/*
 * PROBLEM Given a singly linked list, devise a time- and space-efficient algorithm
 * to find the mth-to-last element of the list. Implement your algorithm, taking care
 * to handle relevant error conditions. Define mth to last such that when m = 0 the
 * last element of the list is returned.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *findMToLastElement(Node *head, int m)
{
    Node *tail = head;
    if (!head)
    {
        return NULL;
    }

    for (; m > 0; m--)
    {
        if (!tail->next)
        {
            return NULL;
        }
        tail = tail->next;
    }

    while (tail->next)
    {
        head = head->next;
        tail = tail->next;
    }

    return head;
}

void printList(Node *head)
{
    printf("List is: [");
    for (;head; head = head->next)
    {
        if (head->next)
        {
            printf("%i, ", head->data);
        }
        else
        {
            printf("%i", head->data);
        }
    }
    printf("]\n");
}

int main(void)
{
    Node *head = NULL, *elem;
    int cnt;
    printf("Making empty list\n");
    printList(head);
    printf("Try to get 3 to last element.\n");
    elem = findMToLastElement(head, 3);
    if (elem)
    {
        printf("This element is %d.\n", elem->data);
    }
    else
    {
        printf("This element does not exists.\n");
    }
    printf("Making one element list\n");
    elem = malloc(sizeof(*elem));
    if (!elem)
    {
        fprintf(stderr, "Memory out!\nExiting.\n");
        exit(EXIT_FAILURE);
    }
    elem->data = 0;
    elem->next = NULL;
    head = elem;
    elem = NULL;
    printList(head);
    printf("Try to get 0 to last element.\n");
    elem = findMToLastElement(head, 0);
    if (elem)
    {
        printf("This element is %d.\n", elem->data);
        elem = NULL;
    }
    else
    {
        printf("This element does not exist.\n");
    }
    printf("Adding five new elements to list\n");
    for (cnt = 1; cnt <= 5; cnt++)
    {
        Node *node = malloc(sizeof(*node));
        if (!node)
        {
            fprintf(stderr, "Memory out!\nExiting.\n");
            exit(EXIT_FAILURE);
        }
        node->data = cnt;
        node->next = head;
        head = node;
    }
    printList(head);
    for (cnt = 0; cnt <= 6; cnt++)
    {
        printf("Try to get %d to last element\n", cnt);
        elem = findMToLastElement(head, cnt);
        if (elem)
        {
            printf("This element is %d.\n", elem->data);
            elem = NULL;
        }
        else
        {
            printf("This element does not exist\n");
        }
    }

    return EXIT_SUCCESS;
}
