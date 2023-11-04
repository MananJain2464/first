#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node* next ;
} ;

int findmax(int a[] , int j )
{
    int i , max=a[0]  ;
    for(i=0 ; i<j ; i++)
    {
        if(a[i]>max)
        {
            max=a[i] ;
        }
    }
    return max ;
}

int no_of_iteration(int A[] , int j)
{
    int i ;
    int max_iteration=0 ;
    int max = findmax(A , j) ;
    i = max ;
    while(i!=0)
    {
        i=i/10 ;
        max_iteration++ ;
    }
    return max_iteration ; 
}

void insert(struct node** bin , int index , int value)
{
    struct node* temp ;
    temp=(struct node *)malloc(sizeof(struct node)) ;
    temp->data=value ;
    if (bin[index]==NULL)
    {
        bin[index]=temp ;
        temp->next=NULL ;
    }
    else
    {
        struct node *p=bin[index] ;
        while(p->next!=NULL)
        {
            p=p->next ;
        }
        p->next=temp ;
        temp->next=NULL ;
    }
}

int remove_element(struct node **bin , int index)
{
    struct node *p=bin[index] ;
    bin[index]=bin[index]->next ;
    int x = p->data;
    free(p);
    return x;
}

void radix_sort(int A[] , int j )
{
    int i ;
    int max=findmax(A , j) ;
    int iteration=no_of_iteration(A , j) ;
    int s=1 ;
    while(iteration!=0)
    {
        //struct node* bin ;
        // incorrect bin=(struct node **)malloc(sizeof(struct node)*10) ;   the below one is correct
        struct node* bin[10] = { NULL };
        int k;
        for(k=0 ; k<10 ;k++)
        {
          bin[k]=NULL ;  
        }

        int l ;
        for(l=0 ; l<j ; l++)
        {
            int value=A[l] ; 
            int index=(A[l]/s)%10 ;
            insert(bin , index , value ) ;
        }
        int m=0 ,n=0;
        while(m<10)
        {
            while(bin[m]!=NULL)
            {
                A[n++]=remove_element(bin ,m) ;

            }
            m++ ;
        }
        s=s*10 ;
        iteration-- ;
    }
   // delete bin ; wrong
}

int main()
{
     int A[10]={1,256,416,810,914,58,369,147,36,100} ;
    printf("this is the program for radix sort using linked list ") ;
    printf("\n Enter the numbers of elements you want ") ;
    int  j=10 ;
    /*scanf("%d" , &j) ;
    int i , A[j] ;
    for(i=0 ; i<j ; i++)
    {
        scanf("%d" , &A[i]) ;
    }*/
    radix_sort(A , j) ;
    for(j=0 ; j<10 ;j++)
    {
        printf("\n%d" , A[j]) ;
    }
}