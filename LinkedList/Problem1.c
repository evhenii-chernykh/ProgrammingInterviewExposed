/*
 * PROBLEM head and tail are global pointers to the first and last element, respectively,
 * of a singly linked list of integers. Implement C functions for the following prototypes:
 *
 * int delete( Node *node );
 * int insertAfter( Node *node, int data );
 *
 * The argument to delete is the element to be deleted. The two arguments to
 * insertAfter give the element after which the new element is to be inserted and
 * the data for the new element. It should be possible to insert at the beginning of the
 * list by calling insertAfter with NULL as the element argument. These functions
 * should return a boolean indicating success.
 *Your functions must keep the head and tail pointers current.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head, *tail;

int deleteNode(Node *node)
{
    Node *curPos = head;
    if (!node)
    {
        return 0;
    }

    /* Deleting from head. */
    if (node == head)
    {
        head = head->next;
        free(node);
        /* If we have one node list. */
        if (!head)
        {
            tail = NULL;
        }
        return 1;
    }

    while (curPos)
    {
        if (curPos->next == node)
        {
            curPos->next = node->next;
            free(node);
            /* If we delete last node. */
            if (!curPos->next)
            {
                tail = curPos;
            }
            return 1;
        }
        curPos = curPos->next;
    }

    return 0;
}

int insertAfter(Node *node, int data)
{
    Node *newNode, *curPos;

    newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        return 0;
    }
    newNode->data = data;

    /* inserting to beginning of the list */
    if (!node)
    {
        newNode->next = head;
        head = newNode;

        /* inserting into empty list */
        if (tail == NULL)
        {
            tail = newNode;
        }
        return 1;
    }

    curPos = head;
    while (curPos)
    {
        if (curPos == node)
        {
            newNode->next = curPos->next;
            curPos->next = newNode;
            /* If we insert after last node. */
            if (curPos == tail)
            {
                tail = newNode;
            }
            return 1;
        }
        curPos = curPos->next;
    }

    return 0;
}

void printList(void)
{
    Node *node = head;
    putchar('[');
    while (node)
    {
        if (node->next)
        {
            printf("%i, ", node->data);
        }
        else
        {
            printf("%i", node->data);
        }
        node = node->next;
    }
    putchar(']');
}

int main(void)
{
    Node *node;
    int cnt;
    head = tail = NULL;
    printf("List is: ");
    printList();
    printf(".\nInit list.\n");
    for (cnt = 1; cnt <= 5; cnt++)
    {
        insertAfter(NULL, cnt);
        if (cnt == 3)
        {
            node = head;
        }
    }
    printf("List is: ");
    printList();
    printf("\n");
    return 0;
}