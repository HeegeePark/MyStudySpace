#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct GraphNode
{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;    // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

GraphType g;

// 그래프 초기화
void graph_init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_arr(int arr[], int in[], int s, int i, int size) {
    for (int j = 0; j < g.n; j++)
        printf("%3d", in[j]);
    printf("\n");
    for (int j = 0; j < g.n; j++)
        printf("%3d", arr[j]);
    printf("  - s:%d, i:%d, size:%d\n", s, i, size);
}
void generate(int arr[], int s, int size, int *in) {
    int i, tmp;
    int in_degree[MAX_VERTICES];
    for (i = 0; i < g.n; i++)            // copy
        in_degree[i] = in[i];

    GraphNode* node = g.adj_list[arr[s]];    //각 정점의 진입 차수를 변경
    while (node != NULL) {
        int u = node->vertex;
        in_degree[u]--;            //진입 차수를 감소
        if (in_degree[u] == 0)
            arr[size++] = u;
        node = node->link;   // 다음 정점
    }
    s++;
    if (s == g.n) {
        for (i = 0; i< g.n; i++)
            printf("정점%d->", arr[i]);
        printf("\n");
    }
    else {
        for (i= s; i < size; i++) {
            SWAP(arr[s], arr[i], tmp);
            generate(arr, s, size, in_degree);
            SWAP(arr[s], arr[i], tmp);
        }
    }

}
// 위상정렬을 수행한다.
void topo_sort()
{
    int i, tmp;
    int arr[MAX_VERTICES], size;
    int in_degree[MAX_VERTICES];

    // 모든 정점의 진입 차수를 계산
    for (i = 0; i < g.n; i++)            // 초기화
        in_degree[i] = 0;
    for (i = 0; i < g.n; i++) {
        GraphNode* node = g.adj_list[i];//정점 i에서 나오는 간선들
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    // 진입 차수가 0인 정점을 배열에 삽입
    size = 0;
    for (i = 0; i < g.n; i++) {
        if (in_degree[i] == 0)
            arr[size++] = i;
    }
    // 모든 위상 순서를 생성
    for (i = 0; i < size; i++) {
        SWAP(arr[0], arr[i], tmp);
        generate(arr, 0, size, in_degree);
        SWAP(arr[0], arr[i], tmp);
    }

}
//
int main(void)
{
    graph_init(&g);
    //문제에 주어진 그래프에 대한 인접리스트를 완성하시오.
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);
    
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 4, 5);
    
    //위상 정렬
    topo_sort();
    // 동적 메모리 반환 코드 생략
    return 0;

}
/*출력예시
정점0->정점1->정점2->정점4->정점3->정점5->
정점0->정점1->정점2->정점3->정점4->정점5->
정점0->정점1->정점4->정점2->정점3->정점5->
정점0->정점2->정점1->정점4->정점3->정점5->
정점0->정점2->정점1->정점3->정점4->정점5->
정점1->정점0->정점4->정점2->정점3->정점5->
정점1->정점0->정점2->정점4->정점3->정점5->
정점1->정점0->정점2->정점3->정점4->정점5->
정점1->정점4->정점0->정점2->정점3->정점5->
계속하려면 아무 키나 누르십시오 . . .
*/
/* 출력 결과
정점0->정점1->정점2->정점4->정점3->정점5->
정점0->정점1->정점2->정점3->정점4->정점5->
정점0->정점1->정점4->정점2->정점3->정점5->
정점0->정점2->정점1->정점4->정점3->정점5->
정점0->정점2->정점1->정점3->정점4->정점5->
정점1->정점0->정점4->정점2->정점3->정점5->
정점1->정점0->정점2->정점4->정점3->정점5->
정점1->정점0->정점2->정점3->정점4->정점5->
정점1->정점4->정점0->정점2->정점3->정점5->
계속하려면 아무 키나 누르십시오 . . .
*/
