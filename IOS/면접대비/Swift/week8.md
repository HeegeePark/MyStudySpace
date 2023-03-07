# defer가 호출되는 순서는 어떻게 되고, defer가 호출되지 않는 경우를 설명하시오.

- defer구문으로 작성하게 되면 코드 블럭을 나가기 전에 꼭 실행된다.
- 오류가 발생해도, 정상적으로 코드가 작동해도 빠져나가기 전에 실행된다.

### defer가 여러 개가 한 코드 블럭에서 호출될 시

- defer는 스택으로 동작하기 때문에 역순으로 호출된다.

``` swift
func example() {
    defer { print("1") }
    defer { print("2") }
    defer { print("3") }
    defer { print("4") }
    defer { print("5") }
    defer { print("6") } 
}

/*
Print:

6
5
4
3
2
1
*/
```

### defer가 호출되지 않는 경우

- error를 던지는 뒤에 선언한 구문은 실행되지 않는다.
  - stack에 할당되지 못했기 때문.



참조

https://dongminyoon.tistory.com/46

# property wrapper에 대해서 설명하시오.

- 특정 값을 한 번 감싸서 get/set 로직을 어느 정도 분리해서 반복을 줄여줄 수 있는 방법을 제공하는 속성이다.
- 코드의 재사용성을 높여 코드가 짧아지는 효과가 있음.



참조

https://zeddios.tistory.com/1221

# Generic에 대해 설명하시오.

- 제네릭이란 타입에 의존하지 않는 범용 코드를 작성할 때 사용한다

- 제네릭을 사용하면 중복을 피하고, 코드를 유연하게 작성할 수 있다

```swift
func swapTwoValues<T>(_ a: inout T, _ b: inout T) {
   let tempA = a
   a = b
   b = tempA
}
```

- 타입 constraint 걸 수 있음
  - 특정 프로토콜을 지켜야만 generic 함수 쓸수 있게 하는 것
  - dictionary는 hashable 프로토콜 지켜야만 key로 들어올 수 있게 되어 있음.

# some 키워드에 대해 설명하시오.

- some 키워드는 computed property인 body안에 불투명한 타입이 있음을 나타낸다.
- 함수 내부의 코드가 수정되어도 함수 밖 내용은 수정할 필요가 없어진다.
- 스유에서 some을 안 쓴다면 매번 함수 리턴값을 VStack, HStack, Button, Text 등등 구체적인 뷰값을 명시해줘야해서 아주 귀찮아졌을 것.

불투명한 타입?

```swift
protocol Shape {
    func describe() -> String
}

struct Square: Shape {
    func describe() -> String {
        return "I'm a square. My four sides have the same lengths."
    }
}

struct Circle: Shape {
    func describe() -> String {
        return "I'm a circle. I look like a perfectly round apple pie."
    }
}
```

위와 같은 Shape란 프로토콜과 Shape를 따르는 여러 도형이 있다고 했을 때

```swift
func makeShape() -> Shape {
  return Circle()
}
```

- 정확히 무슨 도형을 리턴하는지 모르게 되는 경우
- 즉, makeShape()는 불투명한 타입
- Swift는 불투명한 타입을 리턴하는 것을 허용하지 않는다.
  - ***Protocol 'Shape' can only be used as a generic constraint because it has Self or associated type requirements*** 이라는 에러 발생

해결 방법

- 타입을 미리 지정해서 함수의 내부를 변화시키는 제네릭 타입과는 정 반대로, 함수 내부의 코드에 따라 구체적인 리턴 타입이 달라진다.

``` swift
func makeShape() -> some Shape {
  return Circle()
}
```



# Result타입에 대해 설명하시오.

- `Result` 타입은 `Generic Enumeration`로 선언되어 있고, 경우에 따른 연관값을 포함하여, 성공과 실패를 나타내는 값

``` swift
@frozen enum Result<Success, Failure> where Failure : Error
```

Result Type을 사용하고자 한다면, 성공했을 경우와, 실패했을 경우의 값을 넣어줘야 함.

```swift
Result<Bool, 미리 선언한 Error 열거형> 
```

# Codable에 대하여 설명하시오.

- Codable은 Decodable과 Encodable을 합친 프로토콜
- 자기 자신으로 변환되거나 외부 표현으로 변환될 수 있는 타입
- 구조체와 클래스 모두 채택 가능 (NSCoding은 클래스만 가능)
  - But, Codable은 다형성으로 동작되는 경우에는 문제가 발생하므로 이때는 NSCoding 이용할 것.

### Decodable

- 외부 표현으로부터 자기 자신으로 디코딩 될 수 있는 타입
- `CodingKeys` 열거형은 프로퍼티의 이름과 json파일의 속성의 이름이 다를 경우 선언

### Encodable

- 자기 자신을 인코딩하는 타입
- Decodable의 역순, 마찬가지로 `CodingKeys` 사용 가능



# Closure에 대하여 설명하시오.

### closure

- 사용자의 **코드 안에서 전달되어 사용할 수 있는 로직**을 가진 중괄호 `{}`로 구분된 **코드 블럭**
- 일급 객체의 역할 가능
  - **일급 객체는 전달 인자로 보낼 수 있고, 변수∙상수 등으로 저장하거나 전달할 수 있으며, 함수의 반환 값이 될 수도 있다.**
- 함수는 클로저의 한 형태, 일명 **이름이 있는 클로저**

# Closure와 함수와의 관계에 대해 설명하시오.

- 클로저는 레퍼런스 타입이기 때문에, 한 클로저가 두 let/var 에 할당하면 같은 클로저를 참조하는 거라서 값 누적됨.(??)



