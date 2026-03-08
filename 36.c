/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>

#define MAX 1000

int main() {
    int queue[MAX];
    int n, m;
    int front = 0, rear = -1;

    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }

    scanf("%d", &m);

    // Dequeue operations
    for (int i = 0; i < m; i++) {
        front = (front + 1) % MAX;
    }

    // Display elements
    int index = front;
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }

    return 0;
}