#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
 void print(struct node* head)
{
    struct node *ptr=head;
     while (ptr!=NULL)
     {
        printf(" %dx^%d",ptr->coeff,ptr->exp);
        ptr=ptr->next;
     }
     
}
struct node  *createnode(struct node *head,int coeff,int exp)
{
       struct node* p;
       struct node *ptr=head;
       p=(struct node*)malloc(sizeof(struct node));
       p->coeff=coeff;
       p->exp=exp;
       p->next=NULL;
       if (head==NULL)
       {
           return p;
       }
       while (ptr->next!=NULL)
       {
           ptr=ptr->next;
       }
       ptr->next=p;
       return head;
       
       

}
struct node *addpolynomial(struct node *head1, struct node *head2)
{
    struct node *head3 = NULL;
    struct node *ptr1 = head1, *ptr2 = head2;

    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2!=NULL)
        {
            if (ptr1->exp==ptr2->exp)
            {
                head3=createnode(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
                break;
            }
            ptr2=ptr2->next;
        }
        if (ptr2==NULL)
        {
            head3=createnode(head3,ptr1->coeff,ptr1->exp);
        }
        ptr1=ptr1->next;
    } 
    while (ptr2 != NULL)
    {
        int found = 0;
        ptr1 = head1;

        while (ptr1 != NULL)
        {
            if (ptr1->exp == ptr2->exp)
            {
                found = 1;
                break;
            }
            ptr1 = ptr1->next;
        }

        if (!found) 
            head3 = createnode(head3, ptr2->coeff, ptr2->exp);

        ptr2 = ptr2->next;
    }

    return head3;
}
    
        



int main()
{
    int n;
    int coeff,exp;
    struct node *head1=NULL,*head2=NULL;
    printf("Enter number of terms of polynomial\n");
    scanf("%d",&n);
    
    for (int  i = 0; i < n; i++)
    {
        printf("Enter coeff of %dth term\n",i);
        scanf("%d",&coeff);
        printf("Enter exp of %dth term\n",i);
        scanf("%d",&exp);
        head1=createnode(head1,coeff,exp);

    }
    printf("For second term");
     for (int  i = 0; i < n; i++)
    {
        printf("Enter coeff of %dth term\n",i);
        scanf("%d",&coeff);
        printf("Enter exp of %dth term\n",i);
        scanf("%d",&exp);
        head2=createnode(head2,coeff,exp);
           
    }
    struct node *head3=addpolynomial(head1,head2);
    print(head3);
   
}
