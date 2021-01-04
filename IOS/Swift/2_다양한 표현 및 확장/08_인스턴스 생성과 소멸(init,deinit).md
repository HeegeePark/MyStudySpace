# 08_인스턴스 생성과 소멸(init,deinit)

## 1. 프로퍼티 초기값

- 스위프트의 모든 <u>인스턴스는 초기화</u>와 동시에 **모든 프로퍼티**에 유효한 값이 할당되어 있어야 함.
- 프로퍼티에 미리 기본값을 할당해두면 인스턴스가 생성됨과 동시에 초기값을 지니게 됨.

``` swift
class PersonA {
  // 모든 저장 프로퍼티에 기본값 할당
  var name: String = "unknown"
  var age: Int = 0
  var nickName: String = "nick"
}

// 인스턴스 생성
let jason: PersonA = PersonA()

// 기본값이 인스턴스가 지녀야 할 값과 맞지 않다면
// 생성된 인스턴스의 프로퍼티에 각각 값 할당
jason.name = "jason"
jason.age = 30
jason.nickName = "j"
```



## 2_1. 이니셜라이저(initializer)

- 프로퍼티의 초기값을 지정하기 어려운 경우에는 이니셜라이저 `init`을 통해 인스턴스가 가져야 할 <u>초기값을 전달</u>할 수 있음.

``` swift
class PersonB {
  var name: String
  var age: Int
  var nickName: String
  
  // 이니셜라이저 
  init(name: String, age: Int, nickName: String) {
    self.name = name
    self.age = age
    self.nickName = nickName
  }
}

let heegee: PersonB = PersonB(name: "heegee", age: 24, nickName: "희지")
```

- 프로퍼티의 초기값이 꼭 필요 없을 때
  - 옵셔널을 사용!
  - `class` 내부의 `init`을 사용할 때는 `convenience` 키워드 사용

``` swift
class PersonC {
  var name: String
  var age: Int
  var nickName: String?		// 프로퍼티 값이 꼭 필요하지 않은 경우
  
//  // 이니셜라이저 
//  init(name: String, age: Int, nickName: String) {
//    self.name = name
//    self.age = age
//   self.nickName = nickName
//  }
  
  // 위와 동일한 기능 수행
  // 자신의 init을 호출할 때는 편의 이니셜라이저 사용할 것
  convenience init(name: String, age: Int, nickName: String) {
    init(name: name, age: age)
    self.nickName = nickName
  }
  
  init(name: String, age: Int) {
    self.name = name
    self.age = age
  }
}

let heegee: PersonC = PersonC(name: "heegee", age: 24)
let taesu: PersonC = PersonC(name: "taesu", age: 27, nickName: "태수")
```

- 암시적 추출 옵셔널은 인스턴스 사용에 꼭 필요하지만 초기값을 할당하지 않고자 할 때 사용

``` swift
class Puppy {
  var name: String
  var owner: PersonC!		// init에서 전달은 안하지만, 프로퍼티 값이 꼭 필요한 경우 (nil X)
  
  init(name: String) {
    self.name = name
  }
  
  func goOut() {
    print("\(name)가 주인 \(owner.name)와 산책을 합니다")
  }
}

let happy: Puppy = Puppy(name: "taesu")

// 강아지는 주인없이 산책하면 안돼요!
// happy.goOut()	// 주인이 없는 상태라 오류 발생

// 암시적 추출 때문에 주인을 할당해 주어야 산책 가능 
happy.owner = heegee
happy.goOut()		// taesu가 주인 heegee와 산책을 합니다.
```



## 2_2. 실패가능한 이니셜라이저

- 이니셜라이저 매개변수로 전달되는 초기값이 잘못된 경우 인스턴스 생성에 실패할 수 있음.
- 인스턴스 생성에 실패하면 `nil` 반환
- 실패가능한 이니셜라이저의 반환타입은 옵셔널 타입
- `init?`을 사용.

``` swift
class PersonD {
  var name: String
  var age: Int
  var nickName: String?
  
  // 원하는 값의 범위가 아닐 시 nil 반환
  init?(name: String, age: Int) {
    if(0...120).contains(age) == false {
      return nil
    }
    
    if name.count == 0 {
      return nil
    }
    
    self.name = name
    self.age = age
  }
}

// let john: PersonD = PersonD(name: "john", age: 23)
let john: PersonD? = PersonD(name: "John", age: 24)
let joker: PersonD? = PersonD(name: "joker", age: 123)
let batman: PersonD? = PersonD(name: "", age: 30)

print(joker)	// nil
print(batman)	// nil
```



## 3. 디이니셜라이저(deinitializer)

- **`deinit`**은 클래스의 인스턴스가 메모리에서 해제되는 시점에 호출됨.
- 인스턴스가 해제되는 시점에 해야할 일을 구현할 수 있음.
- **`deinit`**은 매개변수를 지닐 수 없음
- 자동으로 호출됨, 직접 호출 불가
- 디이니셜라이저는 **클래스 타입에만 구현 가능**
- 인스턴스가 메모리에서 해제되는 시점은 ARC(Auto Reference Counting)의 규칙에 따라 결정됨.

``` swift
class PersonE {
  var name: String
  var pet: Puppy?
  var child: PersonC
  
  init(name: String, child: PersonC) {
    self.name = name
    self.child = child
  }
  
  // 인스턴스가 메모리에서 해제되는 시점에 자동 호출
  deinit {
    if let petName = pet?.name {
      print("\(name)가 \(child.name)에게 \(petName)를 인도합니다")
      self.pet?.owner = child
    }
  }
}

var donald: PersonE? = PersonE(name: "donald", child: jenny)
donald?.pet = happy
donald = nil	// donald 인스턴스가 더이상 필요없으므로 메모리에서 해제
// donald가 jenny에게 happy를 인도합니다
```

