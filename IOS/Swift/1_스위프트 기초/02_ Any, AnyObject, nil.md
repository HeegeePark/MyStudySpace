# 02_Any, AnyObject, nil

- `Any`: 스위프트의 모든 타입을 지칭하는 키워드
- `AnyObject`: 모든 클래스 타입을 지칭하는 프로토콜
- `nil`: '없음'을 의미 (다른 언어에서의 null과 유사한 표현)

## 1. Any

- `Any`: 스위프트의 모든 타입을 지칭하는 키워드

```swift
var someAny: Any = 100
someAny = "어떤 타입도 수용 가능"
someAny = 123.12

// Any타입에 Double자료를 넣었더라도 Any는 Double 타입이 아니기 때문에 할당할 수 없음.
// 명시적으로 타입을 변환해 주어야 함. 
let someDouble: Double = someAny	// 컴파일 오류 발생
```



## 2. AnyObject

- 모든 클래스 타입을 지칭하는 프로토콜

```swift
class SomeClass{}
var someAnyObject: AnyObject = someClasss()

// AnyObject는 클래스의 인스턴스만 수용 가능하기 때문에 클래스의 인스턴스가 아니면 할당할 수 없음.
someAnyObject = 123.12	// 컴파일 오류 발생
```



## 3. nil

- '없음'을 의미하는 키워드

```swift
// someAny는 Any 타입이고, someAnyObject는 AnyObject 타입이기 때문에 nil을 할당할 수 없음.
var someAny: Any = 100
var someAnyObject: AnyObject = SomeClass()

someAny = nil		// 컴파일 오류 발생
someAnyObject = nil		// 컴파일 오류 발생
```

