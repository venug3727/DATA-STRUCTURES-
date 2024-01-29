#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};

struct node *head =NULL;
struct node *create_node(head);
struct node *insert_beg(head);
struct node *insert_end(head);
struct node *insert_ran(head);
struct node *display(head);
struct node *delete_beg(head);
struct node *delete_end(head);
struct node *delete_ran(head);

int main()
{
    int option;
    

    while(1)
    {
        printf("\n1.create node\n2.insert at beging\n3.insert at end\n4.insert at random position\n5.display \n6.delete at beging\n7delete at end\n8delete at random pos\n9.exit");
        scanf("%d",&option);

        switch (option)
        {
        case 1: create_node(head);
            break;
        case 2:insert_beg(head);
            break;
        case 3:insert_end(head);
            break;
        case 4:insert_ran(head);
            break;
        case 5:display(head);
            break;
        case 6:delete_beg(head);
            break;
        case 7:delete_end(head);
            break;
        case 8 :delete_ran(head);
            break;

        case 9:exit(0);
            
        
        default: printf("wrong value");
            break;
        }
    }
    
}

struct node *create_node(head)
{
    struct node *newnode,*temp;
    int n;
    printf("how many data you want to insert:-");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {   
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data:- ");
        scanf("%d",&newnode->data);

        newnode->next=NULL;
        if (head==NULL)
        {
            head=temp=newnode;

        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

    }
    
}

struct node *insert_beg(head)
{
    struct node *newnode, *temp;
    temp = head;
    newnode =(struct node *)malloc(sizeof(struct node ));
    printf("enter data:- ");
    scanf("%d",newnode->data);
    newnode-> next=temp;
    head = newnode;

}


struct node *insert_end(head)
{
    struct node *temp ,*newnode ;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data:- ");
    scanf("%d",&newnode->data);
    temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=newnode;

    
}

struct node *insert_ran(head)
{
    int pos,i;
    struct node *temp,*newnode;
    printf("enter the position:-");
    scanf("%d",&pos);
     newnode = (struct node *)malloc(sizeof(struct node ));
     printf("enter data:-");
     scanf("%d",&newnode->data);
     temp=head;
    while (i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

struct node *display(head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
    
    
}


struct node *delete_beg(head)
{
    struct node *temp;
    if (head==NULL)
    {
        printf("empty");
        free(head);
    }
    else
    {
        temp = head;
        head = temp->next;
        printf("%ddeleted element",temp->data);
        free(temp);
    }
    
    
}

struct node *delete_end(head)
{
    struct node *prenode,*temp;
    temp=head;
    if (head==NULL)
    {
        printf("empty");
        free(head);
    }
    else
    {
        while (temp->next!=NULL)
        {
            prenode = temp;
            temp=temp ->next;
        }
        printf("%ddeleted element",temp->data);
        free(temp);
        prenode->next=NULL;
        
    }
    
    
}

struct node *delete_ran(head)
{
    struct node *temp,*nextnode;

    int pos,i=1;
    printf("enter position:- ");
    scanf("%d",&pos);
    while (i <pos-1)
    {
        temp=temp->next;
        i++;

    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    printf("%ddeleted element",nextnode->data);
    free(nextnode);
    
}