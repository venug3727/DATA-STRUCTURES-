#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;

};

struct node *f=NULL;
struct node *r=NULL;
struct node *enque();
struct node *deque();
struct node *display();


struct node *enque()
{
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (f==NULL&&r==NULL)
    {
        f=r=newnode;

    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}


struct node *deque()
{
    struct node *temp;
    temp=f;
    if (f==NULL)
    {
        printf("empty");

    }
    else
    {
        f=f->next;
        
        free(temp);
        printf("deleted element is: %d",temp->data);
        
    }
    
    
}


struct node *display()
{
    struct node *temp;
    temp=f;
    if (f==NULL)
    {
        printf("empty");

    }
    else
    {
        while (temp!=NULL)
        {
            printf("\t%d\n",temp->data);
            temp=temp->next;
        }
        
    }
    

}

int main()
{
    int option;
    while (1)
    {
        printf("<<<<<<<<<<<<<<<##################MENU##################>>>>>>>>>>>>>>\n");
        printf("\n1.enque.\n2.deque.\n3.display\n4.Exit.");
        printf("\nEnter your option.");
        scanf("%d",&option);
        switch (option)
        {
        case 1:enque();
            
            break;

        case 2:deque();
            break;

        

        case 3:display();
            break;

        case 4:exit(0);
        
        default:printf("wrong value");
            break;
        }


      

    }
    
}