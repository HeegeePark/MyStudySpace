# Brute-Force Algorithm
- 완전탐색은 모든 경우를 시도해봄으로써 답을 구하는 방법
- 하지만 모든 경우를 시도해보는 코드를 짜기가 까다로울 경우(ex N중 for문), **Brute-Force** 알고리즘을 사용함.

## 재귀호출을 이용한 BF구현
- 재귀함수 getResult(int current, int n, int result[])는 N중 for문을 수행하는 함수로, N이 무엇인지에 대한 다중 반복문의 제약이 없어짐.
- (**굉장히 중요한 코드**★)
``` 
void getResult(int current, int n, int result[]) {
	if(current >= n) {
		print(result);
	}
	
	else {
		for(int i=1; i<=n; i++) {
			if(isNotContaining(result, i) {
				result[current] = i;
				getResult(current+1, n, result);
				result[current] = 0;
			}
		}
	}
}
```

### [예제] 순열구하기
- N개의 알파벳 중에서 R개를 나열할 수 있는 경우를 모두 출력하시오
- [https://github.com/HeegeePark/DataStructure/blob/master/FinalNote/%EC%88%9C%EC%97%B4%EA%B5%AC%ED%95%98%EA%B8%B0/%EC%88%9C%EC%97%B4%EA%B5%AC%ED%95%98%EA%B8%B0/src.cpp](https://github.com/HeegeePark/DataStructure/blob/master/FinalNote/%EC%88%9C%EC%97%B4%EA%B5%AC%ED%95%98%EA%B8%B0/%EC%88%9C%EC%97%B4%EA%B5%AC%ED%95%98%EA%B8%B0/src.cpp "코드링크")






