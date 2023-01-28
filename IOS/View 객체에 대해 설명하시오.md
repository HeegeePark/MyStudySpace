# View 객체에 대해 설명하시오.



## UiView

```swift
class UIView: UIResponder
```

앱 화면에서 시각적으로 표시되는 UI는 공통적으로 View를 가지고 있다 View는 자신의 영역에서 화면을 표시 할 뿐 아니라 터치 이벤트를 처리한다.

## View

사용자 인터페이스의 기본 구성 요소

### View 의 역할

1. 화면에 Content (이미지, 텍스트) 표시

   On-demand Drawing Model

   View 가 최초로 생성될때 bitmap cache를 생성하고 View 내부에 저장함

   content가 변경되지 않고 크기, 위치가 변경되면 캐시를 출력한다

2. 터치 이벤트 처리

   UIKit - gesture recognizer 사용해 다양한 제스쳐 구현가능

   UILabel 텍스트를 보여주는 view는 기본적으로 터치 이벤트가 비활성화 되어있지만 gesture recognizer를 사용해 이벤트 처리 할 수 있다.

3. Laying out Subviews

​	View는 하나 이상의 subview를 가질 수 있고 superview는 한개만 있다 subview는 배열로 관리하며 마지막에 추가된 subview가 가장 위에 표시된다.

