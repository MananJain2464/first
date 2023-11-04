#include <stdio.h>
#include <stdlib.h>

struct PolynomialTerm 
{
    int coefficient;
    int exponent;
};

struct Node 
{
    struct PolynomialTerm term;
    struct Node* next;
};

struct Node* insert_term_sorted(struct Node* poly_list, struct PolynomialTerm term) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->term = term;
    new_node->next = NULL;
    
    if (poly_list == NULL || term.exponent > poly_list->term.exponent) 
    {
        new_node->next = poly_list;
        return new_node;
    }
    
    struct Node* current = poly_list;
    while (current->next != NULL && current->next->term.exponent >= term.exponent) 
    {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    return poly_list;
}

struct Node* multiply_polynomials(struct Node* poly1, struct Node* poly2) 
{
    struct Node* result = NULL;
    struct Node* current1 = poly1;
    while (current1 != NULL) 
    {
        struct Node* current2 = poly2;
        while (current2 != NULL) 
        {
            struct PolynomialTerm term;
            term.coefficient = current1->term.coefficient * current2->term.coefficient;
            term.exponent = current1->term.exponent + current2->term.exponent;
            result = insert_term_sorted(result, term);
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return result;
}

void print_polynomial(struct Node* poly_list) 
{
    struct Node* current = poly_list;
    while (current != NULL) 
    {
        struct PolynomialTerm term = current->term;
        printf("%dx^%d", term.coefficient, term.exponent);
        if (current->next != NULL) 
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* poly1 = NULL;
    poly1 = insert_term_sorted(poly1, (struct PolynomialTerm){2, 3});
    poly1 = insert_term_sorted(poly1, (struct PolynomialTerm){-1, 2});
    poly1 = insert_term_sorted(poly1, (struct PolynomialTerm){3, 0});

    struct Node* poly2 = NULL;
    poly2 = insert_term_sorted(poly2, (struct PolynomialTerm){-2, 2});
    poly2 = insert_term_sorted(poly2, (struct PolynomialTerm){1, 1});

    printf("Polynomial 1: ");
    print_polynomial(poly1);

    printf("Polynomial 2: ");
    print_polynomial(poly2);

    struct Node* result_poly = multiply_polynomials(poly1, poly2);
    printf("Product: ");
    print_polynomial(result_poly);

    return 0;
}
