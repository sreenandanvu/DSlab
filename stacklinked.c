#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
int isEmpty()
{
    return top == NULL;
}
void push(int value)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode==NULL)
  {
    printf("Stack Overflow");
    return;
  }
  newNode->data = value;
  newNode->next=top;
  top=newNode;
  printf("%d pushed to stack",value);
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow");
        return -1;
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
 {
    int c,value;
    while(1)
    {
    printf("\n--Stack Opertion--\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value);
        break;
        case 2:
        value = pop();
        if (value != -1)
        printf("%d popped from stack\n", value);
        break;
        case 3:
        value = peek();
        if (value != -1)
        printf("Top element: %d\n", value);
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
    return 0;
}
