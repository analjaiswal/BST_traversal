#include <stdio.h>
#include <stdlib.h>
struct tnode
{
   int data;
   struct tnode *lchild, *rchild;
};

struct tnode *insert(struct tnode *p,int val)
{
    struct tnode *temp1,*temp2;
    if(p == NULL)
    {
        p = (struct tnode *) malloc(sizeof(struct tnode)); /* insert the new node as root node*/
        if(p == NULL)
        {
            printf("Cannot allocate\n");
            exit(0);
        }
        p->data = val;
        p->lchild=p->rchild=NULL;
    }
    else
    {
        temp1 = p;
        /* traverse the tree to get a pointer to that node whose child will be the newly created node*/
        while(temp1 != NULL)
        {
            temp2 = temp1;
            if( temp1 ->data > val)
                temp1 = temp1->lchild;
            else
                temp1 = temp1->rchild;
        }
        if( temp2->data > val)
        {
            temp2->lchild = (struct tnode*)malloc(sizeof(struct tnode));/*inserts the newly created node as left child*/
            temp2 = temp2->lchild;
            if(temp2 == NULL)
            {
                printf("Cannot allocate\n");
                exit(0);
            }
            temp2->data = val;
            temp2->lchild=temp2->rchild = NULL;
        }
        else
        {
            temp2->rchild = (struct tnode*)malloc(sizeof(struct tnode)); /*inserts the newly created node as left child*/
            temp2 = temp2->rchild;
            if(temp2 == NULL)
            {
                printf("Cannot allocate\n");
                exit(0);
            }
            temp2->data = val;
            temp2->lchild=temp2->rchild = NULL;
        }
    }
    return(p);
}
/* a function to binary tree in inorder */
void inorder(struct tnode *p)
{
    if(p != NULL)
    {
        inorder(p->lchild);
        printf("%d\t",p->data);
        inorder(p->rchild);
    }
}

/* a function to binary tree in preorder */
void preorder(struct tnode *p)
{
    if(p == NULL)
        return;

    printf("%d\t",p->data);
    preorder(p->lchild);
    preorder(p->rchild);

}

/* a function to binary tree in postorder */
void postorder(struct tnode *p)
{
    if(p == NULL)
        return;
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\t",p->data);

}

void main()
{
   struct tnode *root = NULL;
   int n,x;
   int op;
   printf("Enter the number of nodes\n");
   scanf("%d",&n);
   while(n>0)
     {
         printf("Enter the data value\n");
         scanf("%d",&x);
         root = insert(root,x);
         n=n-1;
         printf("value of n: ", n);
    }

    while( op != 4)
    {
        printf("Which traversal do you want:\n 1) Inorder Traversal \n 2) Preorder Traversal \n 3) Postorder Traversal \n 4) To Exit\n");

        scanf("%d", &op);

        if( op == 1)
            inorder(root);
        else if( op == 2 )
            preorder(root);
        else if(op == 3)
            postorder(root);

    }

 }
