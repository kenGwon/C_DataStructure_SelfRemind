/*
 - 자료구조: 그래프(graph)
 - 코드내용: 그래프의 깊이 우선 탐색(Depth First Search: DFS) 구현
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

// 그래프에 대한 인접 리스트의 노드 구조 정의
typedef struct graphNode
{
    int vertex;
    struct graphNode *link;
} graphNode;

typedef struct graphType
{
    int n; // 정점 갯수
    graphNode *adjlist_H[MAX_VERTEX]; // 정점에 대한 인접 리스트의 헤드 노드 배열
    int visited[MAX_VERTEX]; // 정점에 대한 방문 표시를 위한 배열
} graphType;

//**************DFS 구현을 위한 스택 구현부[start]**************
typedef int element;

typedef struct stack_node
{
    element data;
    struct stack_node* link;
} StackNode;

StackNode* top;

int isEmpty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(element item)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

element pop()
{
    if (top == NULL)
    {
        printf("스택이 텅 비어있습니다.\n");
        exit(1);
    }
    else
    {
        element result;
        StackNode* temp = top;
        result = temp->data;
        top = temp->link;
        free(temp);
        return result;
    }
}
//**************DFS 구현을 위한 스택 구현부[end]**************

// 깊이 우선 탐색을 위해 초기 공백 그래프를 생성하는 연산
void createGraph(graphType *g)
{
    int v;
    g->n = 0; // 그래프의 정점갯수를 0으로 초기화
    for (v = 0; v < MAX_VERTEX; v++)
    {
        g->visited[v] = FALSE;
        g->adjlist_H[v] = NULL;
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType *g, int v)
{
    if(g->n + 1 > MAX_VERTEX)
    {
        printf("\n그래프 정점의 갯수를 초과했습니다.");
        return;
    }
    else
    {
        g->n++;
    }
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType *g, int u, int v)
{
    graphNode *node;
    if (u >= g->n || v >= g->n)
    {
        printf("\n그래프에 없는 정점입니다!");
        return;
    }
    node = (graphNode *)malloc(sizeof(graphNode));
    node->vertex = v;
    node->link = g->adjlist_H[u];
    g->adjlist_H[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void print_adjList(graphType *g)
{
    int i;
    graphNode *p;
    for (i = 0; i < g->n; i++)
    {
        printf("\n\t\t정점 %c의 인접리스트", i + 65);
        p = g->adjlist_H[i];
        while (p)
        {
            printf(" -> %c", p->vertex + 65);
        }
    }
}

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType *g, int v)
{
    graphNode *w;
    top = NULL;
    push(v);
    g->visited[v] = TRUE;
    printf(" %c", v + 65);

    // 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
    while (!isEmpty())
    {
        v = pop();
        w = g->adjlist_H[v];
        //인접 정점이 있는 동안 수행
        while (w)
        {
            // 현재 정점 w를 방문하지 않은 경우
            if (!g->visited[w->vertex])
            {
                if(isEmpty()) push(v);
                push(w->vertex);
                g->visited[w->vertex] = TRUE;
                printf(" %c", w->vertex + 65);
                v = w->vertex;
                w = g->adjlist_H[v];
            }
            // 현재 정점 w가 이미 방문된 경우
            else
            {
                w = w->link;
            }
        } // 스택이 공백이면 DFS 종료
    }
}

int main(void)
{
    int i;
    graphType *G9;
    G9 = (graphType*)malloc(sizeof(graphType));
    createGraph(G9);

    // 그래프 G9 구성
    for (i = 0; i < 7; i++)
    {
        insertVertex(G9, i);
    }
    insertEdge(G9, 0, 2);
    insertEdge(G9, 0, 1);
    insertEdge(G9, 1, 4);
    insertEdge(G9, 1, 3);
    insertEdge(G9, 1, 0);
    insertEdge(G9, 2, 4);
    insertEdge(G9, 2, 0);
    insertEdge(G9, 3, 6);
    insertEdge(G9, 3, 1);
    insertEdge(G9, 4, 6);
    insertEdge(G9, 4, 2);
    insertEdge(G9, 4, 1);
    insertEdge(G9, 5, 6);
    insertEdge(G9, 6, 5);
    insertEdge(G9, 6, 4);
    insertEdge(G9, 6, 3);
    printf("\n G9의 인접 리스트");
    print_adjList(G9);

    printf("\n\n//////////////\n\n깊이 우선 탐색 >> ");
    DFS_adjList(G9, 0);

    getchar();
    
    return 0;   
}

