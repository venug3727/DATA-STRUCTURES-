#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("enter data:- ");
    scanf("%d",&newnode->data);
    newnode->left=newnode->right=NULL;
    return newnode;
}


struct node *insert(struct node *root,struct node *newnode)
{
    if (root!=NULL)
    {
        if (newnode->data<root->data  )
        {
           root->left=insert(root-> left,newnode);
        }



    }


    else if (root!=NULL)
    {
        if (newnode->data>root->data)
        {
            root->right=insert(root->right,newnode);

        }


    }

    else {
        root = newnode;
    }
    return root;

}


void preorder(struct node *root)
{
    if(root!=NULL)
        {
            printf("\t%d",root->data);
            preorder(root->left);
            preorder(root->right);
        }

}

void inorder(struct node *root)
{
    if(root!=NULL)
        {
            inorder(root->left);
            printf("\t%d",root->data);

            inorder(root->right);
        }

}
void postorder(struct node *root)
{
    if(root!=NULL)
        {
            postorder(root->left);


            postorder(root->right);
            printf("\t%d",root->data);
        }
}


int main()
{
    int option;

    struct node *root=NULL,*newnode;
    while(1)
    {
        printf("\n1.create.\n2.preorder.\n3.inorder.\n4postorder.\n5Exit.");
        printf("\n Enter option:- ");
        scanf("%d",&option);

        switch (option)
        {
        case 1: newnode=create();
                if (root==NULL)
                {
                    root=newnode;
                }else
                {
                    insert(root,newnode);
                }



            break;

        case 2:preorder(root);
            break;

        case 3: inorder(root);
            break;
        case 4:postorder(root);
            break;
        case 5:exit(0);

        default:printf("Entered Option is wrong !!!!......");
            break;
        }
    }
}


