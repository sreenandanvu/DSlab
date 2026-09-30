#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int queue[MAX];
int front=-1;
int rear=-1;

int isFull()
{
    return(front == (rear +1)% MAX);
}

int isEmpty()
{
    return(front == -1);
}

void enqueue(int value)
{
    if(isFull())
    {
        printf("Queue is Full");
        return;
    }
    if(front == -1)
    {
        front=0;
    }
    rear=(rear+1)%MAX;
    queue[rear]=value;
    printf("%d inserted into the queue\n",value);
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue Empty");
        return;
    }
    printf("%d deleted from queue\n",queue[front]);
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}

void search(int value)
{
  if(isEmpty())
  {
    printf("Queue empty");
    return;
  }
  int i=front;
  while(1)
  {
    if(queue[i]==value)
    {
        printf("%d value found at postion",i);
        return;
    }
    if(i==rear)
    {
        break;
    }
    i=(i+1)%MAX;
  }
  printf("%d not found",value);
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

void main()
{
    int ch,value;
    while(1)
    {
        printf("1.Enqueue 2.Dequeue 3.Search\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the value to be inserted: ");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            printf("\nEnter the value to be searched: ");
            scanf("%d",&value);
            search(value);
            break;
            case 4:
            exit(1);
            default:
            printf("Invalid opertaion");
        }
    } 
}