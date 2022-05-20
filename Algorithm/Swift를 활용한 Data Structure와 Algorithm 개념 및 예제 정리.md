# Swift를 활용한 Data Structure와 Algorithm 개념 및 예제 정리

### 1. 컴퓨터를 공부하면서 반드시 숙지해야 할 것

``` 
1. 문제 해결이 목적, 컴퓨터 프로그래밍은 그 수단
2. 문제 해결은 컴퓨터라는 연산 장치로 사람이 빠르게 할 수 없는 연산 같은 것을 컴퓨터로 효율적으로 처리하는 것을 예로 들 수 있음
3. 프로그래밍 언어란, 사람이 컴퓨터와 소통하기 위한 언어로 각각의 목적에 따라 여러 종류의 언어가 존재
```

### 2. 프로그램의 실행 단계

``` 
1. 인간이 이해할 수 있는 고급 프로그래밍 언어 => 컴파일러 => 어셈블리어 => Binary(01010..) => 프로그램 실행
```

### 3. 변수와 자료형

```
1. 변수: 컴퓨터에 데이터를 저장할 공간
2. 자료형: 컴퓨터에 저장할 데이터의 형태: 정수/실수, 문자, 문자열 등
3. 정수형 변수의 범위: -21억 ~ 21억(-2^31 ~ 2^31 - 1)
```

### 4. 캐스팅의 개념

```
1. 같은 자료형 사이의 연산은 그 자료형 연산으로 취급
2. 다른 자료형 사이의 연산은 더 큰 범위의 연산으로 취급
3. 즉, 자료형을 임시로 바꾸는 것을 캐스팅이라고 함.
```

### 5. 문제를 해결하기 전에 해야할 것

``` 
1. 해당 문제에 맞는 설계 후 프로그래밍을 진행해야 정확하고 실수없이 해결할 수 있음
```

### 6. 배열

``` 
1. 변수 여러 개를 한 번에 선언할 수 있는 방법
2. 장점: 데이터에 대한 접근이 빠름, 변수를 일일이 선언하지 않아도 동일한 자료형의 변수 여러 개를 한 번에 저장할 수 있음.
3. 단점: 데이터에 대한 삽입/삭제 연산이 느림, 정적인 크기 할당
```

### 7. 2차원 배열

```
1. 2차원 좌표평면과 유사
2. 가로, 세로가 존재
```

### 8. 완전 탐색에 대한 이해(Brute-Force Algorithm)

```
1. 문제 해결하는 방법이 여러가지가 있고, 흔히 사용하는 방법이 몇 가지 존재함.
2. 그 중 가장 간단한 문제 해결 방법이 완전 탐색
3. 가능한 모든 경우를 시도해보는 알고리즘
4. 완전 탐색을 수행하기 위해서는 모든 경우가 무엇인지 파악하는 것이 중요함.
5. 문제를 접했을 때 가장 먼저 접근해봐야 하는 알고리즘
```

### 9. 정렬(Sort)

```
1. 특정 기준을 적용하여 데이터를 나열하는 알고리즘
2. 오름차순 정렬/ 내림차순 정렬
```

### 9.1. 기본적인 정렬 알고리즘의 종류

**9.1.1. 선택정렬(Selection Sort)**

```
1. 최솟값을 맨 앞으로 이동시킴(오름차순)
2. 왼쪽은 정렬이 모두 되었다는 의미
3. O(N^2)의 시간복잡도를 가짐
```

``` swift
for i in 0..<N-1 {
  var index = i
  for j in (i+1)..<N {
    if data[index] > data[j] {
      index = j
    }
  }
  
  let temp = data[index]
  data[index] = data[i]
  data[i] = temp
}
```

**9.1.2. 삽입정렬(Insertion Sort)**

```
1. 원소를 차례대로 정렬된 배열에 삽입시킴
2. 왼쪽은 정렬이 모두 되었다는 의미
3. O(N^2)의 시간복잡도를 가짐
```

```swift
for i in 1..<N {
  for j in 0...i-1.reversed() {
    if data[j + 1] < data[j] {
      let temp = data[j + 1]
      data[j + 1] = data[j]
      data[j] = temp
    }
  }
}
```

**9.1.3. 버블정렬(Bubble Sort)**

```
1. 인접한 원소를 비교하여 큰 수를 뒤로 보냄
2. 오른쪽은 정렬이 모두 되었다는 의미
3. O(N^2)의 시간복잡도를 가짐
```

```swift
for i in 1...N-1.reversed() {
  for j in 0..<i {
    if data[j] > data[j + 1] {
      let temp = data[j]
      data[j] = data[j + 1]
      data[j + 1] = temp
    }
  } 
}
```

### 10. 시간 복잡도(Time Complexity)

```
1. 문제를 효율적으로 해결
2. 똑같은 문제를 해결 하더라도 빠르게 해결하는 것이 중요
3. 시간 복잡도를 계산 함으로써, 프로그램을 직접 실행해보지 않더라도 얼마나 빠른지 대략적으로 알 수 있음
4. O(1), O(N), O(N^2) ... 중 가장 영향력 있는 시간복잡도가 최악의 경우 시간 복잡도를 결정(최고차항)
5. 컴퓨터 사양마다 명령을 수행하는데 걸리는 시간은 다 다르지만 비슷하다고 가정했을 때, 대략 1억번 연산을 수행하는데 1초가 걸림
```

