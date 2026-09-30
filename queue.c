#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value);
int dequeue();
void display();
int peek();

int main()
{
    int choice,value;
    while(1)
    {
        printf("---Queue Operations---\n1.Enqueue\t2.Dequeue\t3.Display\t4.Peek\t5.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&value);
            enqueue(value);
            break;

            case 2:
            value = dequeue();
            if (value !=-1)
            {
                printf("Dequeued element is %d",value);
            }
            break;

            case 3:
            display();
            break;

            case 4:
            value = peek();
            if (value !=-1)
            {
                printf("Element at front is %d",value);
            }
            break;

            case 5:
            exit(0);
            
            default:
            printf("Invalid Choice"); 
        }
    }
return 0;
}
        void enqueue(int value)
        {
        if(rear== MAX-1)
        {
        printf("Queue overflow");
        return;
        }
        if (front == -1)
        {
        front=0;
        }
        rear++;
        queue[rear]=value;
        printf("Element entered sucessfully");
        }

        int dequeue()
        {
        if(front== -1)
        {
        printf("Queue Underflow");
        return -1;
        }
        int deleted_item = queue[front];
        if(front==rear)
        {
        front=-1;
        rear=-1;
        }
        else
        {
        front++;
        }
        return deleted_item;
        }

        int peek() 
        {
        if (front==-1) 
        {
        printf("Queue is empty.\n");
        return -1;
        }
        return queue[front];
        }

        void display() 
        {
        if (front==-1)
        {
        printf("Queue is empty.\n");
        return;
        }
        printf("Queue elements are: ");
        for (int i=front;i<=rear;i++)
        {
        printf("%d ", queue[i]);
        }
        printf("\n");
        }
