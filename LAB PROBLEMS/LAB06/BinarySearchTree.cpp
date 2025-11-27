#include<bits/stdc++.h>
struct bstnode{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};
struct bstnode *newnode(int value){
    struct bstnode *bstnode=(struct bstnode*)malloc(sizeof(struct bstnode));
    bstnode->data=value;
    bstnode->left=bstnode->right=NULL;
    return bstnode;    
};
struct bstnode* insert(struct bstnode* root, int value){
    if(root==NULL)return newnode(value);
    if(value<=root->data)root->left=insert(root->left,value);
    else if(value>root->data)root->right=insert(root->right,value);
    return root;
};
struct bstnode* findmin(struct bstnode* root)
{
    while(root->left!=NULL)root=root->left;
    return root;
}
struct bstnode* deletenode(struct bstnode* root,int value)
{
    if(root==NULL)return NULL;
    if(value<root->data)root->left=deletenode(root->left,value);
    else if(value>root->data)root->right=deletenode(root->right,value);
    else
    {
        if(root->left==NULL && root->right==NULL) 
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            struct bstnode* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct bstnode* temp=root->left;
            free(root);
            return temp;
        }
        else
        {
         struct bstnode* temp=findmin(root->right);
         root->data=temp->data;
         root->right=deletenode(root->right,temp->data);
        }
    }
    return root;
};
void preorder(struct bstnode* root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}5
void inorder(struct bstnode* root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct bstnode* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
bool search(struct bstnode* root, int value)
{
    if(root==NULL)return false;
    if(root->data==value)return true;
    return search(root->left,value)||search(root->right,value);
}
int main() {
    struct bstnode* root = NULL;
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