### 11. 기본 정수론(Basic Number Theory)

```
1. 정수(Integer)의 성질을 연구하는 분야
2. 가령, 약수와 배수
```

### 11.1. 약수(Divisor)

```
특정 정수를 나누어 떨어지게 하는 수
```

### 11.2. 소수(Prime Number)

```
약수가 1과 자기 자신 뿐인 정수
```

### 11.3. 에라토스테네스의 체

```
1. 소수를 구하는 알고리즘 중 하나
2. 소수의 배수를 지워 나감으로써 2부터 특정 범위 내의 소수를 얻을 수 있음
3. O(N log N)의 시간복잡도를 가짐
4. 2부터 N까지 모든 숫자들 중 모든 소수를 구할 때 사용하면 빠르지만, 특정 수가 소수인지 아닌지 판별할 때는 제곱근 까지 나눠보는 것이 더 빠름
```

### 11.4. 소인수분해

```
1. 숫자 N을 소수의 곱으로 나타냄
2. 2부터 시작해서 차례대로 전부 나누어봄(2로 나누어 지는 수는 이미 앞에서 나눌 수 있을 때 까지 다 나누었기 때문에 4로 나누어지지 않는 것이 가능함, 3과 6, 5와 10 마찬가지)
```

### 11.5. 유클리드 호제법

```
1. 공약수: A의 약수 이면서 동시에 B의 약수인 수
2. 공배수: A의 배수 이면서 동시에 B의 배수인 수
3. 최대공약수(GCD, Greatest Common Divisor): A의 약수 이면서 동시에 B의 약수인 수 중 가장 큰 수
4. 최소공배수(LCM, Least Common Multiple): A의 배수 이면서 동시에 B의 배수인 수 중 가장 작은 수
5. 유클리드 호제법: 최대공약수를 구하기 위한 알고리즘
```

``` swift
func getGCD(_ a: Int, _ b: Int) -> Int {
  return a % b == 0 ? b: getGCD(b, a % b)
}
```

### 11.6. 파스칼 삼각형

``` 
1. 왼쪽 오른쪽 각 대각선 위의 수를 합하여 자신을 결정하는 형태
2. 조합과 관련이 있음(파스칼 삼각형을 이용하면 조합을 쉽게 구할 수 있음)
3. 경우의 수 문제에서 숫자가 굉장히 큰 경우 활용할 수 있음. 가령, 20 C 10의 끝 3자리 수를 구하는 경우(파스칼 삼각형을 구성할 때, % 1000 연산 하면 됨)
4. n C r = pascal[n][r]
```

``` swift
func getPascalTriangle(_ N: Int) {
  var pascal: [[Int]] = Array(repeating: Array(repeating: 0, count: N + 10), count: N + 10)
  
  pascal[0][0] = 1
  for i in 1...N {
    pascal[i][0] = 1	// n C 0 = 1
    pascal[i][i] = 1	// n C n = 1
    
    for j in 1..<i {
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
    }
  }
}
```

### 12. 문자형 변수(Character)

```
오직 하나의 문자만 담을 수 있는 자료형
```

### 13. 아스키 코드(Ascii Code)

```
1. 컴퓨터는 문자를 모르기 때문에 숫자로 인식함
2. 출력할 때만 그 숫자에 대응되는 문자로 출력함
3. 숫자에 대응되는 문자 정보가 담긴 표를 아스키코드 표라고 함
```

### 14. 문자열(String)

```
1. 문자만으로 이루어진 배열
2. 여러 개의 문자를 저장할 수 있음
```

### 15. 함수(Function)

```
1. 수학에서 어떤 숫자가 들어왔을 때 처리를 해서 출력하는 것
2. 값을 입력받아 특정 연산을 수행하여 결과를 반환하는 것
```

``` swift
func 함수이름() -> 반환타입 {
  구현체
  반환값
}
```

### 16. 스코프(Scope)

```
1. 변수는 선언된 블록 내에서만 접근할 수 있음
2. 함수 간 작업의 완벽한 분담을 위해 스코프가 존재함
```

### 17. 포인터(Pointer)

```
1. 값을 저장하는 것이 아닌, 값의 위치(메모리 주소)를 저장하는 변수
2. 해당 주소가 가리키는 곳으로 접근하면 실제 저장되어 있는 값을 알 수 있음
3. 작성한 코드가 컴퓨터 내부적으로 어떻게 동작하는지에 대한 원리는 반드시 파악하고 있어야 하기 때문에 포인터의 개념이 중요함
```

### 18. 메모리(Memory)

```
1. 자료의 저장단위: 비트(Bit), 바이트(Byte), 킬로바이트(KB), 메가바이트(MB), 기가바이트(GB) ...
2. RAM(Random Access Memory): 자료를 저장하기 위한 장치, 위치마다 접근하는데 걸리는 시간이 비슷하기 때문에 Random이라고 함
3. PC의 운영체제가 우리가 흔히 알고 있는 64bit 운영체제, 32bit 운영체제라는 것은 메모리 하나의 주소의 크기가 64bit, 32bit라는 것
4. 즉, 메모리의 주소 하나가 최대로 담을 수 있는 용량이 8Byte(64bit), 4Byte(32bit)라는 말과 동일
5. Big Endian, Little Endian: 컴퓨터가 값을 저장하는 순서, 높은 숫자 부터 저장하는 것이 Big Endian, 낮은 숫자부터 저장하는 것이 Little Endian
```

