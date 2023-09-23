/*
 - 자료구조: 원형 연결 리스트(circular linked list)
 - 코드내용: 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// circular linked list의 node를 구조체로 정의
typedef struct ListNode
{
    char data[10];
    struct ListNode *link;
} listNode;

// 리스트의 시작을 나타내는 head node를 구조체로 정의
typedef struct  
{
    listNode *head;
} linkedList_h;

// 공백 circular linked list를 생성하는 연산
linkedList_h* createLinkedList_h(void); 
// 연결리스트를 순서대로 출력
void printList(linkedList_h*); 
//첫번째 노드 삽입연산
void insertFirstNode(linkedList_h*, const char*); 
// pre 뒤에 노드를 삽입하는 연산
void insertMiddelNode(linkedList_h*, listNode*, const char*);
// 원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(linkedList_h*, listNode*);
// 원형 연결 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h*, const char*);

int main(void)
{
    linkedList_h *CL;
    listNode *p;

    CL = createLinkedList_h();
    printf("(1) circular linked list 생성하기\n");
    getchar();

    printf("(2) circular linked list에 [월] 노드 삽입하기\n");
    insertFirstNode(CL, "월");
    printList(CL); getchar();

    printf("(3) circular linked list의 [월] 노드 뒤에 [수] 노드 삽입하기\n");
    p = searchNode(CL, "월");
    insertMiddelNode(CL, p, "수");
    printList(CL); getchar();

    printf("(4) circular linked list의 [수] 노드 뒤에 [금] 노드 삽입하기\n");
    p = searchNode(CL, "수");
    insertMiddelNode(CL, p, "금");
    printList(CL); getchar();

    printf("(5) circular linked list에서 [수] 노드 삭제하기\n");
    p = searchNode(CL, "수");
    deleteNode(CL, p);
    printList(CL); getchar();

    return 0;
}

linkedList_h* createLinkedList_h(void)
{
    linkedList_h *cl;
    cl = (linkedList_h*)malloc(sizeof(linkedList_h)); // head node 할당
    cl->head = NULL; // 공백 리스트 이므로 NULL로 설정
    return cl;
}

void printList(linkedList_h *cl)
{
    listNode *p;
    printf("CL = (");
    p = cl->head;
    
    do
    {
        printf("%s", p->data);
        p = p->link;
        if (p != cl->head) printf(" ,");
    } while (p != cl->head);  
    printf(")\n");  
}

void insertFirstNode(linkedList_h *cl, const char *x)
{
    listNode *new_node, *temp;
    new_node = (listNode*)malloc(sizeof(listNode));
    strcpy(new_node->data, x);
    
    if (cl->head == NULL) // 원형 연결 리스트가 공백인 경우
    {
        cl->head = new_node; // 새 노드를 리스트의 시작 노드로 연결
        new_node->link = new_node;
    } 
    else
    {
        temp = cl->head;
        
        while (temp->link != cl->head) temp = temp->link;

        new_node->link = temp->link;
        temp->link = new_node;
        cl->head = new_node;
    }
}

void insertMiddelNode(linkedList_h *cl, listNode *pre, const char *x)
{
    listNode *new_node;
    new_node = (listNode*)malloc(sizeof(listNode));
    strcpy(new_node->data, x);

    if (cl == NULL)
    {
        cl->head = new_node;
        new_node->link = new_node;
    }
    else
    {
        new_node->link = pre->link;
        pre->link = new_node;
    }
}

void deleteNode(linkedList_h *cl, listNode *old)
{
    listNode *pre;
    
    if (cl->head == NULL) return; // 공백 리스트인 경우 중단

    if (cl->head->link == cl->head) // 리스트에 노드가 한개만 있는 경우
    {
        free(cl->head);
        cl->head == NULL;
        return;
    }
    else if (old == NULL) return; // 삭제할 노드가 없는 경우 삭제 연산 중단
    else
    {
        pre = cl->head;
        
        while (pre->link != old) // 선행자 노드 포인터를 pre를 이용해 찾음
            pre = pre->link; 
        
        pre->link = old->link;
        
        if (old == cl->head)
            cl->head == old->link;
        
        free(old);
    }
}

listNode* searchNode(linkedList_h* cl, const char* x)
{
    listNode *temp;
    temp = cl->head;

    if (temp == NULL) return NULL;

    do {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    } while (temp != cl->head);
    
    return NULL;
}
