#include <stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;

    };
    struct node *head=NULL;
    struct node *create();
    struct node *display();
    
    struct node *reverse();
   


struct node *create()
{
    
    int n;
    struct node *newnode,*temp;
    printf("How many data u want to cerat:-");
    scanf("%d",&n);
    
    for (int i=0;i<n;i++)
    {
    
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=0;

    if (head==NULL)
    {
        temp=head=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    
    }
    


    
    }   
}

struct node *reverse()
{
    struct node *prenode , *currnode,*nextnode;
    prenode = NULL;
    currnode=nextnode=head;
    while (nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currnode->next=prenode ;
        prenode=currnode;
        currnode=nextnode;

    }

    head=prenode ;
    
}



struct node *display()
{
    struct node *temp;
    temp=head;
    if (temp==NULL)
    {
        printf("there is no value in list");
    }
    
    else{
        while (temp!=0)
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
        printf("\n1.create nodes.\n2.display.\n3.reverse\n4.Exit.");
        printf("\nEnter your option.");
        scanf("%d",&option);
        switch (option)
        {
        case 1:create(head);
            printf("\nLIST CREATED");
            break;

        case 2:display(head);
            break;

        

        case 3:reverse(head);
            break;

        case 4:exit(0);
        
        default:printf("wrong value");
            break;
        }


      

    }
    
}