#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *head = NULL;

void insertAtBeginning(int value) {
    Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL){
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted successfully\n");
}


void insertAtEnd(int value) {
    Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        struct Node *node;
        node = head;
        while(node->next!=NULL) {
            node = node->next;
        }
        node->next = newNode;
        newNode->prev = node;
    }
    printf("Inserted successfully\n");
}

void insertAtPos(int value) {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    int posTracker=1;
    Node *node;
    node = head;
    if(head == NULL) {
        head = newNode;
    }
    else {
        while(node->next!=NULL && posTracker<pos-1) {
            node = node->next;
            posTracker++;
        }
    
        if(node->next == NULL) {
            node->next = newNode;
            newNode->prev = node;
        }
        else {
            newNode->next = node->next;
            newNode->prev = node;
            node->next = newNode;
            (newNode->next)->prev = newNode;
        }   
    }
    printf("Inserted successfully\n");
}

void deleteBeginning() {
    if(head == NULL) {
        printf("Underflow occurred\n");
        return;
    }
    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("Deleted successfully\n");
}

void deleteEnd() {
    if(head == NULL) {
        printf("Underflow occurred\n");
        return;
    }
    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    printf("Deleted successfully\n");
}

void deletePos() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(head == NULL) {
        printf("Underflow occurred\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted successfully\n");
}

void display() {
    if(head == NULL) {
        printf("Linkedlist is empty\n");
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice,tempVal;
    while(1) {
        printf("\n\n1.Insert at Beginning \n2.Insert at End \n3.Insert at position \n4.Delete from beginning \n5.Delete from end \n6.Delete from position \n7.Display \n8.Exit \nEnter your choice: ");
        scanf("%d", &choice);
        if(choice<4) {
            printf("Enter the number: ");
            scanf("%d", &tempVal);
        }
        switch(choice) {
            case 1: 
                insertAtBeginning(tempVal);
                break;
            case 2:
                insertAtEnd(tempVal);
                break;
            case 3:
                insertAtPos(tempVal);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deletePos();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default: printf("Invalid input\n");
        }
    }
    return 0;
}