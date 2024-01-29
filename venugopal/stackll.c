# include<stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node *next;

};

struct node *top=NULL;
struct node *push();
struct node *pop();
struct node *display();


struct node *push()
{
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d",&newnode->data);
    if(newnode == NULL)
    {
        printf("Memory not allocatede");
    }
    else if (top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }

    else
    {
        newnode->next=top;
        top=newnode;
    }
    
    


}


struct node *pop()
{
    struct node *temp;
    temp=top;
    if (top==NULL)
    {
        printf("empty");
    }
    else
    {
        top=temp->next;
        free(temp);
    }
    
}

struct node *display()
{
    struct node *temp;
    temp=top;
    if (top==NULL)
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
        printf("\n1.push.\n2.pop.\n3.display\n4.Exit.");
        printf("\nEnter your option.");
        scanf("%d",&option);
        switch (option)
        {
        case 1:push(top);
            printf("\n CREATED");
            break;

        case 2:pop(top);
            break;

        

        case 3:display(top);
            break;

        case 4:exit(0);
        
        default:printf("wrong value");
            break;
        }


      

    }
    
}