### 19. 운영체제(Operating System)

```
1. 정의: 하드웨얼르 제어하기 위한 소프트웨어(ex) Linux, MacOS, Windows, iOS, Android ...)
```

### 20. Call By Value vs Call By Reference

```
1. call by value: 값에 의한 호출, 변수의 값을 복사해서 인자로 넘겨줌. 따라서 원본의 값이 변경되지 않음
2. call by reference: 참조에 의한 호출, 변수의 주소를 인자로 넘겨줌. 따라서 원본의 값이 변경됨
```

### 20.1. Swift에서 Array

``` swift
@frozen public struct Array<Element> {
  /// The total number of elements that the array can contain without
  /// allocating new storage
  ///
```

```
1. Swift에서 Array는 struct 즉, 값 타입이기 때문에 전달인자로 전달될 때 값이 복사돼서 넘어감
2. Call By Value를 Call By Reference 처럼 사용할 수 있는 방법이 있지만, 권장하지 않음
3. 단, 아래와 같이 정확한 목적이 있는 경우에는 inout 키워드와 &(주소)값을 넘김으로써 사용할 수도 있음
```

``` swift
func swap(_ a: inout Int, _ b: inout Int) {
  let temp = a
  a = b
  b = a
}

func solution() {
  var a = 5
  var b = 10
  
  swap(&a, &b)
  
  print("\(a) \(b)")	// 10 5
}
solution()
```

### 21. 재귀함수(Recursive Function)

```
1. 자기자신을 부르는 함수
2. 재귀함수도 함수이기 때문에 값을 입력받아 특정 연산을 수행하여 결과를 반환함
3. 귀납적 계산 방법을 따름
4. 귀납적 계산법이란, f(x)를 구하기 위해 또 다시 f(x)를 활용
5. 귀납적 계산법은 계산하기 위해 자기자신을 사용하는 식과 멈춰야 하는 기저조건이 존재
```

### 21.1. 수학적 귀납법

```
1. 명제 P(n)이 모든 자연수 n에 대하여 성립함을 보이는 것
2. 증명 순서: 
	1. P(1)이 참임을 보임
	2. P(k)가 성립한다고 가정한 후, P(k + 1)이 성립함을 보임
	3. 따라서 모든 자연수 n에 대하여 P(n)이 성립함
3.재귀함수가 정확한 값을 반환하는지 증명하기 위해 수학적 귀납법을 사용함
```

### 21.2. 재귀함수의 디자인 절차

``` 
1. 먼저 문제 속에서 재귀적 패턴(자기자신을 사용하는 패턴)을 파악해야 함
2. 함수의 역할을 말로써 정확하게 정의함
3. 기저조건에서 함수가 제대로 동작함을 보임
4. 함수가 제대로 동작한다고 가정하고 함수를 완성함
```

``` swift
func getFactorial(_ N: Int) -> Int {
  // 기저조건
  if N == 0 {
    return 1
  }
  
  return N * getFactorial(N - 1)
}
```

### 22. Back-tracking(Advanced Brute-Force Algorithm)

```
1. 모든 경우를 시도해 보는 코드를 구현하기가 까다로운 경우
2. 가령, 문제의 크기 N에 따라 N중 반복문을 구현해야 하는 경우
3. 재귀호출을 이용하여 편리하게 구현할 수 있음
4. ex) 순열 구하기
```

### 22.1. Back-tracking Idea

``` swift
func doRecursion(_ depth: Int) {
  // x번째 for문을 실행
  if depth > n {
    print(numbers)
  } else {
    for i in 1...n {
      if !numbers[i] { 
        numbers[i] = true
        doRecursion(depth + 1)
      }
    }
  }
}
```

### 23. 고급정렬(Advanced Sort)

```
1. 특정 기준을 적용하여 나열함
2. 기본 정렬: 선택 정렬, 삽입 정렬, 버블 정렬
3. 기본 정렬 시간복잡도: O(n^2)
4. O(n log n)만에 정렬할 수 있는 알고리즘: 합병 정렬, 퀵 정렬, 힙 정렬
```

### 23.1. 로그의 개념과 그 효율성

```
1. 로그의 정리: 지수함수의 역함수, logx(y) = z => x^z = y
2. 즉, x를 몇 번 곱해야 y가 되는가?
3. CS에서 log를 사용하는 경우, 그 밑이 2 이므로 보통 밑을 생략
4. log가 있는 경우, 시간 복잡도를 많이 줄일 수 있으므로 효율적인 알고리즘
```

### 23.2. 합병 정렬(Merge Sort)

```
1. 재귀호출을 이용함
2. 배열을 절반으로 나누어 각각을 정렬한 후 합침
3. 시간 복잡도: O(n log n)
```

