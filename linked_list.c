#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head;

void create(int n)
{
    struct node *temp1, *temp2;
    int data, i;
    head =(struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory cannot be allocated");
    }
    else
    {
        printf("enter data for node1: ");
        scanf("%d", &data);
        head->data = data;
        head->link = NULL;
        temp2 = head;
        for (i = 1; i < n; i++)
        {
            temp1 =(struct node *)malloc(sizeof(struct node));
            if (temp1 = NULL)
            {
                printf("memory cannot be allocated: ");
            }
            else
            {
                printf("enter data for node%d: ", i + 1);
                scanf("%d", &data);
                temp1->data = data;
                temp1->link = NULL;
                temp2->link = temp1;
                temp2 = temp2->link;
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("empty list/n");
    }
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
}
int main()
{
    int n;
    printf("enter no of nodes: ");
    scanf("%d", &n);
    create(n);
    display();
return 0;
}
