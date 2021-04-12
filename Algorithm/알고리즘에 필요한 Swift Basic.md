# 알고리즘에 필요한 Swift Basic 총정리

## 키보드 입력받는 법

``` swift
let value = readLine()
```

- `readLine()`의 리턴값은 Optional String이므로 알아서 가공...

## 키보드 입력받은 값 공백으로 구분하기

- ex. 1 2 3 4 

### case 1: `split()`으로 쪼개기

``` swift
let nums = readLine()!.split(seperator: " ") 	// ["1", "2", "3", "4"]
```

### case 2: `components()`로 쪼개기

``` swift
let nums = readLine()!.components(separatedBy: " ")		// ["1", "2", "3", "4"]
```

### 둘의 차이점

1. Import Foundation
   - components의 경우 Foundation에 들어있는 instance method여서 반드시 import Foundation을 해줘야 함.
     - 대신 용량이 늘어남
   - split의 경우 Swift 기본 instance method여서 Foundation없이도 사용 가능
2. 리턴값이 다르다
   - components로 쪼개면 리턴값이 [String]
   - split으로 쪼개면 리턴값이 [String.SubSequence]
     - 바로 String으로 쓸 수가 없음
     - 그래도 map하면 되니까 백준 풀 때는 import 없는 split 선호

## 배열(Array) 다루기

- 알고리즘 풀 때 배열 다룰 일 매우 매니매니
- 특히 map, filter 매우 유용유용

### 1. 빈 배열 만들기

``` swift
var empty : [Int] = []
var empty = [Int]()
var empty : Array<Int> = []
```

### 2. 임의의 data 넣어서 만들기

``` swift
var array = Array(1...5) 	// [1,2,3,4,5]
```

### 3. 크기가 정해진 배열

``` swift
var arr = Array(repeating: 0, count: 3)		// [0,0,0]
```

### 4. 2차원 배열(Matrix) 만들기

``` swift
let matrix = [[Int]]()
let arr: [[Int]] = Array(repeating: Array(repeating:1, count: 5), count: 3)		// 안쪽 count가 row, 바깥 count가 col

// 다룰 때는
arr[i][j]
```

### 5. 배열 거꾸로 출력

``` swift
array.reversed()
```

### 6. 배열 정렬하기

``` swift
array.sorted() 	// default는 오름차순
array.sorted(by: >)		// 내림차순
```

### 7. 배열 다룰 때 가장 중요한 map, filter, reduce

- map

``` swift
var string = ["1","2","3","4"]
string.map { Int($0) } 		// [1,2,3,4] 각 원소를 Int로 맵핑
```

- filter

``` swift
var array = [1,2,3,4]
array.filter { $0 % 2 == 0 }	// [2,4] 조건에 맞는 수만 뽑아냄
```

- reduce

``` swift
var array = [1,2,3,4]
array.reduce(0, +) // 숫자 합이 나타남. 문자열 합치기도 가능
```



## String, Substring, Index 다루기

``` swift
let secondIndex = string.index(after: string.startIndex)
let second = string[secondIndex]

let endIndex = string.index(before: str.endIndex)

// n번째 문자 index 구하는 법
let index = string.index(string.startIndex, offsetBy: n-1)

// subString 구하는 법
let subString = string[start...end]

// 문자 검색해서 index 찾기
	"abc123".index(firstOf: "c")

// 특정 character replace
string.replacingOccurences(of: " ", with: "+")
```



## print할 때 따옴표('), 쌍따옴표(") 출력하기

``` swift
print("이렇게 \' 써준다.")	// 결과 : 이렇게 ' 써준다.
```