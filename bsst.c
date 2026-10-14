#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct node *right;
    struct node *left;
};

struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
     printf("Meory allocation failed\n");
     exit(1);
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
sturct Node* insert(struct Node *root,int value){
    if(root==NULL)
    return createNode(value);

    if(value<root->data)
    root->left=insert(root->left,value);
    else if(value>root->data)
    root->right=insert(root->right,value);

    return root;
}

struct Node* search(struct Node *root,int key)
{
    if(root==NULL || root->data==key)
    return root;
    if(key < root->data)
    return search(root->left,key);
    return search(root->right,key);
}

struct Node* findmin(struct Node *root)
{
  while(root !=NULL && root->left !=NULL)
  root=root->left;
  return root;
}


struct Node* deleteNode(struct Node *root,int key)
{
    if(root==NULL)
    return NULL;
    if(key<root->data)
    [
        root->left=deleteNode(root->left,key);
    ]
    else if(key>root->data)
    {
        root->right=deleteNode(root->right,key);
    }
    else
    {
        If(root->left==NULL)
        {
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node *temp= findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    struct Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;
                root = insert(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;

                if (search(root, value) == NULL) {
                    printf("Value not found.\n");
                } else {
                    root = deleteNode(root, value);
                    printf("Node deleted.\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1)
                    goto cleanup;

                if (search(root, value) != NULL)
                    printf("Value found.\n");
                else
                    printf("Value not found.\n");
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                goto cleanup;

            default:
                printf("Invalid choice.\n");
        }
    }

cleanup:
    freeTree(root);
    return 0;
}
}