``` swift
func mergeSort(_ array: [Int]) -> [Int] {
  if array.count <= 1 { return array }
  let center = array.count / 2
  let left = Array(array[0..<center])
  let right = Array(array[center..<array.count])
  
  func merge(_ letft: [Int], _ right: [Int]) -> [Int] {
    var left = left
    var right = right
    var result = [Int]()
    
    while !left.isEmpty && !right.isEmpty {
      let value = letft[0] < right[0] ? left.removeFirst(): right.removeFirst()
      result.append(value)
    }
    
    // 왼쪽 배열 요소 남은 경우
    if !left.isEmpty {
      result += left
    }
    // 오른쪽 배열 요소 남은 경우
    if !right.isEmpty {
			result += right
    }
    return result
  }
  return merge(mergeSort(left), mergeSort(right))
}
```

### 23.3. 퀵 정렬(Quick Sort)

```
1. 재귀호출을 이용함.
2. 원소를 하나 정하여(pivot), 해당 원소보다 작은 수/큰 수로 배열을 나눔
3. 시간 복잡도: pivot이 원소를 절반으로 나눈다고 가정했을 때, 평균적으로 O(n log n)이고, pivot이 가장 크거나 작은 경우(n^2)
	- 모든 데이터를 비교해야 하므로
```

``` swift
func quickSort(_ array: [Int]) -> [Int] {
  guard let first = array.first, array.count > 1 else { return array }
  
  let pivot = first
  let left = array.filter { $0 <= pivot }
  let right = array.filter { $0 > pivot }
  
  return quickSort(left) + [pivot] + quickSort(right)
}
```

### 23.4 대표 정렬 알고리즘 시간 복잡도 비교(Time Complexity of Sort Algorithm)

| -               | 선택 정렬(Selection) | 삽입 정렬(Insertion) | 버블 정렬(Bubble) | 합병 정렬(Merge) | 퀵 정렬(Quick) |
| --------------- | -------------------- | -------------------- | ----------------- | ---------------- | -------------- |
| 평균 시간복잡도 | -                    | -                    | -                 | -                | O(N log N)     |
| 최악의 경우     | O(N^2)               | O(N^2)               | O(N^2)            | O(N log N)       | O(N^2)         |

### 24. 이진 탐색(Binary Search)

```
1. 탐색: 특정 값을 찾음
2. 이진 탐색: 정렬되어 있는 값들 중 특정 값을 찾는 것
3. 찾고자 하는 값과 중간 값을 비교하여 절반씩 제거할 수 있음
4. 숫자를 절반씩 지워나가기 때문에 O(n log n)의 시간 복잡도를 가짐
5. 이미 정렬되어 있다면, 이진 탐색이 굉장히 효율적이고 정렬을 다시 하더라도 숫자를 엄청 많이 탐색해야 하는 경우에도 효율적임
```

``` swift
func binarySearch(_ array: [Int], _ start: Int, _ end: Int, _ value: Int) -> Bool {
  if start >= end {
    return array[start] == value ? true: false
  }
  
  let mid = (start + end) / 2
  if array[mid] == value {
    return true
  }
  
  return array[mid] < value ? binarySearch(array, mid + 1, end, value): binarySearch(array, start, mid - 1, value)
}
```

### 24.2 매개 변수 탐색(Parametric Search)

```
1. Binary Search를 이용하여 문제를 해결하는(조건을 만족하는 최대값을 구하는) 테크닉
2. 원래의 값들을 대신할 수 있는 매개변수들이 정렬되어 있는 경우 사용할 수 있음
3. 원래의 값들을 통해 매개 변수를 구하기 위한 별도 작업이 필요함
```

**관련 문제**

```
- BOJ 2805 - 나무 자르기
- BOJ 1654 - 랜선 자르기
- BOJ 2512 - 예산
- BOJ 2110 - 공유기 설치
- BOJ 2343 - 기타 레슨
- BOJ 6236 - 용돈 관리
- BOJ 13702 - 이상한 술집
- BOJ 17266 - 어두운 굴다리
- BOJ 1300 - K 번째 수 (고난이도)
- BOJ 1637 - 날카로운 눈 (고난이도)
```

### 25. 기본 자료구조(Basic Data-Structure)

```
1. 자료를 저장한느 구조
2. Stack, Queue, Tree, Graph ...
3. 특정 목적에 따라 자료를 저장하는 방법이 달라 목적(각 장단점에 의거)에 맞게 사용할 수 있어야 함
4. 저장되어 있는 자료구조를 바탕으로 의미있는 결괄르 도출하는 과정이 알고리즘
5. 가장 기본이 되는 자료구조: 변수, 배열
```

### 25.1. 배열 VS 연결 리스트

| -                | 배열(Array / ArrayList) | 연결 리스트(Linked List)          |
| ---------------- | ----------------------- | --------------------------------- |
| 장점             | 탐색이 빠름             | 배열에 비해 삽입/삭제 연산이 빠름 |
| 단점             | 삽입/삭제 연산이 느림   | 배열에 비해 탐색이 느림           |
| 탐색 시간 복잡도 | O(1)                    | O(N)                              |
| 삽입 시간 복잡도 | 평균적으로 O(N)         | 평균적으로 O(1)                   |
| 삭제 시간 복잡도 | 평균적으로 O(N)         | 평균적으로 O(1)                   |

### 25.2. 캡술화(Encapsulation)

```
1. 자료구조 구현의 핵심
2. 자료구조를 사용하는 사람은 자료구조가 어떻게 동작하는지 알 필요가 없음
3. 구현한 사람외에 사용하는 사람은 사용법만 알아야 함
```

