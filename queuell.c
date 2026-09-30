#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node *front = NULL, *rear = NULL;

void enqueue() {
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
}

void dequeue() {
    if(front == NULL) {
        printf("Underflow occurred\n");
        return;
    }
    Node *temp = front;
    front = front->next;
    temp->next = NULL;
    free(temp);
    if(front == NULL)
        rear = NULL;
}

void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    printf("Contents are:\n");
    while(temp!=NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("X\n");
}


int main() {
    int choice;
    while(1) {
        printf("\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}