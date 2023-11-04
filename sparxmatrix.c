#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int column;
    int data;
    struct node *next;
};

void create(int r, int c, int data, struct node **temp, struct node **head)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->row = r;
    new_node->column = c;
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *temp = new_node;
        *head = *temp;
    }
    else
    {
        struct node *q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = new_node;
    }
}

void print(struct node *head)
{
    struct node *r = head;
    int maxrow = 0;
    int maxcol = 0;

    while (r != NULL)
    {
        if (r->row > maxrow)
        {
            maxrow = r->row;
        }
        if (r->column > maxcol)
        {
            maxcol = r->column;
        }
        r = r->next;
    }

    int **A = (int **)malloc(sizeof(int *) * maxrow);
    for (int i = 0; i < maxrow; i++)
    {
        A[i] = (int *)malloc(sizeof(int) * maxcol);
        for (int j = 0; j < maxcol; j++)
        {
            A[i][j] = 0;
        }
    }

    r = head;
    while (r != NULL)
    {
        A[r->row][r->column] = r->data;
        r = r->next;
    }

    for (int i = 0; i < maxrow; i++)
    {
        for (int j = 0; j < maxcol; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < maxrow; i++)
    {
        free(A[i]);
    }
    free(A);
}

int main()
{
    printf("This is a program for a sparse matrix as a linked list.\n");
    printf("Enter the number of non-zero elements in the matrix: ");
    int num_elements;
    scanf("%d", &num_elements);

    struct node *head = NULL;

    printf("Enter the row, column, and data respectively as input:\n");
    for (int j = 0; j < num_elements; j++)
    {
        int r, c, data;
        scanf("%d %d %d", &r, &c, &data);
        struct node *temp = NULL;
        create(r, c, data, &temp, &head);
    }

    print(head);

    /* Freeing allocated memory
    struct node *current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }*/
   
    return 0;
}
