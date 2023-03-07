# ARC란 무엇인지 설명하시오.



- automatic reference counting, 자동으로 메모리 관리해주는 모델
- 객체에 대한 참조 카운트가 0이 되면 메모리 해제함
  - 자동으로 retain, release를 적절한 위치에 삽입해서 retain count 관리함
  - heap 영역에서 관리
- 컴파일 타임 (코드를 빌드할 때) 실행됨
  - 컴파일 할 때 해제 시점이 정해져 있어서 추가적인 오버헤드도 없고 개발자가 파악할 수 있다는 장점
- 순환참조(strong reference cycle) 있으면 해제 안 돼서 메모리 누수 생길 수 있다는 단점

# Retain Count 방식에 대해 설명하시오.

**1) compile time**에는 코드를 분석하고 예측하여 적절한 위치에 retain, release를 삽입해준다.

**2) run time**에 삽입된 코드가 실행되면서 retain, release에 의해 reference count를 증감하고, count가 0이 되었을 때 메모리에서 제거한다.

**retain**

- 객체의 reference count(retain count)를 증가시킨다.
- 객체가 메모리에서 해제되지 않도록 이 함수를 호출하여 카운트를 증가시키는것

**release**

- 객체의 reference count(retain count)를 감소시킨다.
- 객체를 더이상 필요로 하지 않을 때 이 함수를 호출하여 카운트를 감소시키는 것



참조

https://seolhee2750.tistory.com/121

