#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int x)
{
    if (!root)
    {
        root = malloc(sizeof(struct node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        return (root);
    }
    if (root->data > x)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return (root);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
    return;
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
    return;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

struct node *delete(struct node *root, int x)
{
    struct tree *p1, *p2;
    if (!root)
    {
        printf("node not found");
        return (root);
    }
    else
    {
        if (root->data < x)
        {
            root->right = delete (root->right, x);
            return root;
        }

        if (root->data < x)
        {
            root->left = delete (root->left, x);
            return root;
        }

        if (root->data == x)
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }

            else if (root->left == NULL || root->right == NULL)
            {
                struct node *temp;
                if (root->right == NULL)
                {
                    temp = root->left;
                }
                else
                {
                    temp = root->right;
                }
                free(root);
                return temp;
            }
        }
        else
        {
            struct node *replace = root->right;
            while (root->left != NULL)
            {
                replace = replace->left;
                root->data = replace->data;
                root->right = delete (root->right, replace->data);
                return root;
            }
        }
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

int count(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int maxVal(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftMax = maxVal(root->left);
    int rightMax = maxVal(root->right);
    int value = 0;
    if (leftMax > rightMax)
    {
        value = leftMax;
    }
    else
    {
        value = rightMax;
    }
    if (value < root->data)
    {
        value = root->data;
    }
    return value;
}

int minVal(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftMin = mixVal(root->left);
    int rightMin = mixVal(root->right);
    int value = 0;
    if (leftMin > rightMin)
    {
        value = rightMin;
    }
    else
    {
        value = leftMin;
    }
    if (value < root->data)
    {
        value = root->data;
    }
    return value;
}
int main()
{
    struct node *root;
    int choice, item, item_no;
    root = NULL;
    clrscr();
    /* rear  = NULL;*/
    do
    {
        do
        {
            printf("\n \t 1. Insert in Binary Tree  ");
            printf("\n\t 2. Delete from Binary Tree ");
            printf("\n\t 3. Inorder traversal of Binary tree");
            printf("\n\t 4. Postorder traversal of Binary tree");
            printf("\n\t 5. Preorder traversal of Binary tree");
            printf("\n\t 6. Search and replace ");
            printf("\n\t 7. Height ");
            printf("\n\t 8. Count of nodes ");
            printf("\n\t 9. Minimum ");
            printf("\n\t 10. Maximum ");
            printf("\n\t 11. Exit ");
            printf("\n\t Enter choice : ");
            scanf(" %d", &choice);
            if (choice < 1 || choice > 11)
                printf("\n Invalid choice - try again");
        } while (choice < 1 || choice > 11);
        switch (choice)
        {
        case 1:
            printf("\n Enter new element: ");
            scanf("%d", &item);
            root = insert(root, item);
            printf("\n root is %d", root->info);
            printf("\n Inorder traversal of binary tree is : ");
            inorder(root);
            break;
        case 2:
            printf("\n Enter the element to be deleted : ");
            scanf(" %d", &item_no);
            root = delet(root, item_no);
            inorder(root);
            break;
        case 3:
            printf("\n Inorder traversal of binary tree is : ");
            inorder(root);
            break;
        case 4:
            printf("\n Postorder traversal of binary tree is : ");
            postorder(root);
            break;
        case 5:
            printf("\n Preorder traversal of binary tree is : ");
            preorder(root);
            break;
        case 6:
            printf("\n Search and replace operation in binary tree ");
            root = search(root);
            break;

        case 7:
            printf("\n Height of binary tree is : ");
            height(root);
            break;

        case 8:
            printf("\n Count of binary tree is : ");
            count(root);
            break;

        case 9:
            printf("\n Minimum value of binary tree is : ");
            minVal(root);
            break;

        case 10:
            printf("\n Maximum value of binary tree is : ");
            maxVal(root);
            break;

        default:
            printf("\n End of program ");
        }
        /* end of switch */
    } while (choice != 11);
    return (0);
}

