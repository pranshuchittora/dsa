#include <stdio.h>

// -----------------------
#define stack_size 100
int stack[stack_size]; // Initialised Stack
int top = -1;   // Currently the stack is empty so top is -1

// -----------------------
void push() // PUSH function is used to inser an element into the stack
{

    if (top + 1 >= stack_size) // Check whether the stack is full or not
        printf("Stack OVERFLOW :( \n Try POPing elements out\n");
    else
    {
        int push_val;
        printf("Enter the value to be pushed into the Stack : ");
        scanf("%d", &push_val); // Stdin of the element to be pushed to the stack
        top++;                  // Making the stack top value ready to write
        stack[top] = push_val;  // Pushing the element to the stack
    }
}

void pop() // Function to pop/remove an element from the stack
{
    if (top - 1 < -1) // Check whether the stack is already empty or not
        printf("UNDERFLOW");

    else
        top--; // Rather than removeing the element just assume that the top most element is one down :) #TimeComplexity
}
void display() // A Fancy function to display the elements of the stack
{
    printf("\nStack :");
    int i = 0;
    for (i = 0; i <= top; i++)
    {
        printf("->%d", stack[i]);
    }
    printf("\n");
}
int main()
{
    printf("Stack has been created :)\n");

    int response = 0;

    do
    {
        display();
        printf("\n\t--- Select option ---\n");
        printf("1 : POP an element from the stack\n");
        printf("2: PUSH an element to the stack\n");
        printf("-------------------------------------\n");
        printf("Enter option : ");
        scanf("%d", &response);
        switch (response)
        {
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        default:
            response = 0;
            break;
        }

    } while (response != 0);

    printf("\nExiting Program :) -{.Y.}-\n");
    return 0;
}