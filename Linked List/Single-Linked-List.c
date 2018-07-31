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
void insert_mul(struct Node **);
void insert_before(struct Node **);
void insert_after(struct Node **);
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
        printf("0 : Add multiple nodes at the end\n");
        printf("1 : Display LL\n");
        printf("2 : Add node at the end of the LL\n");
        printf("3 : Add node at the beginning of the LL\n");
        printf("4 : Add node before a given value in the LL\n");
        printf("5 : Add node after a given value in the LL\n");
        printf("-1 : EXIT\n");

        //
        printf("=============\n");
        scanf("%d", &option);
        printf("-----------\n");
        //
        switch (option)
        {

        case 0:
            printf("INSERT MULTIPLE NODES\n");
            insert_mul(&head);
            printf("\n-----------\n");
            break;

        case 1:
            printf("DISPLAY LINKED LIST\n");
            display_ll(&head);
            printf("\n-----------\n");
            break;
        case 2:
            printf("INSERT NODE AT THE END\n");
            insert_end(&head);
            printf("\n-----------\n");
            break;
        case 3:
            printf("INSERT NODE AT THE START\n");
            insert_beg(&head);
            printf("\n-----------\n");
            break;
        case 4:
            printf("INSERT NODE -> BEFORE\n");
            display_ll(&head);
            printf("\n-----------\n");
            insert_before(&head);
            printf("\n-----------\n");
            break;

        case 5:
            printf("INSERT NODE -> AFTER\n");
            display_ll(&head);
            printf("\n-----------\n");
            insert_after(&head);
            printf("\n-----------\n");
            break;
        }
    } while (option != -1);

    printf("\nNamaste _/|\\_\n\n");

    return 0;
}
// Insert Multiple Nodes at the end -> 0
void insert_mul(struct Node **head)
{
    struct Node *current = *head;
    // Taking the current to the last node
    while (current->next != NULL)
        current = current->next;

    int new_node_data;
    printf("Press '-1' to terminate adding \n");
    printf("Enter data : \n");
    scanf("%d", &new_node_data);
    while (new_node_data != -1)
    {
        struct Node *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = new_node_data;
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
        scanf("%d", &new_node_data);
    }
}
// Display -> 1
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

// Insert a node at the end of the linked list -> 2
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

// Insert a node at the beginning of the linked list -> 3
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

void insert_before(struct Node **head)
{
    struct Node *current_node = *head;
    struct Node *next_node = current_node->next;
    int before_val;

    printf("\nEnter the value before which you want to insert new node : ");
    scanf("%d", &before_val);

    int new_node_data;
    printf("Enter new node data : ");
    scanf("%d", &new_node_data);

    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = NULL;

    while (next_node->data != before_val)
    {
        current_node = next_node;
        if (next_node->next == NULL)
            break;
        next_node = next_node->next;
    }
    if (current_node->next==NULL)
        printf("\nInvalid Insertion \nProcess Terminated \n");
    else
    {
        current_node->next = new_node;
        new_node->next = next_node;
        printf("\nNode inserted successfully \n");
    }
}

void insert_after(struct Node **head)
{
    struct Node *current_node = *head;

    int after_val;

    printf("\nEnter the value after which you want to insert new node : ");
    scanf("%d", &after_val);

    int new_node_data;
    printf("Enter new node data : ");
    scanf("%d", &new_node_data);

    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = NULL;

    while (current_node->data != after_val)
    {
        if (current_node->next == NULL)
            break;
        current_node = current_node->next;
    }
    if (current_node->next == NULL)
        printf("\nInvalid Insertion \nProcess Terminated \n");
    else
    {

        new_node->next = current_node->next;
        current_node->next = new_node;
        printf("\nNode inserted successfully \n");
    }
}