# Struct 가 무엇이고 어떻게 사용하는지 설명하시오.

- 스위프트의 구조체
- 구조체의 특징은 자동으로 생겨난 멤버 초기자(memberwise initializer)를 가지고 있어 이것을 사용하여 구조체 인스턴스의 멤버 속성을 초기화할 수 있다.
  - 클래스 인스턴스는 없는 기능
- 구조체는 코드의 유연성에 도움이 된다. 객체를 분리해 하나의 타입으로 개발하고싶을 때 사용한다.

### 구조체 사용법

- 구조체 정의: `struct` 키워드 사용

  ```swift
  struct 이름 {
    /*구현부*/
  }
  ```

- 구조체 프로퍼티 및 메서드 구현

  ```swift
  struct Sample {
    // 가변 프로퍼티(값 변경 가능)
    var mutableProperty: Int = 100
    
    // 불변 프로퍼티(값 변경 불가능)
    let immutableProperty: Int = 100
    
    // 타입 프로퍼티(static 키워드 사용: 타입 자체가 사용하는 프로퍼티)
    static var typeProperty: Int = 100
    
    // 인스턴스 메서드(인스턴스가 사용하는 메서드)
    func instanceMethod() {
      print("instance Method")
    }
    
    // 타입 메서드(static 키워드 사용: 타입 자체가 사용하는 프로퍼티)
    static func typeMethod() {
      print("type Method")
    }
  }
  ```

- 구조체 사용

  ```swift
  // 가변 인스턴스 생성
  var mutable: Sample = Sample()
  
  mutable.mutableProperty = 200
  
  // 불변 프로퍼티는 인스턴스 생성 후 수정 X
  // 컴파일 오류 발생
  // mutable.immutableProperty = 200
  
  // 불변 인스턴스
  let immutable: Sample = Sample()
  
  // 불변 인스턴스는 가변 프로퍼티도
  // 인스턴스 생성 후 수정 X
  // immutable.mutableProperty = 200
  // immutable.immutableProperty = 200
  
  // 타입 프로퍼티 및 메서드
  Sample.typeProperty = 300
  Sample.typeMethod()	// type Method
  
  // 인스턴스에서는 타입 프로퍼티나 타입 메서드를 사용 X
  // 컴파일 오류 발생
  // mutable.typeProperty = 400
  // mutable.typeMethod()
  ```