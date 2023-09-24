/*
 - 자료구조: double linked list
 - 코드내용: 자료구조 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct double_linked_list_node
{
    struct double_linked_list_node* front; 
    char data[10];
    struct double_linked_list_node* rear;
} Node;

typedef struct 
{
    Node* head;
} Node_head;

Node_head* createDoubleLinkedList(void);
void printDoubleLinkedList(Node_head* list);
void insertNode(Node_head* list, Node* pre, const char* data);
void deleteNode(Node_head* list, Node* old);
Node* searchNode(Node_head* list, const char* search_data);

int main(void)
{
    Node_head* DLL;
    Node* p;

    DLL = createDoubleLinkedList();
    printf("(1) 더블 링크드 리스트 생성 완료\n");
    printDoubleLinkedList(DLL); 

    printf("(2) 더블 링크드 리스트에 [월] 노드 삽입\n");
    insertNode(DLL, NULL, "월");
    printDoubleLinkedList(DLL); 

    printf("(3) 더블 링크드 리스트의 [월] 노드 뒤에 [수] 삽입\n");
    p = searchNode(DLL, "월");
    insertNode(DLL, p, "수");
    printDoubleLinkedList(DLL); 

    printf("(4) 더블 링크드 리스트의 [수] 노드 뒤에 [금] 삽입\n");
    p = searchNode(DLL, "수");
    insertNode(DLL, p, "금");
    printDoubleLinkedList(DLL); 

    printf("(5) 더블 링크드 리스트에서 [수] 노드 삭제\n");
    p = searchNode(DLL, "수");
    deleteNode(DLL, p);
    printDoubleLinkedList(DLL); 

    return 0;
}


Node_head* createDoubleLinkedList(void)
{
    Node_head* list;
    list = (Node_head*)malloc(sizeof(Node_head));
    list->head = NULL;
}

void printDoubleLinkedList(Node_head* list)
{
    Node* p;
    printf("DL =(");
    p = list->head;

    while (p != NULL)
    {
        printf("%s", p->data);
        p = p->rear;
        if (p != NULL) printf(", ");
    }

    printf(")\n");
}

void insertNode(Node_head* list, Node* pre, const char* data)
{
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, data);

    if (list->head == NULL)
    {
        new_node->front = NULL;
        new_node->rear = NULL;
        list->head = new_node;
    }
    else
    {
        new_node->rear = pre->rear;
        pre->rear = new_node;
        new_node->front = pre;
        if (new_node->rear != NULL)
        {
            new_node->rear->front = new_node;
        }
    }
}

void deleteNode(Node_head* list, Node* old)
{
    if (list->head == NULL) return;
    else if (old == NULL) return;
    else
    {
        old->front->rear = old->rear;
        old->rear->front = old->front;
        free(old);
    }
}

Node* searchNode(Node_head* list, const char* search_data)
{
    Node* temp;
    temp = list->head;

    while (temp != NULL)
    {
        if (strcmp(temp->data, search_data) == 0) return temp;
        else temp = temp->rear;
    }
    
    return temp;
}


