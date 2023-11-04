#include <stdio.h>
#include<stdlib.h>

int findmax(int a[] , int i )
{
    int j , max=a[0]  ;
    for(j=0 ; j<i ; j++)
    {
        if(a[j]>max)
        {
            max=a[j] ;
        }
    }
    return max ;
}

void CountSort(int a[] , int i)
{
    int k , *b , l ,m  , n=0 , j=0 , max;
    max=findmax(a , i) ;
    b=(int *)malloc(sizeof(int)*(max+1)) ;
    for(l=0 ; l<max+1 ; l++)
    {
        b[l]=0 ;
    }

    for(m=0 ; m<i ; m++)
    {
        b[a[m]]++ ;
    }

    while(n<max+1)
    {
        if(b[n]>0)
        {
            a[j++]=n ;
            b[n]-- ;
        }
        else
        {
            n++ ;
        }
    }
   /* for(k=0 ; k<i ; k++)
    {
        printf("%d" , a[k]) ;
    }
    */
}

int main ()
{
   
   /* int i , j=0 ;
    
    int a[j] ;
     printf("hi") ;
    printf("this is the program for count sort . enter the size of the array .") ;
    scanf("%d" , &i) ;
    while(i>-1)
    {
        scanf("%d" , a[i]) ; 
        i-- ;
    }
    count_sort(a , i ) ;*/

    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

 CountSort(A,n);

 for(i=0;i<10;i++)
 printf("%d ",A[i]);
 printf("\n");

 return 0;
}