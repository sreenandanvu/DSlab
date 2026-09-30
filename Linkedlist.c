#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int is_null(struct Node *head) {
    if(head->next == NULL){
        return 1;
    }
    return 0;
}

struct Node *insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;
    printf("Inserted successfully");
    return head;
}

struct Node *insertAtEnd(struct Node *head, int value) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct Node *node;
    node = head;
    while(node->next!=NULL) {
        node = node->next;
    }
    node->next = newNode;
    printf("Inserted successfully");
    return head;
}

struct Node *insertAtPos(struct Node *head, int value, int pos) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    int posTracker=0;
    struct Node *node;
    node = head;
    while(node->next!=NULL && posTracker<pos-1) {
        node = node->next;
        posTracker++;
    }

    if(node->next == NULL) {
        node->next = newNode;
    }
    else {
        newNode->next = node->next;
        node->next = newNode;
    }   
    printf("Inserted successfully");
    return head;
}

struct Node *deleteBeginning(struct Node *head) {
    struct Node *temp;
    temp = head->next;
    head->next = temp->next;
    temp->next = NULL;
    free(temp);
    printf("Deleted successfully");
    return head;
}

struct Node *deleteEnd(struct Node *head) {
    struct Node *temp;
    temp = head;
    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted successfully");
    return head;
}

struct Node *deletePos(struct Node *head, int pos) {
    struct Node *temp, *newNode;
    temp = head;
    int counter = 1;
    while((temp->next)->next != NULL && counter<pos) {
        temp = temp->next;
        counter++;
    }
    newNode = temp->next;
    temp->next = newNode->next;
    newNode->next = NULL;
    printf("Deleted successfully");
    return head;
}

int main() {

    struct Node *head, *node;
    head = malloc(sizeof(struct Node));
    head->next = NULL;

    int tempVal, choice, flag=1, pos;

    do {
        printf("\n\n1.Insert at Beginning \n2.Insert at End \n3.Insert at position \n4.Delete from beginning \n5.Delete from end \n6.Delete from position \n7.Display \n8.Exit \nEnter your choice: ");
        scanf("%d", &choice);
        if(choice<4) {
            printf("Enter the number: ");
            scanf("%d", &tempVal);
        }
        switch(choice) {
            case 1: 
                head = insertAtBeginning(head, tempVal);
                break;
            case 2:
                head = insertAtEnd(head, tempVal);
                break;
            case 3:
                printf("Enter the position to be insert at: ");
                scanf("%d", &pos);
                head = insertAtPos(head, tempVal, pos);
                break;
            case 4:
                if(is_null(head)==1){
                    printf("Linkedlist is empty");
                    break;
                }
                head = deleteBeginning(head);
                break;
            case 5:
                if(is_null(head)==1){
                    printf("Linkedlist is empty");
                    break;
                }
                head = deleteEnd(head);
                break;
            case 6:
                if(is_null(head)==1){
                    printf("Linkedlist is empty");
                    break;
                }
                printf("Enter the position to be deleted: ");
                scanf("%d", &pos);
                head = deletePos(head, pos);
                break;   
            case 7:
                printf("Stored numbers are\n");
                node = head->next;
                if(node == NULL) {
                    printf("Linkedlist is empty\n");
                    break;
                }
                while(node != NULL) {
                    printf("%d->", node->data);
                    node = node->next;
                }
                break;
            case 8:
                flag = 0;
                break;
            default: 
                printf("Invalid input");
                break;
        }
    }while(flag==1);

    free(node);
    return 0;
}