#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *Left;
    int data;
    struct node *Right;
};

struct node *create(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->Left = NULL;
    newnode->Right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }
    else if (value == root->data)
    {
        printf("Same data cannot be inserted");
    }
    else if (value > root->data)
    {
        root->Right = insert(root->Right, value);
    }
    else if (value < root->data)
    {
        root->Left = insert(root->Left, value);
    }
}
struct node *search(struct node *root,int value)
{
    if(root==NULL)
    {
        printf("Bst is empty");
        return NULL;
    }
    else
    {
        if(value==root->data)
        {
            return root;
        }
        else if(value<root->data){
            search(root->Left,value);
            
        }
        else if(value>root->data){
            search(root->Right,value);
            
        }
    }
}
struct node*display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->Left);
        printf("%d  ",root->data);
        display(root->Right);
    }
}
struct node*minValue(struct node *root)
{
    if(root!=NULL)
    {
        struct node* current=root->Right;
        while(current->Right!=NULL)
        {
            current=current->Left;
            return current;
        }
    }
    else{
        return NULL;
    }
}
struct node*delete(struct node *root,int value)
{
    if(root!=NULL)
    {
        if(value<root->data)
        {
            root->Left=delete(root->Left,value);
        }
        else if(value>root->data)
        {
            root->Right=delete(root->Right,value);
        }
        else{
            if(root->Left==NULL)
            {
                struct node *temp=root->Right;
                free(root);
                return temp;
            }
            else if(root->Right==NULL)
            {
                struct node *temp=root->Left;
                free(root);
                return temp;
            }
            struct node *temp=minValue(root->Right);
            root->data=temp->data;
            root->Right=delete(root->Right,temp->data);
        }
        return root;

    }
}


void inorder(struct node *root)
{   
    if(root!=NULL){
    inorder(root->Left);
    printf("%d ",root->data);
    inorder(root->Right);
    }
    
}
void preorder(struct node *root)
{   
    if(root!=NULL){

    printf("%d ",root->data);
    preorder(root->Left);
    preorder(root->Right);
    }
    
}
void postorder(struct node *root)
{   
    if(root!=NULL){
    
    postorder(root->Left);
    postorder(root->Right);
    printf("%d ",root->data);
    }
    
}


void main()
{
    struct node *root = NULL;
    int num, ch;
    printf("MENU");
    printf("_ _ _ _ _ _");
    do
    {
        printf(" 1. INSERT\n 2. DELETE\n 3. SEARCH \n 4. TRAVERSE \n 5. DISPLAY \n 6. EXIT \n");
        printf("Enter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to insert :");
            scanf("%d", &num);
            if (root == NULL)
            {
                root = create(num);
            }
            else
            {
                insert(root, num);
            }
            break;
        case 2:
            if (root == NULL)
            {
                printf("Bst is empty");
            }
            else
            {
                printf("Enter the value to delete :");
                scanf("%d", &num);
                root = delete(root, num);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Bst is empty");
            }
            else
            {
                printf("Enter the value to be searched:");
                scanf("%d", &num);
                if (search(root, num) == NULL)
                {
                    printf("Element not found");
                }
                else
                {
                    printf("Item found");
                }
            }
        case 4:
            if (root == NULL)
            {
                printf("Bst is empty");
            }
            else
            {
                printf("\n 1. Inorder \n 2. Preorder \n 3. Postorder\n Choose any one of the travesal option : ");
                int op;
                scanf("%d", &op);
                switch (op)
                {
                case 1:
                    inorder(root);
                    break;
                case 2:
                    preorder(root);
                    break;
                case 3:
                    postorder(root);
                    break;
                default:
                    printf("Enter a valid choice :");
                    break;
                }
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("Bst is empty :");
            }
            else
            {
                display(root);
            }
            break;
        default:
            printf("Enter avalid choice :");
            break;
        }
    } while (1);
}