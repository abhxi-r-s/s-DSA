#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
    
}*temp;

struct node *head=NULL,*tail=NULL;


void insert();
void insert_beg(int num);
void insert_end(int num);
void insert_pos(int num);
void delete();
void delete_beg();
void delete_end();
void delete_pos(int pos);
void display();


void main()
{
    int choice;
    while(choice!=4)
    {
    printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:insert();
        break;
        case 2:delete();
        break;
        case 3:display();
        break;
        case 4:
        printf("Exiting----");
        break;
        default:
        printf("Invalid choice");
        break;

    }
    }
}
void insert()
{
    int choice,num;
    printf("Enter the value to insert :");
    scanf("%d",&num);
    printf("\nINSERTION\n1.Insert at beginning\n2.Insert at end");
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:insert_beg(num);
        break;
        case 2:insert_end(num);
        break;
        case 3:insert_pos(num);
        break;
        default:
        printf("Invalid option ");
        break;
    }
}
void insert_beg(int num)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        newnode->data=num;
        head=newnode;
        tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    
}
void insert_end(int num)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        newnode->data=num;
        head=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

    }
    
}
