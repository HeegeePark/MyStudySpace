# Optional 이란 무엇인지 설명하시오.

### optional

- 값이 있을 수도 없을 수도 있는
- 기본적으로 변수 선언할 때 non-optional이라 어떤 값을 줘야함. int라 했는데 nil 주면 에러남

```swift
var v1: Int? = 30
var v2: Int = v1  // 에러 (Int랑 Int?는 다른 타입)
var v3: Int? = v1!

v1 = nil
var v4: Int = v1!  // 에러 (nil에 접근하여 런타임 에러)
```

- ?가 붙으면 optional type, 값이 있거나 nil 이거나

- !가 붙으면 강제 unwrapping. 값이 nil이 아닌 게 보장 돼있을 때만 써야 함

- optional 변수 값 가져오는 법

  1. !(force unwrapping)

  2. optional binding

     - if let/var 구문으로 nil check 먼저

     ```swift
     func printName() {
     	var value: String?
     	value = "Lena"
     	print(value)  // Optional("Lena")
     	if let name = value {
     		print(name)  // "Lena"
     	}
     	// if문 안에서만 name 변수 사용 가능
     }
     ```

     - guard let으로도 가능
       - 조건 만족 안하면 else 구문 실행

     ```swift
     func printName() {
     	var value: String?
     	value = "Lena"
     	print(value)  // Optional("Lena")
     	guard let name = value else {
     			return // 상위코드 블록 종료할 것 (return, break, continue, throw,,,)
     	}
     	print(name)  // "Lena"
     	// 메소드 내애서 지역 상수처럼 name 사용 가능
     }
     ```

  3. optional chaining

     - 하위 프로퍼티에 옵셔널이 있는지 연속적으로 확인하면서, 하나라도  nil이면 nil 반환

     ```swift
     class Person {
     	var residence: Residence? // Residence 클래스 상속받는 optional 변수
     }
     class Residence {
     	var numberOfRooms = 1
     }
     
     let zedd = Person()  // 초기화 따로 안했으니까 현재 residence 값은 nil
     
     // 프로퍼티 이어지는 '체이닝'. 여기서 roomCount는 Int? 타입
     if let roomCount = zedd.residence?.numberOfRooms {
     	print("zedd's residence has \\(roomCount) room(s).")
     } else {
     	print("residence가 nil이라서 이게 출력됨.")
     }
     ```