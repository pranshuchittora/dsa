
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->next = temp;
    temp->data = data;
}

void survivorPosition(int m, int n)
{

    Node *head = newNode(1);
    Node *prev = head;
    for (int i = 2; i <= n; i++)
    {
        prev->next = newNode(i);
        prev = prev->next;
    }
    prev->next = head;
    Node *ptr1 = head, *ptr2 = head;
    while (ptr1->next != ptr1)
    {
        // Find m-th node
        int count = 1;
        while (count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }

        /* Remove the m-th node */
        ptr2->next = ptr1->next;
        ptr1 = ptr2->next;
    }

    cout<<"Survivor's Position = "<<ptr1->data<<endl;
}

int main()
{
    int n , m;
    cout << "Enter the total number of soldiers : ";
    cin >> n;
    cout << "Enter the number of persons to be skipped at each execution : ";
    cin >> m;
    survivorPosition(m, n);
    return 0;
}