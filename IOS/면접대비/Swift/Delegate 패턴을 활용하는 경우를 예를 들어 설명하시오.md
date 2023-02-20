# Delegate 패턴을 활용하는 경우를 예를 들어 설명하시오.

### Delegate

Protocol를 이용하여 권한을 위임하고 일을 처리하는 방식의 디자인 패턴

- delegate pattern은 클래스나 구조체의 인스턴스에 특정 행위에 대한 책임을 다른 타입의 인스턴스에게 넘기는 방식이다.

### Protocol

프로토콜이란, 선언된 프로퍼티, 메소드, 기타 요구사항 등을 직접 구현하지 않고 특정 역할을 수행하고자, 조건만 제시한 규약

### 활용 예

View Controller에서, TableView의 특정 셀에 있는 여러 개의 버튼 중 특정 버튼을 눌렀을 경우에 해야할 일을 View Controller로 넘겨주기 위해서 Delegate 패턴을 사용

- TableViewCell이 선택되었을 경우 호출하는 기능은 TableView Delegate에서 기본적으로 처리하고 있지만, 셀 내부의 특정 버튼에대한 이벤트는 처리할 수 없으므로 직접 커스텀한 delegate를 사용해야 한다.

### 주의할 점

- delegate를 weak var로 선언해야 하며. (메모리 캡처링)
- A <-> B 관계가 아닌 A <-> B <-> C 객체간 소통인 경우에는 잘 사용하지 않는다고 한다.