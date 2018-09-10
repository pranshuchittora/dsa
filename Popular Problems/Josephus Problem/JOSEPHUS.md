<h1 align="center" id="head"> Josephus Problem </h1>
In computer science and mathematics, the Josephus Problem (or Josephus permutation) is a theoretical problem. Following is the problem statement:
There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

---


## The given problem can be solved using 
- [Recursion](#recursion) 
- [Circular Linked list](#cll)


## Recursive Method
The problem has following recursive structure.

  survivorPosition(n, k) = (survivorPosition(n - 1, k) + k-1) % n + 1
  survivorPosition(1, k) = 1
After the first person (kth from begining) is killed, n-1 persons are left. So we call survivorPosition(n – 1, k) to get the position with n-1 persons. But the position returned by survivorPosition(n – 1, k) will consider the position starting from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).

Following is simple recursive implementation of the Josephus problem. The implementation simply follows the recursive structure mentioned above.
```cpp
#include <iostream>
using namespace std;

int survivorPosition(int n, int k)
{
    if (n == 1)
        return 1;
    return (survivorPosition(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n, k;

    cout << "Enter the total number of soldiers : ";
    cin >> n;
    cout << "Enter the number of persons to be skipped at each execution : ";
    cin >> k;

    int ans = survivorPosition(n, k);
    cout << endl
         << "Survivor's Position = " << ans << endl;

    return 0;
}
```

## Circular Linked List
The following problem can be solved using Circular-Linked-List as follows :

```
Algo

1) Create a circular linked list of size n.
2) Traverse through linked list and one by one delete every m-th node until there is one node left.
3) Return value of the only left node.
```
## 1->2->3->4.....->n
So for each execution , we remove the particular node (m-th) which is the position of the person killed.

```cpp
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

    cout << "Survivor's Position = " << ptr1->data << endl;
}

int main()
{
    int n, m;
    cout << "Enter the total number of soldiers : ";
    cin >> n;
    cout << "Enter the number of persons to be skipped at each execution : ";
    cin >> m;
    survivorPosition(m, n);
    return 0;
}
```












### Credits
- Computerphile 
- Geeks4Geeks 
- Me , Myself & I