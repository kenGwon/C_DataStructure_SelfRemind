/*
 - 자료구조: binary tree
 - 코드내용: binary tree를 순회하는 세가지 방법(pre-order, in-order, post-order) 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* left_node, treeNode* right_node);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);

int main(void)
{
    treeNode* n7 = makeRootNode('d', NULL, NULL);
    treeNode* n6 = makeRootNode('c', NULL, NULL);
    treeNode* n5 = makeRootNode('b', NULL, NULL);
    treeNode* n4 = makeRootNode('a', NULL, NULL);
    treeNode* n3 = makeRootNode('/', n6, n7);
    treeNode* n2 = makeRootNode('*', n4, n5);
    treeNode* n1 = makeRootNode('-', n2, n3);

    printf("preorder: "); preorder(n1); printf("\n");
    printf("inorder: "); inorder(n1); printf("\n");
    printf("postorder: "); postorder(n1); printf("\n");

    return 0;
}

treeNode* makeRootNode(char data, treeNode* left_node, treeNode* right_node)
{
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->data = data;
    root->left = left_node;
    root->right = right_node;
    return root;
}

void preorder(treeNode* root)
{
    if (root)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);        
    }
}

void inorder(treeNode* root)
{
    if (root)
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(treeNode* root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}







