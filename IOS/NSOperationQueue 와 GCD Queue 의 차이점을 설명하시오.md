# NSOperationQueue 와 GCD Queue 의 차이점을 설명하시오.

### NSOperationQueue

- Objective-C 기반 고수준 API
- GCD보다 약간의 오버헤드가 더 발생되고 느리지만, KVO 지원 및 작업취소등을 지원
- 다양한 작업들 중에서 의존성을 추가할 수 있다
- 재사용, 취소, 중지 가능하다
- NSOperation을 만들어서 병렬 or 직렬로 스레드 풀을 사용가능하다.

### GCD Queue

- C기반 로우레벨의 API
- Global Queue에서 QOS 우선순위를 줄 수 있다.
- Main Queue: 메인 스레드에서 사용될 것 들을 처리, UI코드



---

## NSOperationQueue 장점

### 작업 취소

NSOperationQueue는 NSOperation의 Cancel을 통해 작업을 취소할 수 있도록 제어가 가능합니다. 하지만 GCD는 기조가 실행하고 잊어버리기때문에 취소를 구현할 수 있지만 부수적인 코드가 많이 작성됩니다.

### KVO

NSOperation은 isCancelled, isFinished등 작업의 상태가 변경되었는지를 알 수 있으며 좀 더 세세한 작업을 할 수 있습니다.

### 작업의 재사용

NSOperation의 자식 클래스를 만들어서 원하는 형태로 작업이 가능하며 작업이 끝나더라도 재사용할 수 있습니다.

### 작업 우선순위

각 작업은 우선순위가 있으며 작업들간의 우선순위를 매깁니다. 우선순위가 높은 작업이 우선순위가 낮은 작업보다 먼저 수행이 됩니다. GCD도 우선순위를 가지지만 같은 작업에 대해서는 직접적인 방법은 없으며, 개별 블럭이 아닌 전체 큐에 대한 우선순위를 설정합니다.

### 작업 간의 의존성

작업이 수행한 후 다른 작업이 수행할 수 있도록 작업 계층을 만들 수 있습니다.



참고자료

> https://minsone.github.io/mac/ios/how-to-using-nsoperation-and-nsoperationqueue