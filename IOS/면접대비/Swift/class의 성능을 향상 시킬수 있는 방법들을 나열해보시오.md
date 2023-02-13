# class의 성능을 향상 시킬수 있는 방법들을 나열해보시오.

### 좋은 성능에 영향을 주는 요인 3가지

- **Allocation**: 인스턴스를 생성하면 Stack과 Heap 중 어느 곳에 **할당** 되는 지
- **Reference Counting**: 인스턴스를 통해 **레퍼런스 카운트**가 몇개가 발생하는지
- **Method Dispatch**: 인스턴스에서 메소드를 호출했을 때, **메소드 디스패치**가 정적인지 동적인지

### 1. Heap allocation 피하기

딕셔너리에 String 타입의 키를 사용하는 것은 성능에 좋지 않다. 

- String 타입은 값타입이지만, heap에 Character 타입으로 문자들을 간접적으로 저장하기 때문,  사용하게 되면 heap allocation이 발생한다.

**해결방법**: struct을 만들어서 key로 사용하는 것

- Hashable이라는 프로토콜을 채택해야 하는데, 커스텀 객체를 collection에 사용하기 위해 필요하다.



### 2. Reference Counting Overhead 최소한으로 줄이기

Reference Counting이 발생하는 Struct

- String 타입은 Character들을 힙에 저장하며, UIFont 또한 클래스로 만들어진 객체이므로 래퍼런스 카운트가 필요하다.
- 구조체가 레퍼런스를 가지게 되면 reference counting으로 오버헤드(overhead)를 처리하는 비용이 들게 된다.

``` swift
struct label {
    var text: String
    var font: UIFont
    func draw() {}
}
```

**해결방법**: uuid를 String 타입이 아닌 UUID로 변경하여 래퍼런스 줄인다. UUID는 struct 타입이다. String 대신 enum을 사용하여 해결할 수도 있다.



### 3. Method Dispatch

**Static Method Dispatch**

컴파일 시점에 컴파일러가 메소드의 실제 코드 위치를 파악할 수 있어, 런타임에 찾는 과정 없이 바로 코드를 실행한다. 구현된 코드들이 어디서 실행되는지 알 수 있기에 메소드 인라이닝과 같은 코드 최적화를 시행한다. 메소드 인라이닝(Method Inlining)이란 메소드를 호출할 때 해당 메소드로 이동하지 않고 메소드의 결과값을 바로 반환하여 성능을 향상시킨다.

**Dynamic Method Dispatch**

컴파일 시점에 어떤 메소드를 호출하는 지 알 수 없어, 런타임에 table을 참조하여 해당 메소드에 대한 정보를 가져와서 코드를 실행한다. Static Method Dispatch보다 많은 비용을 필요로 하지 않고, 래퍼런스 카운팅, 힙 할당과 같은 쓰레드 동기 오버헤드가 없다. 하지만 컴파일러는 Static은 최적화 작업이 가능하지만, Dynamic Dispatch에는 추론할 수 없다.

**Dynamic Dispatch가 필요한 이유?**

이유는 다형성 때문이다. 다형성(Polymorphism)이란 하나의 객체가 여러 타입을 가질 수 있는 것을 의미한다.

**해결방법**: Final Class

- 서브 클래스를 만들지 않는다면, final을 클래스 앞에 선언한다. 그러면 컴파일러가 static하게 dispatch할 수 있다. 또한 서브클래스를 만들지 않는다라는 의도도 보여줄 수 있다.

![image](https://user-images.githubusercontent.com/47033052/218379350-84e657fb-39db-4786-a1c6-e42d95698999.png)

![image](https://user-images.githubusercontent.com/47033052/218379489-29fbcccf-70cc-4019-a8c4-ae57e328c7de.png)



참조

https://corykim0829.github.io/swift/Understanding-Swift-Performance/#