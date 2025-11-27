#include<bits/stdc++.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int value){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=value;
    node->left=node->right=NULL;
    return node;    
};
struct node* insert(struct node* root, int value){
    if(root==NULL)return newnode(value);
    if(root->left==NULL)root->left=newnode(value);
    else if(root->right==NULL)root->right=newnode(value);
     else   root->left=insert(root->left,value);
    return root;
};
void attachright(struct node* root, struct node* child)
{
    if(root==NULL || child==NULL)return;
    while(root->right!=NULL)root=root->right;
    root->right=child;
};
struct node* deletenode(struct node* root,int value)
{
    if(root==NULL)return NULL;
    if(root->data==value)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node* left=root->left;
            struct node* right=root->right;
            free(root);
            attachright(left,right);
            return left;
        }
    }
    root->left=deletenode(root->left,value);
    root->right=deletenode(root->right,value);
    return root;
};
void preorder(struct node* root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
bool search(struct node* root, int value)
{
    if(root==NULL)return false;
    if(root->data==value)return true;
    return search(root->left,value)||search(root->right,value);
}
int main() {
    struct node* root = NULL;
    int choice, value;
    while (1) {
        printf("1.Insertion\n2.Deletion\n3.Preorder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n6.Search\n7.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deletenode(root, value);
                printf("Node deleted (if found).\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
            printf("Enter Value:\n");
            scanf("%d", &value);
            if(search(root,value))printf("Value is Found!!\n");
            else printf("Value is not found!!\n");
            break;
            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}