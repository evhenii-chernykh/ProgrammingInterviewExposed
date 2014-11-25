#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int removeHead(Node **list)
{
    Node *head;
    if (!list || !*list)
    {
        return 0;
    }

    head = (*list);
    *list = head->next;
    free(head);

    return 1;
}

void printList(Node *head)
{
    printf("List is: [");
    while (head)
    {
        if (head->next)
        {
            printf("%i, ", head->data);
        }
        else
        {
            printf("%i", head->data);
        }
        head = head->next;
    }
    printf("]\n");
}

int main(void)
{
    Node *list = NULL;
    int cnt;
    for (cnt = 1; cnt <= 5; cnt++)
    {
        Node *elem = malloc(sizeof(*elem));
        if (!elem)
        {
            fprintf(stderr, "Memory out!\nExiting.\n");
            exit(EXIT_FAILURE);
        }
        elem->data = cnt;
        elem->next = list;
        list = elem;
    }
    printList(list);
    printf("Removing all elements from the list\n");
    while (list)
    {
        removeHead(&list);
        printList(list);
    }

    return EXIT_SUCCESS;
}
