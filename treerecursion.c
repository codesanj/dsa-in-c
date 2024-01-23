#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* buildTree(){
      node* root;
      int d;
      printf("enter data of root: ");
      scanf("%d",&d);
      if(d==-1){
          return NULL;
      }
      root=malloc(sizeof(struct node));
      root->data=d;
      printf("enter left of %d:\n ",d);
      root->left=buildTree();
      printf("enter right of %d:\n ",d);
      root->right=buildTree();
      return root;
}

void printPre(node* root){
    if (root==NULL){
        return;
    }
    printf("\n%d",root->data);
    printPre(root->left);
    printPre(root->right);
}

int main(){
    node* root=buildTree();
    printPre(root);
}
