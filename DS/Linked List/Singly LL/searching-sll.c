//Program to make and traverse a singly LL
/*
=========================================
Developer       :       Pranshu Chittora
Date            :       2018-09-23
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

    int srch_val;
    printf("Enter the value to find in the LL : ");
    scanf("%d", &srch_val);

    struct Node *node_found = NULL; // Initialising matched node to NULL

    // Traversing the list to find the node which contains value
    current = head->next; // Making current to head->next because head node is empty
    while (current != NULL)
    {
        if (srch_val == current->data) // Executes when the current node's data is equal to the value to be found
        {
            node_found = current;
            break; // Breaks the loop as the node is found
        }
        else
            current = current->next; // As this current node's data is not matched with the value to be found
    }
    if (node_found) // Some fancy console statements :D
        printf("\nElement found in the list @ %p  \n", node_found);
    else
        printf("\nElement not found in the List :( \n");
    return 0;
}