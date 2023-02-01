# stackView의 장점과 단점에 대해서 설명하시오.

## 장점

### 개발이 쉽다.

- 개발자가 직접 설정해줘야할 조건(Constraints)이 엄청 줄어든다.
  (Axis, Distribution, Alignment, Spacing 설정값에 맞게 자동으로 조건을 조정함)
  - Axis: 가로 or 세로
  - Spacing: 하위 뷰 사이 여백
  - Distribution: 하위 뷰의 크기 배분
  - Alignment: 하위 뷰의 위치 정렬
- 뷰를 추가하거나 삭제할 때 편리하다.
- 중첩하면 복잡한 레이아웃도 구현 가능하다.

### 빠르다.

- StackView 자체가 보여줄 컨텐츠가 없기 때문에 iOS가 화면을 띄울 때 별도로 렌더링하는 수고가 들지 않는다. (iOS 14 이전)

## 단점

### Background, corner등이 먹지 않는다.

- 비렌더링뷰이기 때문.
- **하지만,** iOS 14 이후 CATransformLayer를 사용하여 3D 레이어 계층을 만들며 CALayer와 달리 자체 콘텐츠를 표시하지 않는데 CALayer로 바뀌면서 background, corner 등 여러가지 정보를 포함하여 랜더링 할 수 있게 되었다.



참조

https://velog.io/@eddy_song/stack-view

https://fbdlrghks123.tistory.com/6