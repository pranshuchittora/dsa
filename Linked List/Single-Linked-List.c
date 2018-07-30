#include <stdio.h>
#include <malloc.h>
// LL node structure declared
struct Node
{
    int data;
    struct Node *next;
};
// LL functions
void display_ll(struct Node **);
void insert_end(struct Node **);
void insert_beg(struct Node **);

int main()
{
    printf("\n\n");
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    //
    int head_data;
    printf("Enter HEAD data : ");
    scanf("%d", &head_data);
    head->data = head_data;
    head->next = NULL;
    printf("Linked List initilised \nHEAD-> %p\nHEAD Data -> %d\n\n", head, head_data);
    int option;
    do
    {
        printf("======MAIN MENU======\n");

        printf("1 : Display LL\n");
        printf("2 : Add node at the end of the LL\n");
        printf("3 : Add node at the beginning of the LL\n");

        //
        printf("=============\n");
        scanf("%d", &option);
        printf("-----------\n");
        //
        switch (option)
        {
        case 1:
            display_ll(&head);
            printf("\n-----------\n");
            break;
        case 2:
            insert_end(&head);
            printf("\n-----------\n");
            break;
        case 3:
            insert_beg(&head);
            printf("\n-----------\n");
            break;
        }

    } while (option != -1);

    printf("\n\n");
    return 0;
}
// Display
void display_ll(struct Node **head)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        printf("%d-->", current->data);
        current = current->next;
    }
    printf("NULL");
}

// Insert a node at the end of the linked list
void insert_end(struct Node **head)
{
    struct Node *current = *head;
    //Creating New Node
    int new_node_data;
    printf("Enter data : ");
    scanf("%d", &new_node_data);
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = NULL;
    // Taking the current to the last node
    while (current->next != NULL)
        current = current->next;

    //Linking current node with the newly created node
    current->next = new_node;
}

// Insert a node at the beginning of the linked list
void insert_beg(struct Node **head)
{
    struct Node *current_head = *head;
    //Creating New Node
    int new_head_data;
    printf("Enter new HEAD data : ");
    scanf("%d", &new_head_data);
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_head_data;
    new_node->next = current_head;
    // Making new node HEAD
    *head = new_node;
}