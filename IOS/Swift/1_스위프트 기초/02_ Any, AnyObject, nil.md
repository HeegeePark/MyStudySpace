# 02_Any, AnyObject, nil

- `Any`: 스위프트의 모든 타입을 지칭하는 키워드
- `AnyObject`: 모든 클래스 타입을 지칭하는 프로토콜
- `nil`: '없음'을 의미 (다른 언어에서의 null같은 존재)

## 1. Any

- `Any`: 스위프트의 모든 타입을 지칭하는 키워드

```swift
var someAny: Any = 100
someAny = "어떤 타입도 수용 가능"
someAny = 123.12

// Any타입에 Double자료를 넣었더라도 Any는 Double 타입이 아니기 때문에 할당할 수 없음.
// 명시적으로 타입을 변환해 주어야 함. (타입 변환은 차후에)
let someDouble: Double = someAny
```

