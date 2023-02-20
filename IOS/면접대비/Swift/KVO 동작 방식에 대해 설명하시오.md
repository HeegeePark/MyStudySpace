# KVO 동작 방식에 대해 설명하시오.

### Key Value Observing

- B라는 오브젝트의 속성 값이 변경되었을 때,  A라는 오브젝트가 알게 되는 것
- **프로퍼티의 상태에 반응하는 형태**
- 두 객체 사이의 정보를 맞춰주는 것이 쉬움.
- new/old value를 쉽게 얻을 수 있음.

### 동작 방식

모델 객체의 어떤 값이 변경되었을 경우 이를 UI에 반영하기 위해서 컨트롤러는 모델 객체에 Observing을 도입하여 델리게이트에 특정 메시지를 보내 처리할 수 있도록 하는 것

즉, 변수에 코드를 붙여 변수가 변경될 때마다 코드가 실행되도록 하는 방법을 의미한다. property observers(willset , didSet)과 아주 유사한데 KVO는 타입 정의 밖에서 observe를 추가한다는 점이 다르다.

### 단점

- NSObject를 상속받는 객체에서만 사용이 가능함.
- dealloc될 때 옵저버를 지워줘야 함.
- 많은 value를 감지할 때는 많은 조건문이 필요.

참조

https://woozzang.tistory.com/124

https://hackmd.io/@j6y9vYO-QQ6cYUUQsvxYPQ/r1WFVByds

https://you9010.tistory.com/275