#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
//반복 버젼
int search_binary1(int key, int low, int high) {
    int middle;
    while (low <= high) {                 // 아직 키들이 남아 있으면
        middle = (low + high) / 2;
        if (key == list[middle])
            return middle;     // 탐색 성공
        else if (key < list[middle])
            low = middle + 1;     // 오른쪽 부분리스트 탐색
        else high = middle - 1;             // 왼쪽 부분리스트 탐색
    }
    return -1;                     // 탐색 실패
}

//순환 버젼
int search_binary2(int key, int low, int high) {
//아래를 완성하시오.
    if (low > high) { return -1; }
    int middle = (low + high) / 2;
    if (key == list[middle]) {
        return middle;
    } else if (key < list[middle]) {
            return search_binary2(key, middle + 1, high);
    } else {
            return search_binary2(key, low, middle - 1);
    }
}
int compare(const void* v1, const void* v2)    // 비교함수 정의
{
    int cmpvalue1, cmpvalue2;

    cmpvalue1 = *(int*)v1;
    cmpvalue2 = *(int*)v2;
    
    //return cmpvalue1 - cmpvalue2;    // 오름차순 정렬
    return cmpvalue2 - cmpvalue1;    // 내림차순 정렬

}
int main(void)
{
    //srand((unsigned)time(NULL));
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 1000;
    qsort(list, MAX_SIZE, sizeof(int), compare);
    int key = 10, index;
    

    index= search_binary1(key, 0, MAX_SIZE - 1);
    printf("반복 이진 탐색 인덱스: %d\n", index);
    
    index= search_binary2(key, 0, MAX_SIZE - 1);
    printf("순환 이진 탐색 인덱스: %d\n", index);
    
    return 0;

}
/*예시 출력
반복 이진 탐색 인덱스: 9896
순환 이진 탐색 인덱스: 9896
계속하려면 아무 키나 누르십시오 . . .

실제출력
반복 이진 탐색 인덱스: 9896
순환 이진 탐색 인덱스: 9896
계속하려면 아무 키나 누르십시오 . . .
*/
