#include <stdio.h>
#define MAX 20
void readSparse(int a[MAX][3])
{
    int r, c, n;
    printf("Enter no of non zero elements: ");
    scanf("%d", &n);
    printf("Enter no of rows elements: ");
    scanf("%d", &r);
    printf("Enter no of columns elements: ");
    scanf("%d", &c);
    a[0][0] = r;
    a[0][1] = c;
    a[0][2] = n;
    printf("enter the values row,column,value: ");
    for (int i = 1; i < n; i++)
    {
        if (a[i][3] != 0)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        }
    }
}
int printSparse(int a[MAX][3])
{
    int n;
    for (int i = 0; i < n; i++)
    {
        printf("%d%d%d", a[i][0], a[i][1], a[i][2]);
    }
    return 0;
}
int main(){
    int sample[MAX][3];
    readSparse(sample[MAX][3]);
    printSparse(sample[MAX][3]);
    return 0;

}