### 25.3. 구조체(Struct)

```
1. 캡슐화를 통해 구현하며, 캡슐화를 구현하기 위해 사용
2. 하나의 자료형(Type)을 정의할 수 있음
3. 여러 프로퍼티와 메소드로 이루어져 있어, 관련된 데이터끼리 묶을 수 있음
```

### 26. 스택(Stack)

```
1. Computer Science의 대표적인 자료구조 중 하나
2. Linear(선형) 자료구조
3. 자료를 쌓으면서 저장하는 자료구조
4. LIFO 특징을 가지고 있어, 순서를 뒤집거나 발자취를 기록할 때 사용 가능
5. Push/Pop 연산 가능
6. Stack Overflow: Stack은 정해진 크기가 있어, 용량이 다 찼음에도 불구하고 데이터를 삽입할 경우 Stack Overflow 발생
7. Stack Underflow: Stack이 비었음에도 불구하고 데이터를 삭제하려고 하는 경우
```

``` swift
struct Stack {
	// Property
  var array: [Int]
  var len: Int
  var capacity: Int
  
  // Initializer
  init(_ capacity: Int) {
    self.capacity = capacity
    self.array = Array(repeating: 0, count: capacity)
    self.len = 0
  }
  
  // Method
  mutating func push(_ data: Int) {
    if len >= capacity {
      print("Overflow")
    } else {
      self.array[self.len] = data
      self.len += 1
    }
  }
  
  mutating func pop() {
    if self.len <= 0 {
      print("Underflow")
    } else {
      self.array[self.len - 1] = 0
      self.len -= 1
    }
  }
  
  func top() -> Int {
    return self.len <= 0 ? -1: self.array[len - 1]
  }
}
```

### 27. 큐(Queue)

```
1. Stack과 함께 Computer Science 기초 자료구조 중 하나
2. FIFO 구조
3. Linear(선형) 자료구조
4. Queue Overflow: Queue의 용량보다 데이터를 더 넣으려고 하는 경우
5. Queue Underflow: Queue에 데이터가 없는데 데이터를 삭제하려고 하는 경우
6. 단순 투 포인터로 큐를 구현하게 되는 경우 push/pop 연산 시 두 포인터가 모두 증가만 하게 되므로,
앞의 공간에 대한 낭비가 발생할 수 있음
```

### 27.1. 원형 큐의 개념과 구현 방법(Circular Queue)

```
1. 선형 큐의 공간 낭비의 단점을 해결하기 위한 큐
2. 선형 큐에 비해 공간 활용 능력이 우수
3. 원소의 개수를 유지하는 별도의 변수가 필요
4. front, rear 투 포인터가 끝에 도달하게 되면 push/pop 연산 시 다시 처음으로 되돌리는 형태
```

``` swift
struct Queue {
  // Property
  private var array: [Int]
  private var f: Int
  private var r: Int
  private var capacity: Int
  
  // Initializer
  init(_ capacity: Int) {
    self.capacity = capacity
    self.array = Array(repeating: 0, count: capacity)
    self.f = 0
    self.r = 0
  }
  
  // Method
  mutating func push(_ data: Int) {
    if self.r >= self.capacity {
      print("Overflow")
    } else {
      self.array[self.r] = data
      self.r += 1
    }
  }
  
  mutating func pop() {
    if self.r - self.f <= 0 {
      print("Underflow")
    } else {
      self.array[self.f] = 0
      self.f += 1
    }
  }
  
  func front() -> Int {
    return self.r - self.f <= 0 ? -1: self.array[self.f]
  }
  
  func size() -> Int {
    return self.r - self.f
  }
}
```

### 27.2. 스택 & 큐 정리(Stack & Queue Summary)

```
1. 특정 자료구조가 무엇인지 아는 것은 중요하지 안혹, 의도에 맞게 사용하는 능력이 중요
2. 올바른 괄호 판단 문제는 대표적인 Stack 자료구조를 활용하는 문제
3. Stack과 Queue에는 상태(status) 즉, 해야 하는 작업이 저장됨
4. Stack의 경우, 함수 호출에 대한 복귀 주소 즉, 발자취를 기록 해두며, 이를 Call Stack이라고 함
	(Stack의 Scheduling, 재귀호출)
5. Queue의 경우, Stack과 달리 상태의 의존관계가 없을 때, 즉 해야 하는 작업을 진행할 때 다른 작업에 영향을 받지 않고 순서대로 처리하며, 대표적으로 스케쥴링, 병렬화에 많이 사용
```

### 28. 트리(Tree)

```
1. 트리 역시 자료를 담는 Computer Science의 기초 자료구조 중 하나
2. 계층형(Hierarchy) 자료구조
3. 정점(Node), 간선(Edge)로 이루어져 있으며, 간선은 두 정점을 잇는 선
4. 부모와 자식관계를 가지며 레벨은 높이를 뜻함
5. 트리는 그 안에 또 트리가 존재하며(재귀적 성질), 이를 서브트리(Subtree)라고 함
6. 최상위 부모노드를 root라고 함
```

### 28.1 트리의 순회(Tree Traversal)

```
1. 트리 내에 어떠한 자료가 담겨 있는지를 알기 위한 방법
2. 순회하는 방법은 많지만, 재귀적 성질을 이용해서 순회하는 방법이 젤 중요함
```

