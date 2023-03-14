# 순수함수란 무엇인지 설명하시오.

**특정 input에 대해서 항상 동일한 output을 반환하는 함수**

- immutable data만 사용하는 함수도 특정 input에 대해 항상 동일한 output을 내기 때문에 순수 함수

``` swift
let offset: CGFloat = 10.0
func getOffset(curHeight: CGFloat) -> CGFloat {
    return offset + curHeight
}
```

output을 만드는데 input만을 사용한다는 의미로, 함수 외부의 값을 사용하지 않아 사이드 이펙트가 없음.

- output은 input에 의해서만 결정된다.
- 함수의 수행 과정에서 외부에 있는 값을 사용하지 않는다.
- 외부의 값을 변경하지 않는다.
- 외부에 영향을 주지도 ,받지도 않으므로 side-effect가 발생하지 않는다.

# 함수형 프로그래밍이 무엇인지 설명하시오.

**"순수함수"를 이용해서 프로그래밍을 하는 것**

### 특징

- 불변 데이터(Immutable Data)
- 1급 함수(First-Class Function)
- 순수 함수(Pure Function)

### 장점

- 멀티 코어가 기본이 되면서 ‘동시성’ 처리에 함수형 프로그래밍이 강점을 보임
- 불변값을 주로 다루기 때문에 Side Effect가 적어 동시성 처리가 쉬워짐
- 코드 이해하기 쉬움
- 유지보수 쉬움

# 고차 함수가 무엇인지 설명하시오.

다른 함수를 전달인자로 받거나 함수실행의 결과를 함수로 반환하는 함수

- 스위프트의 함수(클로저)는 일급시민(일급객체)이기 때문에 함수의 전달인자로 전달할 수 있으며, 함수의 결과값으로 반환 가능

# Swift Standard Library의 map, filter, reduce, compactMap, flatMap에 대하여 설명하시오.

- 스위프트 표준라이브러리에서 제공하는 고차함수 [map, filter, reduce]
- 스위프트 표준 라이브러리의 컨테이너 타입(Array, Set, Dictionary 등)에 구현되어 있음.

---

- `map` 함수는 컨테이너 내부의 기존 데이터를 **변형(transform)하여 새로운 컨테이너를 생성**.
- `filter` 함수는 컨테이너 내부의 **값을 걸러서 새로운 컨테이너로 추출**
- `reduce` 함수는 컨테이너 내부의 **콘텐츠를 하나로 통합**
- `flatMap` 함수는 map과 동일하지만, **차원을 한단계 낮춘 새로운 컨테이너를 생성**
- `compactMap` 함수는 map과 동일하지만, 결과값에서 **nil을 제거하고 옵셔널 바인딩을 적용시킨 새로운 컨테이너**를 생성



참조

https://hackmd.io/@NItj2RZUR_6qs26fqgepdg/SJyyGApR9
