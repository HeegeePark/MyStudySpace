# 03_컬렉션 타입(Array, Dictionary, Set)

- `Array` : 순서가 있는 리스트 컬렉션
- `Dictionary` : <key, value> 쌍으로 이루어진 컬렉션
- `Set` : 순서가 없고, 멤버가 유일한 컬렉션



## 1. Array

- 멤버가 순서(인덱스)를 가진 리스트 형태의 컬렉션 타입
- 여러가지 리터럴 문법 활용 가능

```swift
// 1. Array 선언 및 생성
var integers: Array<Int> = Array<Int>()

// 위와 동일한 표현
var integers: Array<Int> = [Int]()
var integers: Array<Int> = []
var integers: [Int] = Array<Int>()
var integers: [Int] = [Int]()
var integers: [Int] = []
var integers = [Int]()

// 2. Array 활용
integers.append(1)		// 멤버 추가
integers.append(100)

// Int 타입이 아니므로 추가 x
// integers.append(101.1)

print(integers)		// [1, 100]

// 멤버 포함 여부 확인
print(integers.contains(100))		// true
print(integers.contains(99))		// false

// 멤버 교체
integers[0] = 99

// 멤버 삭제
integers.remove(at:0)		// 특정 인덱스
integers.removeLast()		// 마지막 원소
integers.removeAll()		// 모든 원소

// 멤버 수 확인
print(integers.count)

// 인덱스를 벗어나 접근하려면 익셉션 런타임 오류 발생
// integers[0] 		// removeAll()로 존재하는 멤버 없어서 인덱스 벗어남.

// 3. 불변 Array: let을 사용한 Array 선언
let immutableArray = [1,2,3]

// 수정이 불가능한 Array이므로 멤버를 추가하거나 삭제할 수 없음.
// immutableArray.append(4)
// immutableArray.removeAll()
```



## 2. Dictionary

- <key, value> 쌍으로 이루어진 컬렉션
- 여러가지 리터럴 문법 활용 가능

```swift
// 1. Ditionary 선언 및 생성
var anyDictionary: Dictionary<String,Any> = [String: Any]()

// 위와 동일한 표현
var anyDictionary: Dictionary<String,Any> = Dictionary<String,Any>()
var anyDictionary: Dictionary<String,Any> = [:]
var anyDictionary: [String: Any] = Dictionary<String,Any>()
var anyDictionary: [String: Any] = [String: Any]()
var anyDictionary: [String: Any] = [:]
var anyDictionary = [String: Any]()

// 2. Dictionary 활용
// 키에 해당하는 값 할당
anyDictionary["SomeKey"] = "value"
anyDictionary["anotherKey"] = 100

print(anyDictionary)	// ["SomeKey": "value", "anotherKey": 100]

// 키에 해당하는 값 변경
anyDictionary["SomeKey"] = "dictionary"
print(anyDictionary)	// ["SomeKey": "dictionary", "anotherKey": 100]

// 키에 해당하는 값 제거
anyDictionary.removeValue(forKey: "anotherKey")
anyDictionary["someKey"] = nil
print(anyDictionary)

// 3. 불변 Dictionary: let을 사용한 Dictionary 선언
let emptyDictionary: [String: String] = [:]
let intializedDictionary: [String: String] = ["name": "heegee", "gender": "female"]

// 불변 Dictionary이므로 값 변경 불가
// emptyDictionary["key"] = "value"

// "name"이라는 키에 해당하는 값이 없을 수도 있으므로 String 타입의 값이 나온다는 보장이 없다.
// -> 컴파일 오류 발생
// 키에 해당하는 값을 변수 또는 상수에 할당하고자 할 때는 옵셔널과 타입 캐스팅으로 조정
// let someValue: String = intializedDictionary["name"]
```



## 3. Set

- 순서가 없고, 멤버가 유일한 컬렉션
- `Array`, `Dictionary`와 다르게 축약형 존재 x

```swift
// 1. Set 생성 및 확인
var integerSet: Set<Int> = Set<Int>()

// insert: 새로운 멤버 입력
// 동일한 값은 여러번 insert해도 한번만 저장(Set은 중복된 값을 가지지 않음.)
integerSet.insert(1)
integerSet.insert(99)
integerSet.insert(99)
integerSet.insert(99)
integerSet.insert(100)

print(integerSet)		// {100, 99, 1}

// contains: 멤버 포함 여부 확인
print(integerSet.contains(1))	// true
print(integerSet.contains(2))	// false

// remove: 멤버 삭제
integerSet.remove(99)	// {100, 1}
integerSet.removeFirst()	// {1}

// count: 멤버 개수
integerSet.count	// 1

2. Set의 활용
// 멤버의 유일성이 보장되기 때문에 집합 연산에 활용하면 유용함.
let setA: Set<Int> = {1,2,3,4,5}
let setB: Set<Int> = {3,4,5,6,7}

// 합집합 union
let union: Set<Int> = setA.union(setB)
print(union) 	// {2,4,5,6,7,3,1}

// 오름차순 정렬
// sorted 함수로 오름차순된 Array로 리턴
let sortedUnion: [Int] = union.sorted()
print(sortedUnion) 	// [1,2,3,4,5,6,7]

// 교집합
let intersection: Set<Int> = setA.intersection(setB)
print(intersection)	// {5,3,4}

// 차집합
let substracting: Set<Int> = setA.subStracting(setB)
print(substracting)	// {2,1}
```