### 28.1.1. 이진 트리 재귀적 순회 방법

```
1. 자식노드가 2개 이하인 트리를 Binary Tree(이진 트리)라고 함
2. 전위 순회: Root-L(left subtree)-R(right subtree)
3. 중위 순회: L(left subtree)-Root-R(right subtree)
4. 후위 순회: L(left subtree)-R(right subtree)-Root
5. 세가지 순회방법이 목적은 트리 내의 자료를 탐색하는 것으로 같지만, 특성이 다름
```

``` swift
struct Node {
  var left: Int
  var right: Int
  
  init(_ left: Int, _ right: Int) {
    self.left = left
    self.right = right
  }
}

func preOrder(_ tree: [Node], _ root: Int) {
  if root == -1 { return }
  
  print("\(root) ", terminator: "")
  preorder(tree, tree[root].left)
  preorder(tree, tree[root].right)
}

func inOrder(_ tree: [Node], _ root: Int) {
  if root == -1 { return }
  
  inOrder(tree, tree[root].left)
  print("\(root) ", terminator: "")
  inOrder(tree, tree[root].right)
}

func postOrder(_ tree: [Node], _ root: Int) {
  if root == -1 { return }
  
  postOrder(tree, tree[root].left)
  postOrder(tree, tree[root].right)
  print("\(root) ", terminator: "")
}
```

### 28.2. 우선순위 큐(Priority Queue)

```
1. Tree를 활용하는 대표적인 예제
2. 원소를 제거할 때, 우선순위가 가장 높은 원소를 제거
3. 배열로 우선순위 큐를 구현하게 되면, 삽입 연산은 효율적이지만 삭제 연산의 경우 비효율 적일 수 있음
```

### 28.2.1. 힙(Heap)

```
1. 부모의 값이 항상 자식보다 우선순위가 높은 완전이진트리
2. 자식노드가 2개 이하인 이진트리 이면서, 값이 왼쪽부터 채워지는 트리를 완전이진트리라고 부름
3. 힙에 값을 삽입하게 되면, 완전이진트리 특성에 따라 왼쪽부터 채워지고, 부모와 자식 사이의 우선순위를 비교하여 트리를 재구성해야 함
4. 노드가 n개일 때, 높이가 대략 log n이므로 높이가 1개 증가할 때 마다 노드는 약 2배 증가하게 됨
5. 즉, 삽입 연산 시 최악의 경우 트리의 높이 만큼 비교 연산을 수행 하므로, O(log n)의 시간 복잡도를 가짐
6. 힙에서 삭제 연산을 하게 되면, 우선순위가 가장 높은 root를 삭제하고, 가장 끝에 있는 자식 노드를 root로 옮기고 우선순위를 비교하여 트리를 재구성해야 함
7. 삽입 연산과 마찬가지로 root에서 최대로 트리의 높이 만큼 내려올 수 있으므로, O(log n)의 시간복잡도를 가짐
```

### 28.2.2. 우선순위 큐 구현(배열)

``` swift
struct PriorityQueue {
  // property
  private var data: [Int]
  private var len, capacity: Int
  
  // Initializer
  init(_ capacity: Int) {
    self.capacity = capacity
    self.data = Array(repeating: 0, count: capacity + 10)
    self.len = 0
  }
  
  // Method
  mutating func push(_ x: Int) {
    self.data[self.len] = x
    self.len += 1
  }
  
  mutating func pop() {
    var min: Int = self.data[0], minIndex: Int = 0
    for i in 0..<self.len {
      if min > self.data[i] {
        min = self.data[i]
        minIndex = i
      }
    }
    
    for i in minIndex..<self.len {
      self.data[i] = self.data[i + 1]
    }
    
    self.len -= 1
  }
  
  func top() -> Int {
    var min: Int = self.data[0]
    for i in 0..<self.len {
      min = min > self.data[i] ? self.data[i]: min
    }
    
    return min
  }
}
```

### 28.2.3. 우선순위 큐 구현(힙)

```swift
struct PriorityQueue {
  // Property
  var data: [Int]
  var len, capacity: Int
  
  // Initializer
  init(_ capacity: Int) {
    self.capacity = capacity
    self.data = Array(repeating: 0, count: self.capacity + 10)
    self.len = 1
  }
  
  mutating func push(_ x: Int) {
    self.data[self.len] = x
    self.len += 1
    
    var currentIndex: Int = self.len - 1
    while currentIndex > 1 {
      if self.data[currentIndex] < self.data[currentIndex >> 1] {	// 자식 < 부모
        let temp: Int = self.data[currentIndex]
        self.data[currentIndex] = self.data[currentIndex >> 1]
        self.data[currentIndex >> 1] = temp
        
        currentIndex >>= 1
      } else {
        break
      }
    }
  }
  
  mutating func pop() {
    self.data[1] = self.data[self.len - 1]
    self.data[self.len - 1] = 0
    self.len -= 1
    
    var currentIndex: Int = 1
    while true {
      var childIndex: Int = -1
      
      if self.len - 1 < (currentIndex << 1) {
        break
      } else if (currentIndex << 1) < self.len && (currentIndex << 1 + 1) >= self.len {	// 왼쪽 자식 노드 == 마지막 노드
        childIndex = currentIndex << 1
      } else {// 왼쪽 or 오른쪽 중 누구?
        childIndex = data[currentIndex << 1] < data[currentIndex << 1 + 1] ? (currentIndex << 1): (currentIndex << 1 + 1)
      }
      
      if self.data[currentIndex] > self.data[childIndex] {
        let temp = self.data[currentIndex]
        self.data[currentIndex] = self.data[childIndex]
        self.data[childIndex] = temp
        
        currentIndex = childIndex
      } else { break }
    }
  }
  
  func top() -> Int {
    return self.data[1]
  }
}
```

