//Program to make and traverse a singly LL
/*
=========================================
Developer       :       Pranshu Chittora
Date            :       2018-09-22
=========================================
*/
// Structure of a Singly Linked List
// HEAD -> Node_1 -> Node_2 -> Node_3 ... -> Node_n -> NULL

#include <stdio.h>
#include <stdlib.h>

// Defining Node structure
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;                                 // Initialising Head pointer for the linked list.
    head = (struct Node *)malloc(sizeof(struct Node)); // Allocating Memory
    struct Node *current;                              // Current Node for traversing & other pusposes
    current = head;

    // stdin of size of Linked List
    printf("Enter the size of linked list : ");
    int n;
    scanf("%d", &n);

    // Inserting nodes in the linked list .
    int i;
    for (i = 0; i < n; i++)
    {
        struct Node *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        int new_node_data;
        printf("New Node data value : ");
        scanf("%d", &new_node_data); // Taking input of data value through stdin
        new_node->data = new_node_data;
        //Made node & inserted data

        current->next = new_node; // Linking the new_node with the linked list
        current = current->next;  // Making current point to the next node .
    }
    current->next = NULL; // Making the last node ->next to NULL , indicating that this is the last node of the list.

    // Traversing the list & printing the elements.
    current = head->next; // Making current to head->next because head node is empty
    while (current != NULL)
    {
        printf("->%d" , current->data);
        current = current->next;
    }
    return 0;
}