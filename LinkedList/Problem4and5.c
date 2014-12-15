/*
 * PROBLEM Start with a standard doubly linked list. Now imagine that in addition
 * to the next and previous pointers, each element has a child pointer, which
 * may or may not point to a separate doubly linked list. These child lists may have
 * one or more children of their own, and so on, to produce a multilevel data structure.
 * Flatten the list so that all the nodes appear in a single-level, doubly linked list. You
 * are given the head and tail of the first level of the list. Each node is a C struct
 * with the following definition:
 * 
 *     typedef struct Node {
 *         struct Node *next;
 *         struct Node *prev;
 *         struct Node *child;
 *         int value;
 *     } Node;
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    struct Node *child;
    int value;
} Node;

void printList(Node *head)
{
    printf("[");
    for (; head; head = head->next)
    {
        if (head->next)
        {
            printf("%d, ", head->value);
        }
        else
        {
            printf("%d", head->value);
        }
    }
    printf("]\n");
}

Node *makeNode(Node *next, Node *prev, Node *child, int value)
{
    Node *node = malloc(sizeof(struct Node));
    if (!node)
    {
        fprintf(stderr, "Memory out!!!\nExiting.\n");
        exit(EXIT_FAILURE);
    }
    node->next = next;
    node->prev = prev;
    node->child = child;
    node->value = value;
    return node;
}

void flattenList(Node *head, Node **tail)
{
    if (!head || !tail || !*tail)
    {
        return;
    }

    for (; head; head = head->next)
    {
        if (head->child)
        {
            (*tail)->next = head->child;
            head->child->prev = *tail;
            for (; (*tail)->next; (*tail) = (*tail)->next);
        }
    }
}

void separateChilds(Node *node)
{
    for (; node; node = node->next)
    {
        if (node->child)
        {
            node->child->prev->next = NULL;
            node->child->prev = NULL;
            separateChilds(node->child);
        }
    }
}

void unflattenList(Node *head, Node **tail)
{
    separateChilds(head);

    for (; head->next; head = head->next);

    *tail = head;
}

int main(void)
{
    Node *head, *tail;

    Node *node1 = makeNode(NULL, NULL, NULL, 1);
    Node *node2 = makeNode(NULL, NULL, NULL, 2);
    Node *node3 = makeNode(NULL, NULL, NULL, 3);
    Node *node4 = makeNode(NULL, NULL, NULL, 4);
    Node *node5 = makeNode(NULL, NULL, NULL, 5);
    Node *node6 = makeNode(NULL, NULL, NULL, 6);
    Node *node7 = makeNode(NULL, NULL, NULL, 7);
    Node *node8 = makeNode(NULL, NULL, NULL, 8);
    Node *node9 = makeNode(NULL, NULL, NULL, 9);
    Node *node10 = makeNode(NULL, NULL, NULL, 10);
    Node *node11 = makeNode(NULL, NULL, NULL, 11);
    Node *node12 = makeNode(NULL, NULL, NULL, 12);
    Node *node13 = makeNode(NULL, NULL, NULL, 13);
    Node *node14 = makeNode(NULL, NULL, NULL, 14);
    Node *node15 = makeNode(NULL, NULL, NULL, 15);
    Node *node16 = makeNode(NULL, NULL, NULL, 16);
    Node *node17 = makeNode(NULL, NULL, NULL, 17);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    node1->child = node6;
    node6->next = node7;
    node7->prev = node6;
    node7->next = node8;
    node8->prev = node7;

    node4->child = node9;
    node9->next = node10;
    node10->prev = node9;

    node7->child = node11;

    node8->child = node12;

    node9->child = node13;
    node13->next = node14;
    node14->prev = node13;

    node12->child = node15;

    node13->child = node16;
    node16->next = node17;
    node17->prev = node16;

    head = node1;
    tail = node5;

    printList(head);
    flattenList(head, &tail);
    printList(head);
    unflattenList(head, &tail);
    printList(head);

    return EXIT_SUCCESS;
}
