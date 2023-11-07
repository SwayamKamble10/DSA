#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *createnode(struct node *head, int data)
{
    struct node *p;
    struct node *ptr = head;
    p = (struct node *)malloc(sizeof(struct node));
    // p->coeff = coeff;
    p->data = data;
    p->next = NULL;
    if (head == NULL)
    {
        return p;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    return head;
}
struct node* reversell(struct node* head)
{
 struct node* prev = NULL;
    struct node* current =head;
    struct node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
struct node *add(struct node *head1,struct node *head2)
{

}
int main()
{
    struct node *head1,*head2;
    struct node *head3;
    int n1,n2;
    printf("Enter the 1st number\n");
    scanf("%d",&n1);
    printf("Enter the 2nd number\n");
    scanf("%d",&n2);
    for (int i = 0;i<n2 ; i=i*10)
    {
        head1=createnode(head1,n2);
    }
    
    // step 1 
    head1=reversell(head1);
    head2=reversell(head2);
    // step 2
    head3=add(head1,head2); 
}