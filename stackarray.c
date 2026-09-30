#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top=-1;

void push();
void pop();
void peek();
void display();

void main()
{
    int c;
    while(1)
    {
        printf("\n--Stack Opertion--\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid Opertion");
        }
    }
}
void push(int value)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d", &value);
        top++;
        stack[top]=value;
        printf("%d inserted into the stack",value);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else{
    printf("%d Popped",stack[top]);
    top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d",stack[top]);
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Elements of stack are: ");
        for(int i=top;i>=0;i--)
        {
        printf("%d \t ",stack[i]);
        }
    }
}