### 28.2.4. 우선순위 큐의 구현 요약

| -         | 배열 | 힙       |
| --------- | ---- | -------- |
| 값의 삽입 | O(1) | O(log n) |
| 값의 삭제 | O(n) | O(log n) |
| 값의 탐색 | O(n) | O(1)     |

```
1. 삽입 연산은 배열이 빠르긴 하지만, 삭제 연산에서 차이가 많이 발생하므로, 우선순위 큐 구현은 힙이 바람직함
2. 힙의 경우 완전이진트리이기 때문에, 배열을 이용하여 구현할 수 있음
```

### 29. 문제 해결의 절차

``` 
1. 문제를 정확히 이해한다.
2. 문제를 해결하는 알고리즘을 설계한다.
3. 설계한 알고리즘이 문제를 해결한다는 것을 수학적으로 증명한다.
4. 알고리즘이 제한 시간 내에 동작한다는 것을 보인다. (시간복잡도)
5. 알고리즘을 코드로 작성한다.
```

### 29.1. 문제 해결의 기본

```
1. 문제 해결을 위해 고려해야 하는 모든 경우를 파악해야 함.(탐색 공간)
2. 가장 첫 번째로 시도해보아야 하는 알고리즘은 완전탐색(Brute-Force Algorithm)
3. 완전탐색으로 시간 안에 문제 해결이 되지 않을 때는 알고리즘을 개선해 나가야 함.
4. 시간복잡도 계산을 위해 설계한 알고리즘에 대한 의사코드를 작성해야 함.
5. 완전탐색이 시간안에 동작하지 못할 때 개선할 수 있는 알고리즘: 이진 탐색, 분할 정복, 동적 계획법(DP), Greedy, Graph Algorithm(DFS, BFS, 최단 거리 등)
```

### 30. 분할 정복(Divide and Conquer)

```
1. 문제를 소문제로 분할
2. 각각의 소문제를 해결
3. 소문제의 해결 결과를 이용하여 전체 문제를 해결
4. 합병 정렬, 퀵 정렬이 대표적인 예
5. 분할 정복법은 소문제도 분할 정복법으로 해결하기 때문에 재귀호출과 관련이 깊음(재귀호출로 구현하는 경우 많음)
```

### 30.1. 분할 정복 예제 - 연속 부분 최대 합

```swift
// array의 start부터 end까지 연속 부분 최대 합을 반환하는 함수
func getSubMax(_ array: [Int], _ start: Int, _ end: Int) -> Int {
	if start >= end {
    return array[start]
  }
  
  let mid = (start + end) / 2
  let leftSubMax = getSubMax(array, start, mid)
  let rightSubMax = getSubMax(array, mid + 1, end)
  
  var leftSum = 0
  var leftMax = -1
  var rightSum = 0
  var rightMax = -1
  
  for i in start...mid.reversed() {
    leftSum += array[i]
    leftMax = leftMax < leftSum ? leftSum: leftMax
  }
  
  for i in mid+1...end {
    rightSum += array[i]
    rightMax = rightMax < rightSum ? rightSum: rightMax
  }
  
  middleSubMax = leftMax + rightMax
  
  if leftSubMax > rightSubMax && leftSubMax > middleSubMax {
    return leftSubMax
  } else if rightSubMax > leftSubMax && rightSubMax > middleSubMax {
    return rightSubMax
  } else {
    return middleSubMax
  }
}
```

### 31. 기초 동적 계획법(Basic Dynamic Programming)

```
1. 부분 문제를 해결한 결과를 이용하여 전체 문제를 해결
2. "나"를 해결함으로써 "나"를 해결하는 구조
3. 대표적인 예로 피보나치 수열(피보나치를 재귀로 부를 경우 시간복잡도는 O(2^n))
	- Each call to F(n) makes 2 additional calls, to F(n - 1) and F(n - 2). Those 2 calls will then generate 4 calls, which will generate 8, etc.
4. 분할 정복법과 차이는 큰 문제를 독립적으로 나누는 것과 달리, 작은 "나"를 해결한 결과를 계속해서 사용한다는 점
5. 따라서, 작은 소문제를 먼저 모두 기억해 놓는 것이 동적 계획법의 아이디어
6. 분할 정복법은 Top-Down Approach, 동적 계획법은 Bottom-Up Approach
```

``` swift
func solution() {
  guard let n = Int(readLine() ?? "0") else { return }
  var fibonacci = [Int](repeating: 0, count: n)
  
  fibonacci[0] = 0
  fibonacci[1] = 1
  for i in 2..<n {
    fibonacci[i] =   fibonacci[i - 1] + fibonacci[i - 2]
  }
  
  print(fibonacci)
}
```

