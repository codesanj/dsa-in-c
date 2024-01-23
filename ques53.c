#include <stdio.h>
#include <stdlib.h>

struct Node {
    int column;
    int element;
    struct Node *next;
};

void CreateSparseMatrix(struct Node **X){
    int row, col, ele;
    struct Node *p;
    scanf("%d %d %d", &row, &col, &ele);
    if(X[row] == NULL){
        X[row] = (struct Node *) malloc(sizeof(struct Node));
        p = X[row];
        p->column = col;
        p->element = ele;
        p->next = NULL;
    }
    else{
        p = X[row];
        while(p->next != NULL){
            p=p->next;
        }
        struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
        temp->column = col;
        temp->element = ele;
        temp->next = NULL;
        p->next = temp;
    }
}

void DisplaySparseMatrix(struct Node **X, int m, int n){
    for(int i = 0; i < m; i++){
        struct Node *p = X[i];
        for(int j = 0; j < n; j++){
            if(p == NULL){
                printf("0 ");
            }
            else if(j == p->column){
                printf("%d ", p->element);
                if(p->next != NULL)
                    p = p->next;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int m, n, x;
    printf("Enter matrix dimensions:");
    scanf("%d %d", &m, &n);
    printf("Enter total number of non-zero elements: \n");
    scanf("%d", &x);
    
    struct Node** A = (struct Node **) malloc(sizeof(struct Node) * m); 
    
    printf("Enter all non-zero Elements:\n");
    for(int i = 1; i <= x; i++){
        printf("Enter row number, column number and non-zero element:\n");
        CreateSparseMatrix(A);
    }
    
    printf("\nSparse Matrix: \n");
    DisplaySparseMatrix(A, m, n);
}
