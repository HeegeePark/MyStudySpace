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
let nums = readLine()!.split(separator: " ") 	// ["1", "2", "3", "4"]
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



## 줄바꿈 없이 print()

``` swift
print(data, terminatior: "")
```



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



## 비트 연산

1. NOT : ~value //00001111 -> 11110000으로 0과 1를 바꿔준다
2. AND : first & second // 두개 자릿수가 둘다 1일 때 1 리턴
3. OR : first | second // 둘 중 하나라도 자릿수가 1이면 1 리턴
4. XOR : first ^ second // 두 자릿수가 다르면 1, 같으면 0 리턴
5. Left Shift : value << n // n만큼 왼쪽으로 이동하고 빈자리는 0으로
6. Right Shift : value >> n // n만큼 오른쪽으로 이동하고 빈자리는 0으로 
7. 3항 연산자 : 조건문 ? 참 : 거짓 // a < b ? a : b 중첩도 가능



## 앱 종료

``` swift
exit(0)
```



##  무한루프

``` swift
while true {
  // 코드
}
```



## do while

``` swift
repeat {
  // 코드
} while
```



## Swift에는 `++` 연산자가 없음!!! (마이너스 또한)

## String 한 글자와 Character 형 구분할 때

``` swift
Character("a")	// 타입 명시
```



## 거듭제곱

``` swift
pow(x, 2) 	// x^2, x는 Decimal 타입
```



## Decimal -> Int

``` swift
(decimal as NSDecimalNumber).intValue
```



## 부동소수점 다루기

NumberFormatter 이용

- 자세한 방법 : https://twih1203.medium.com/swift5-numberformatter%EB%A1%9C-%EC%86%8C%EC%88%98%EC%A0%90-%EC%95%84%EB%9E%98-%EC%9E%90%EB%A6%BF%EC%88%98-%EB%B0%98%EC%98%AC%EB%A6%BC-%EC%97%86%EC%9D%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0-ee33219e3cdd

``` swift
let formatter = NumberFormatter()
formatter.roundingMode = .down	// 내림
formatter.minFractionDigits = 2 // 2자릿수까지만 표현
formatter.maxFractionDigits = 2
let num = formatter.string(from: NSNumber(value: 2.3243254))		// 2.32 (Optional String)
```



## 타입 범위

``` swift
Int, Int64 = 2의 8승 - 1 (9223372036854775807) // 19자리
Int32      = 2의 6승 -1  (2147483647)          // 10자리
Float      = 소수점 6자리까지 표현 가능
Double     = 소수점 15자리까지 표현 가능
```



## 진수 표현

``` swift
// 10진수 -> N진법
String(integer, radix: n)

// N진법 -> 10진수
Int("11100110", radix: n)!
```



## 문자를 ASCII 코드로 변환

``` swift
Character("a").asciiValue!
```



## String에 식이 들어있을 때 그대로 계산하기

``` swift
let mathExpression = NSExpression(format: "3+4+2-1*6")
let mathValue = mathExpression.expressionValue(with: nil, context: nil) as! Int 	// result : 3
```



## 절대값 변환

``` swift
abs(-29)	// 29
```



## for문에서 원하는 수치만큼 증가 | 감소하는 반복문 필요할 때

``` swift
stride(from: 1, to: 5, by: 2)		// open range..5 불포함 1,3 까지만
stride(from: 1, through: 5, by: 2)		// closed range..5 포함 1,3 ,5 까지

ex)
for even in stride(from: 2, through: 100, by: 2)
```



## Dictionary 사용하기

### 1. 생성

``` swift
var dic: [Int: String] = [:]
var dic = [Int: String]()
var dic = [1: "a", 2: "b", 3: "c"]
```

### 2. 값 수정

``` swift
dic.updateValue("c", forKey:3)
dic[3] = "d"
```

### 3. 값 추가

``` swift
dic[4] = "5"
dic.update("5", forKey: 4)	// 4라는 키가 있을 경우 수정이 됨
```

### 4. 접근

``` swift
dic[4]! // Unwrapping 해줄 것
```

### 5.  for문 돌기

``` swift
for (key, value) in dic {
  print(key)		// 1,2,3
  print(value)		// a,b,c
}
// 단 순서는 뒤죽박죽임 !!! (Dictionary는 순서가 없음)
```

### 6. 값 삭제

``` swift
dic.removeValue(forKey:4) // 특정 키값 삭제
dic.removeAll()		// 전체 삭제
```

### 7. Key를 바꿀 경우, 지우고 다시 넣어줘야 함

### 8. Dictionary Key로 sort

``` swift
let sort = dic.sorted(by: { $0.key < $1.key })	// value 기준 sort 시 -> $0.value
```
