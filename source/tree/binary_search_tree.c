/*
 - 자료구조: binary search tree
 - 코드내용: BST 구현
*/

#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode
{
    char key;
    struct treeNode* left;
    struct treeNode* righit;
} treeNode;

treeNode* searchBST(treeNode *root, char x);
treeNode* insertNode(treeNode *p, char x);
void deleteNode(treeNode *root, element key);
void printBST(treeNode *root);
void menu(void);

int main(void)
{
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;

    root = insertNode(root, 'g');
    insertNode(root, 'g');
    insertNode(root, 'i');
    insertNode(root, 'd');
    insertNode(root, 'b');
    insertNode(root, 'm');
    insertNode(root, 'n');
    insertNode(root, 'a');
    insertNode(root, 'j');
    insertNode(root, 'e');
    insertNode(root, 'q');
    
    while (1)
    {
        menu();
        scanf("%c", &choice);

        switch (choice - '0')
        {
        case 1:
            printf("\t[BST 출력] ");
            printBST(root); printf("\n");
            break;
        
        case 2:
            printf("삽입할 문자를 입력하세요: ");
            scanf("%c", key);
            insertNode(root, key);
            break;
        
        case 3:
            printf("삭제할 문자를 입력하세요: ");
            scanf("%c", key);
            deleteNode(root, key);
            break;

        case 4:
            printf("찾을 문자를 입력하세요: ");
            scanf("%c", key);
            foundedNode = searchBST(root, key);
            if (foundedNode != NULL) printf("\n%c를 찾았습니다.", foundedNode->key);
            else printf("\n문자를 찾지 못했습니다.");
            break;

        case 5:
            return 0;

        default:
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요.");
            break;
        }
    }

   return 0;
}


treeNode* searchBST(treeNode *root, char x)
{
    treeNode* p;
    p = root;
    
    while (p != NULL)
    {
        if (x < p->key) p = root->left;
        else if (x = p->key) return p;
        else p = p->righit;
    }

    printf("찾는 key가 BST에 없습니다.\n");
    return p;
}

treeNode* insertNode(treeNode *p, char x)
{
    treeNode *new_node;

    if (p == NULL)
    {
        new_node = (treeNode*)malloc(sizeof(treeNode));
        new_node->key = x;
        new_node->left = NULL;
        new_node->righit = NULL;
        return new_node;
    } 
    else if (x < p->key) p->left = insertNode(p->left, x);
    else if (x > p->key) p->righit = insertNode(p->righit, x);
    else printf("이미 같은 키가 존재합니다!\n");

    return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode *root, element key)
{
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;

    parent = NULL;
    p = root;
    while ((p != NULL) && (p->key != key)) // 삭제할 노드의 위치를 탐색
    {
        parent = p;
        if (key < p->key) p = p->left;
        else p = p->righit;
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL)
    {
        printf("\n찾는 키가 BST에 없습니다.");
        return;
    }

    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->righit == NULL))
    {
        if (parent != NULL)
        {
            if (parent->left == p) parent->left = NULL;
            else parent->righit = NULL;
        }
        else root = NULL;
    }
    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p->left == NULL) || (p->righit == NULL))
    {
        if (p->left != NULL) child = p->left;
        else child = p->righit;

        if (parent != NULL)
        {
            if (parent->left == p) parent->left = child;
            else parent->righit = child;
        }
        else root = child;
    }
    // 삭제할 노드가 자식 노드를 두개 가진 경우
    else
    {
        succ_parent = p;
        succ = p->left;
        while (succ->righit != NULL) // 왼쪽 sub tree에서 후계자 찾기
        {
            succ_parent = succ;
            succ = succ->righit;
        }
        if (succ_parent->left == succ) succ_parent->left = succ->left;
        else succ_parent->righit = succ->righit;
        p->key = succ->key;
        p = succ;
    }
    free(p);    
}

// BST를 inorder로 순회하면서 출력
void printBST(treeNode *root)
{
    if (root)
    {
        printBST(root->left);
        printf("%c", root->key);
        printBST(root->righit);
    }
}

void menu(void)
{
    printf("\n*--------------------------------*");
    printf("\n\t1: 트리 출력");
    printf("\n\t2: 문자 삽입");
    printf("\n\t3: 문자 삭제");
    printf("\n\t4: 문자 검색");
    printf("\n\t5: 종료");
    printf("\n*--------------------------------*");
    printf("\n\t메뉴 입력>> ");
}