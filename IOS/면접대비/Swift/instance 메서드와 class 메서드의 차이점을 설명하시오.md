# instance 메서드와 class 메서드의 차이점을 설명하시오.

### Instance Method

특정 타입의 인스턴스(클래스, 구조체, 열거형...) 에 속한 함수를 말한다. 그렇기 때문에 보통 해당 인스턴스와 관련한 동작을 수행한다.



### Class Method

Class 메서드는 인스턴스를 생성하지 않고 클래스 자체에 메서드 접근이 가능하다.

### 기존 Static Method와의 차이점

- 원래 static은 `override`가 불가능하지만, Swift에서 static을 `override`가 가능하게 만드려고 Class method를 만든 것.
- 즉, swift에서는 static method == static method
- 이런 이유로 상속이 불가능한 구조체와 열거형엔 사용할 수 없다.