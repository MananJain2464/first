#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int coeffecient ;
    int exponent ;
    struct node * next ;
};
struct node* s=NULL ;
struct node* q=NULL ;
struct node* last=NULL ;
struct node*first=NULL ;
struct node* last2=NULL ;
struct node*first2=NULL ;

void createlinkedlist (int coeffecient , int exponent )
{
    last=(struct node *)malloc(sizeof(struct node)) ;
    last->coeffecient=coeffecient ;
    last->exponent=exponent ;
    last->next=NULL ;
    if(first==NULL)
    {
        first=last ;
        s=first ;
        return ;
    }
    while(s)
    {
        if(last->exponent > s->exponent)
        {
            if(s==first)
            {
                last->next=first ;
                first=last ;
            }
            last->next=s;
            
        }

    }
}

int main()
{
    printf("welcome to the polynomial addition and multiplication tool\n\n ") ;
    printf("enter the coefficient and exponent adjacently and respectively \n\n") ;
    int i=1 , j=1 ;
    int c , e ;
    first=last=NULL ;
    while(i==1)
    {
        printf("enter the coefficent\n") ;
        scanf("%d" , &c) ;
        printf("enter the exponent\n") ;
        scanf("%d" , &e) ;
        createlinkedlist(c , e ) ;
        printf("press 1 if polynomial continues") ;
        scanf("%d" , &i) ;
        if(i!=1)
        {
            break ;
        } 
    }

    //first=(struct node *)malloc(sizeof(struct node)) ;

    printf("Enter the second polynomial\n") ;
    while(j==1)
    {
        printf("enter the coefficent\n") ;
        scanf("%d" , &c) ;
        printf("enter the exponent\n") ;
        scanf("%d" , &e) ;
        createlinkedlist2(c , e ) ;
        printf("press 1 if polynomial continues") ;
        scanf("%d" , &j) ;
        if(j!=1)
        {
            break ;
        } 
    }
}