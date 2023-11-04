#include<stdio.h>
#include<stdlib.h>

//This program is written for polynomial application using linked lists .
struct node
{
    int exponent ;
    int coefficient ;
    struct node * next ;
}  ;

void insertatbeginning(struct node ** head , int exp , int coeff )
{
    struct node * newnode ;
    newnode = (struct node * )malloc(sizeof(struct node)) ;
    newnode->exponent=exp ;
    newnode->coefficient=coeff ;
    newnode->next=NULL ;
    if(*head==NULL)
    {
        *head=newnode ;
    }
    else
    {
        newnode->next=*head ;
        *head=newnode ;
    }
}

void insertinbetween(struct node ** head , int exp , int coeff , int pos)
{
    struct node * p=*head ;
    struct node * newnode ;
    newnode = (struct node * )malloc(sizeof(struct node)) ;
    newnode->exponent=exp ;
    newnode->coefficient=coeff ;
    newnode->next=NULL ;
    int k=1 ;
    while(k<pos-1)
    {
        p=p->next ;
    }
    newnode->next=p->next ;
    p->next=newnode ;
}

void insertatlast(struct node ** head , int exp , int coeff)
{
    struct node *p = *head ;
    struct node * newnode ;
    newnode = (struct node * )malloc(sizeof(struct node)) ;
    newnode->exponent=exp ;
    newnode->coefficient=coeff ;
    newnode->next=NULL ;
    while(p->next!=NULL)
    {
        p=p->next ;
    }
    p->next=newnode ;
}

void printinglinkedlist(struct node *head)
{
    struct node * p = head ;
    while(p)
    {
        printf("%dx^%d+ " , p->coefficient , p->exponent) ;
        p=p->next ;
    }
}

void create(struct node ** head)
{
    printf("we ll take input in the linked list one by one \n") ;
    int j ;
    printf("how many elements do you need in the linked list ?\n") ;
    scanf("%d" , &j) ;
    int k=0 ;
    while(k<j)
    {
        
        int coeff , exp ;
        if(k==0)
        {
            scanf("%d" , &coeff) ;
            scanf("%d" , &exp) ;
            insertatbeginning(head , exp , coeff) ;
        }
        else
        {
            scanf("%d" , &coeff) ;
            scanf("%d" , &exp) ;
            insertatlast(head , exp , coeff) ;
        }
        k++ ;
    }
    printinglinkedlist(*head);
}

struct node* swap(struct node *ptr1 , struct node *ptr2 )
{
    struct node * temp ;
    temp=(ptr1)->next ;
    (ptr1)->next=(ptr2)->next ;
    (ptr2)->next=temp ;
    return ptr2 ;
}

int bubble_sort(struct node ** head)
{
    printf("getting the linked list sorted in some order.") ;
    struct node * p = *head ;
    int i=0 ;
    while(p)
    {
        i++ ;
        p=p->next ;
    }
    int j ;
    for(j=0 ; j<=i ; j++)
    {
        int swapped=0 ;
        struct node * ptr1 ;
        struct node * ptr2 ;
        int k ;
        ptr1=*head ;
        ptr2=(*head)->next ;
        for(k=0 ; k<i-j-1 ; k++)
        {
           if(ptr1->exponent > ptr2->exponent)
           {
            p=swap(ptr1 , ptr2) ;
            swapped=1 ;
           }
           p=p->next ;
           // ptr1=ptr1->next ;
            //ptr2=ptr2->next ;
        }
        if(swapped==0)
        {
            break ;
        }
    }
    printinglinkedlist(*head) ;
}

void additionofpolynomial(struct node * head1 , struct node * head2)
{
    printf("now we are adding both the polynomials \n") ;
    struct node * p =head1 ;
    struct node * q =head2 ;
    while(p && q)
    {
        
    }
}

int main()
{
    printf("first of all we are focusing upon representaion of polynomial using linked list\n") ;
    struct node * head1=NULL ;
    struct node * head2=NULL ;
    create(&head1);
    bubble_sort(&head1) ;
    printinglinkedlist(head1) ;
    //create(&head2);
    //bubble_sort(&head2) ;
    //printinglinkedlist(head2) ;
}
