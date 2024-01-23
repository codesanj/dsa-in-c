#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term at the end of the polynomial
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
        return;
    }
    struct Term* current = *poly;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    // Insert terms into polynomial 1
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 7, 0);

    // Insert terms into polynomial 2
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, -5, 1);
    insertTerm(&poly2, 4, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial (Sum): ");
    printPolynomial(result);

    // Free memory
    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
