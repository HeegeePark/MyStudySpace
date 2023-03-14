# Strong 과 Weak 참조 방식에 대해 설명하시오.

### Strong (강한 참조)

```swift
class TestClass {
		var testClass: TestClass? = nil
}

var testClass1: TestClass? = TestClass() // retain count 1 증가
var testClass2: TestClass? = TestClass()

testClass1?.testClass = testClass2
testClass2?.testClass = testClass1

testClass1 = nil // retatin count 1 감소
testClass2 = nil // TestClass 클래스에 대한 count가 0됨 -> 메모리 해제
```

- 해당 인스턴스의 소유권 가짐
- 선언할 때 아무것도 안 적으면 디폴트로 strong

### Weak (약한 참조)

```swift
class TestClass{
    weak var testClass: TestClass? = nil
}
```

- 소유권은 안 갖고 주소값만 가짐 (포인터 개념)
  - 메모리 해제할 수 있는 권한 없음
- 참조는 하는데 카운트 증가 X
- 메모리 해제되면 변수가 자동으로 nil됨 (해제된 영역 가리키는 건 런타임에러니까)
  - 그래서 변수가 optional 타입이어야 함

# 순환 참조에 대하여 설명하시오.

- 두 객체가 서로 참조하고 있었는데 그 객체를 가리키는 것들이 해제되면 사용하지도 않는데 두 객체에게 접근할 수가 없어서 해제할 수도 없는 문제 생김
- 순환 참조가 있으면 해제되지 않아 메모리 누수 발생.

# 강한 순환 참조 (Strong Reference Cycle) 는 어떤 경우에 발생하는지 설명하시오.

- viewcontroller 안에 UIButton, UILabel, UI..View 등  `@IBOutlet weak var 변수: 타입!`
  - 만들 때 디폴트가 weak, 왜냐면 viewcontroller가 해제됐는데 안에 subview가 outlet 참조하고 있을 수 있음
- delegate
  - 부모 viewcontroller가 자식 viewcontroller 갖고 있는데, 자식 vc의 delegate를 부모로 연결하면 순환참조 됨. 그래서 delegate를 weak로 해야 함
- 클로저 블럭
  - [weak self]의 역할로는 ARC가 프로퍼티의 갯수를 카운팅 하지 않도록 만들며 카운팅이 되지 않기에 순환참조가 일어나지 않도록 만드는 역할
  - weak 참조는 ARC에 의해 참조되는 인스턴스가  메모리에서 해제될 때 프로퍼티의 값을 nil로 만들기 때문에 순환 참조가 발생하지 않음.

