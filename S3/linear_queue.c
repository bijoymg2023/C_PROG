

#include <stdio.h>

int front = -1, rear = -1, Q[3], maxs = 3;

int enqueue(int a) 
{
    if (rear == maxs - 1) 
    { 
        printf("QUEUE OVERFLOW\n");
        return -1; 
    }
    else if (front == -1) 
    {
        front = rear = 0;
        Q[rear] = a;
        return a;
    }
     else 
    {
        Q[++rear] = a;
        return a; 
    }
}

int dequeue () 
{
    if (front == -1) 
    {
        printf("QUEUE UNDERFLOW\n");
        return -1;  
    }
     else 
    {
        int b = Q[front];
        if (front == rear) 
        {
            front = rear = -1;
        } else 
        {
            front++;
        }
        return b; 
    }
}

void display() 
{
    int i;
    if (front == -1) 
    {
        printf("EMPTY QUEUE\n");
    } 
    else 
    {
        printf("Queue Elements: ");
        for (i = front; i <= rear; i++) 
        {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int inp, choice, p, q, flag = 0;

    while (flag == 0) 
    {
        printf("1. ENQUEUE  2. DEQUEUE  3. DISPLAY  4. EXIT\n");
        printf("Select Operation: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if (rear!=maxs-1)
                {
                printf("Enter element to insert: ");
                scanf("%d", &inp);
                p = enqueue(inp);
                printf("Element Inserted: %d\n", p);
                }
                else{
                   printf("QUEUE OVERFLOW\n");}
              
                break;
            case 2:
                q = dequeue();
                if (q != -1) 
                {
                    printf("Element Deleted: %d\n", q);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                flag = 1;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
