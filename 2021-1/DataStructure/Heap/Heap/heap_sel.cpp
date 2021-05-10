#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200


typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

//main()애서 사용하는 함수를 완성하시오.
// 초기화 함수
void init(HeapType* h) {
    h -> heap_size = 0;
}

// 삽입 함수
void insert_min_heap(HeapType* h, element item) {
    int i;
    i = ++(h -> heap_size);
    
    // 트리를 올라가면서 부모 노드와 비교
    while((i != 1) && (item.key < h->heap[i/2].key)) {
        h -> heap[i] = h -> heap[i/2];
        i /= 2;
    }
    h -> heap[i] = item;    // 새로운 노드 삽입
}

// 삭제 함수
element delete_min_heap(HeapType* h) {
    int parent, child;
    element item, temp;
    
    item = h -> heap[1];
    temp = h -> heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while (child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 작은 자식노드 찾기
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key) {
            child++;
        }
        if (temp.key < h->heap[child].key) { break; }
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main()
{
    int sel_num = 10;
    element list[MAX_ELEMENT];
    int size = 100;
    HeapType heap;

    init(&heap);
    srand(1);
    printf("대상  리스트");
    for (int i = 0; i < size; i++) {
        list[i].key = rand() % 10000;
        if (i % 10 == 0)
            printf("\n");
        printf("%d ", list[i].key);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
        insert_min_heap(&heap, list[i]);

    printf("\n작은 키 %d 선택 리스트\n", sel_num);
    for (int i = 0; i < sel_num; i++)
        printf("%d ", delete_min_heap(&heap).key);
    
    printf("\n");
   
    return 0;
}
/*예시 결과
대상  리스트
41 8467 6334 6500 9169 5724 1478 9358 6962 4464
5705 8145 3281 6827 9961 491 2995 1942 4827 5436
2391 4604 3902 153 292 2382 7421 8716 9718 9895
5447 1726 4771 1538 1869 9912 5667 6299 7035 9894
8703 3811 1322 333 7673 4664 5141 7711 8253 6868
5547 7644 2662 2757 37 2859 8723 9741 7529 778
2316 3035 2190 1842 288 106 9040 8942 9264 2648
7446 3805 5890 6729 4370 5350 5006 1101 4393 3548
9629 2623 4084 9954 8756 1840 4966 7376 3931 6308
6944 2439 4626 1323 5537 1538 6118 2082 2929 6541

작은 키 10 선택 리스트
37 41 106 153 288 292 333 491 778 1101
계속하려면 아무 키나 누르십시오 . . .
*/
/* 출력 결과
 대상  리스트
 6807 5249 73 3658 8930 1272 7544 878 7923 7709
 4440 8165 4492 3042 7987 2503 2327 1729 8840 2612
 4303 3169 7709 7157 9560 933 3099 278 1816 5335
 9097 7826 3512 9267 3810 7633 979 9149 6579 8821
 1967 672 1393 9336 5485 1745 5228 4091 194 6357
 5001 1153 6708 7944 5668 1490 8124 2196 9530 903
 7722 4666 8549 8024 7801 6853 977 7408 8228 4933
 298 8981 8635 8013 3865 9814 9063 4536 9425 1669
 4115 94 5629 6501 6517 4195 105 404 9451 4298
 2188 1123 9505 6882 6752 1566 6716 337 4438 3144

 작은 키 10 선택 리스트
 73 94 105 194 278 298 337 404 672 878
 Program ended with exit code: 0
 */
