#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=0,*temp,*del;
 
int count=0;

void insert()
{
    int ch,num,pos;
    printf("\nEnter the value to insert :");
    scanf("%d",&num);
    printf("\nINSERTION\n1.Insert at beginning\n2.Insert at End\n3.Insert at preffered position\n");
    printf("Enter the choice :");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:insert_beg(num);
        break;
        case 2:insert_end(num);
        break;
        case 3:
        printf("\nEnter the position to insert :");
        scanf("%d",&pos);
        if(pos>count||pos<=0)
        {
            printf("\nEnter a valid position to insert :");
            scanf("%d",&pos);
        }
        else
        {
            insert_pos(num,pos);
        }
        break;
        default:
        printf("\nEnter a valid option :");
    }


}
void insert_beg(int num)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;

    if(head==0)
    {
        head=newnode;
        count++;
        printf("\n Element inserted Successfully...!");
    }
    else if(head!=0)
    {
        newnode->next=head;
        head=newnode;
        count++;
        printf("\n Element inserted Successfully...!");
    }
    

}
void insert_end(int num)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    temp=head;

    if(head==0)
    {
        head=newnode;
        count++;
        printf("\n Element inserted Successfully...!");
    }
    else if(head!=0)
    {
        while(temp->next==NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        count++;
        printf("\n Element inserted Successfully...!");
    }


}
void insert_pos(int num,int pos)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    temp=head;

    printf("\nEnter the position to insert :");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg(num);
    }
    else if(pos==count)
    {
        insert_end(num);
    }
    else
    {
    for(int i=0;i<=pos-2;i++)
    {
        temp=temp->next;        
    }
    newnode->next=temp->next;
    temp->next=newnode;
    count++;
    printf("\n Element inserted Successfully...!");
    }

}

void delete()
{
    int choice,pos;
    printf("\nDELETION \n");
    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from preferred position\n");
    printf("Enter the choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:delete_beg();
        break;
        case 2:delete_end();
        break;
        case 3:
        if(head==0)
        {
            printf("\n No elemt to delete ");
        }
        else
        {
        printf("\nEnter the position to delete :");
        scanf("%d",&pos);
        if(pos>count||pos<0)
        {
            printf("Enter a valid position to delete :");
            scanf("%d",&pos);
        }
        else
        {
            delete_pos(pos);
        }
        }
    }
}

void delete_beg()
{
    if(head==0)
    {
        printf("\nNothing to delete");
    }
    else
    {
    temp=head;
    head=head->next;
    
    printf("The deleted element is %d",temp->data);
    count--;
    printf("\n Element deleted Successfully...!");
    }

}
void delete_end()
{
    temp=head;
    if(head==0)
        {
            printf("\n No element to delete ");
        }
    else
        {
            while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
            del=temp->next;
            temp->next=NULL;
            printf("The deleted element is %d",del->data);
            count--;
            printf("\n Element deleted Successfully...!");
        }
    
}
void delete_pos(int pos)
{
    for(int i=0;i<=pos-2;i++)
    {
        temp=temp->next;
    }
    del=temp->next;
    temp->next=del->next;
    count--;
    printf("The Deleted element is  %d",del->data);
    printf("\n Element deleted Successfully...!");
   


}
void search(int a)
{
    temp=head;
    
        while(temp->next==NULL)
        {
            if(temp->data==a)
            {
                printf("Element found");
            }
            else
            {
                printf("Element is present ");
            }
        }
    

}
void display()
{
    temp=head;
    if(temp==0)
    {
        printf("\nNo elements in the list :");
    }
    else
    {
        for(int i=1;i<=count;i++)
        {
        printf("\n%d\n",temp->data);
        temp=temp->next;
        }

    }
    

}

void main()
{
    int choice,a;
    while(choice!=5)
    {
    printf("\nMENU\n****************************\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
        break;
        case 2:
        if(head==0)
        {
            printf("\nNo Elements to delete ");
        }
        else
        {
            
            delete();
        }
        break;
        case 3:display();
        break;
        case 4:
        if(head==0)
        {
            printf("The List is empty");
        }
        else
        {
            printf("\nEnter the element to be searched :");
            scanf("%d",&a);
            search(a);
        }
        
        break;
        case 5:printf("\nExiting........");
        break;
        default:
        printf("\nEnter a valid choice :");

    }
    }
}