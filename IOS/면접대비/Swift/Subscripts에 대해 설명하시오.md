# Subscripts에 대해 설명하시오.

### Subscript란?

- 서브스크립트는 **클래스, 구조체, 열거형에서 정의해서 사용하는 스크립트**
  - 즉 컬렉션, 리스트, 시퀀스 등 **집합 내 속한 요소에 쉽게 접근할 수 있게 해주는 문법**
- **메서드 구현없이도 단순히 값의 추가 및 획득** 등이 가능
  - Ex: 배열의 특정 요소를 접근하는 Array[index] 
- 오버로드로 입맛대로 정의 가능

``` swift
subscript(index: Int) -> Int {
  get {
    // Return an appropriate subscript value here.
  }
  set(newValue) {
    // Perform a suitable setting action here.
  }
}
```

``` swift
struct Age {
  let multiplier: Int
  subscript(index: Int) -> Int {
      return multiplier * index
  }
}

let greenAge = Age(multiplier: 12)
print("greenAge's converted age is \(greenAge[5])")

// Prints "greenAge's converted age is 60"
```

참조

https://green1229.tistory.com/286