### 31.1. 동적 계획법의 문제 풀이 순서

```
1. 부분 문제를 정의 -> 무슨 값을 구할지를 정의
2. 점화식을 구함 -> 그 값을 어떻게 구할지에 대한 식을 세움
4. 문제를 해결 -> 코드 작성
```

### 32. 중급 동적 계획법(Intermediate Dynamic Programming)

```
1. [1, 2, -4, 5, 3, -2, 9, 10] 다음과 같은 수열에서 연속부분 최대합을 구하는 문제에 대해
2. 완전탐색의 경우 O(n^2), 분할 정복법의 경우 O(n log n)의 시간복잡도로 해결 가능
3. 동적계획법을 활용하면 이 문제를 O(n)으로 해결 가능하므로 가장 효율적
4. 가장 빠르고, 구현도 쉽지만 구현까지 오는데 과정이 복잡하므로,
5. 키보드에서 손을 떼고, 종이와 펜으로 설계를 정확하게 하는데 초점 맞추기
```

### 32.1. 동적 계획법 정리

```
1. 부분 문제를 정의하는 것이 가장 어려움
2. 문제가 "재귀적으로 해결되는지"(나를 통해 나를 해결할 수 있는지)를 볼 줄 알아야 함
3. 무조건 많은 예제를 풀어보아야 함
```

### 33. 그래프(Graph)

``` 
1. Computer Science의 대표적인 자료구조 중 하나
2. 정점(Node, Vertex)과 간선(Edge)로 이루어진 자료구조
3. 차수(Degree): 각 정점에 연결되어 있는 간선의 개수
4. 사이클(Cycle): 자기 자신으로 다시 돌아올 수 있는 경로
5. 현실 세계의 많은 것들을 그래프로 나타낼 수 있기 때문에 그래프와 관련된 문제가 매우 많음
```

``` swift
// basic vertex
public class Vertex {
  var key: String?
  var neighbors: Array<Edge>
  
  init() {
    self.neighbors = Array<Edge>()
  }
}

// basic edge
public class Edge {
  var neighbor: Vertex
  var weight: Int
  
  init() {
    weight = 0
    self.neighbor = Vertex()
  }
}

// basic graph
public class Graph {
  private var canvas: Array<Vertex>
  public var isDirected: Bool
  
  init() {
    canvas = Array<Vertex>()
    isDirected = true	// 방향 그래프
  }
  
  // create new vertex
  func addVertex(key: String) -> Vertex {
    // set the key
    var childVertex: Vertex = Vertex()
    childVertex.key = key
    
    // add the vertex to the graph canvas
    canvas.append(childVertex)
    
    return childVertex
  }
}

// --- Making Connections ---
func addEdge(source: Vertex, neighbor: Vertex, weight: Int) {
  // create new edge
  var newEdge = Edge()

  // establish the default properties
  newEdge.neighbor = neighbor
  newEdge.weight = weight

  source.neighbors.append(newEdge)

  // check for undirected graph
  if (isDirected == false) {
    // create a new reversed edge
    var reverseEdge = Edge()

    // establish the reversed properties
    reverseEdge.neighbor = source
    reverseEdge.weight = weight
    neighbor.neighbors.append(reverseEdge)
  }
}
```

### 33.1. 그래프에 관한 중요한 수학적 지식

```
1. 간선의 개수는 대략적으로 정점의 제곱보다 작거나 같음(정확히는 nC2 보다 작거나 같음)
2. 즉, 간선의 개수 <= 정점의 개수 x (정점의 개수 - 1) / 2
3. 차수의 합 = 간선의 개수 x 2
```

### 33.2. 그래프의 구현 1 : 인접 행렬

```
1. 정점의 연결 관계를 2차원 배열에 0, 1로 표현
2. 그래프에서 할 수 있는 질문은 x, y가 연결돼 있는가?, x와 연결된 정점이 모두 무엇인가? 정도로 말할 수 있음
3. 인접 행렬로 그래프를 구현했을 때 장점: 두 정점 연결 여부를 O(1)에 알 수 있음
4. 인접 행렬로 그래프를 구현했을 때 단점: 인접한 정점을 모두 찾는데 O(n)이 걸리며, n^2의 공간이 필요함
```

```swift
func solution(_ n: Int, _ verticies: [[Int]] ) {
  var Graph: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
  
  for i in 0..<n {
    let v = verticies[i]
    Graph[v[0]][v[1]] = 1
    Graph[v[1]][v[0]] = 1
  }
}
```

### 33.3. 그래프의 구현 2 : 인접 리스트

```
1. 각각의 정점에 대하여 인접한 정점 번호를 저장함
2. 장점: 인접한 정점을 모두 찾는 것이 O(degree), 인접 행렬보다 빠르며 필요한 만큼만 공간을 활용함
3. 단점: x와 y 두 정점 연결 여부를 찾는 것이 O(degree)로 인접 행렬의 O(1)에 비해 느림
```

```swift
func solution(_ n: Int, _ verticies: [[Int]] ) {
  var Graph: [Graph] = Array(repeating: Graph(), count: n)
  
  for i in 0..<n {
    let v = verticies[i]
    Graph[v[0]].edges.append(v[1])
    Graph[v[1]].edges.append(v[0])
  }
}
```





















