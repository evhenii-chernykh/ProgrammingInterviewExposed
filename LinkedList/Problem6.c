/*
 * You are given a linked list with at least one node that is either nullterminated
 * (acyclic), or ends in a cycle (cyclic). Write a function that takes a pointer to 
 * the head of a list and determines whether the list is cyclic or acyclic. Your 
 * function should return false if the list is acyclic and true if it is cyclic. You 
 * may not modify the list in any way.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int isCyclic(Node *head)
{
    Node *slow, *fast;
    assert(head);
    slow = head;
    fast = head->next;
    while (1)
    {
        if (!fast || !fast->next)
        {
            return 0;
        }
        else if (fast == slow || fast->next == slow)
        {
            return 1;
        }
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}

int main(void)
{
    Node *head, *tail, *midleNode, *node;
    int i;
    head = tail = NULL;
    for (i = 0; i < 123; i++)
    {
        midleNode = malloc(sizeof(*midleNode));
        if (!midleNode)
        {
            fprintf(stderr, "Memory out!!!\nExiting...\n");
            exit(EXIT_FAILURE);
        }
        if (i == 0)
        {
            tail = midleNode;
        }
        midleNode->data = i;
        midleNode->next = head;
        head = midleNode;
    }
    for (i = 0; i < 123; i++)
    {
        node = malloc(sizeof(*node));
        if (!node)
        {
            fprintf(stderr, "Memory out!!!\nExiting...\n");
            exit(EXIT_FAILURE);
        }
        node->data = i;
        node->next = head;
        head = midleNode;
    }
    
    printf("No circle test = %d\n", isCyclic(head));
    tail->next = midleNode;
    printf("Circle test = %d\n", isCyclic(head));
    return EXIT_SUCCESS;
}
