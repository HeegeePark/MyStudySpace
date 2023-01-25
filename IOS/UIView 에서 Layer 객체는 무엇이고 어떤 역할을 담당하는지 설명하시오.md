# UIView 에서 Layer 객체는 무엇이고 어떤 역할을 담당하는지 설명하시오.

### iOS Graphic

Core Graphics 에서 UIKit 으로 갈 수록 간편해지고 코드량도 줄었지만 사용할 수 있는 기능은 제한된다. 반면 저수준의 프래임워크는 보다 많은 기능을 사용할 수 있지만 UIKit, AppKit 에서 기본적으로 제공하는 기능들을 직접 구현해야하는 경우가 생긴다

![image](https://user-images.githubusercontent.com/47033052/214489344-17008aa6-1eca-4286-baee-c8d481735e7c.png)

### CALayer

![image](https://user-images.githubusercontent.com/47033052/214489389-a56e4650-a9af-4c64-a682-13c8017cbdb7.png)

CALayer는 Core Animation API가 제공하는 요소중 하나로 UIView가 가지고 있는 속성이다 UIView의 역할 ( 1. 화면 표시, 2. 터치 이벤트, 3. subview) 중 화면표시하는 작업을 직접 처리하지 않고 Core Animation에 위임하여 처리한다. 에니메이션, View 형태 변환등을 처리할 수 있다

- 레이어의 위치와 크기
- 레이어의 배경색
- 레이어에 그려질 컨텐츠 (이미지를 출력하거나 Core Graphic를 통해 그려진 그래픽 등)
- 레이어의 모서리가 둥글게 그려져야 하는지
- 레이어에 그림자 추가하기
- 레이어에 외곽선 그리기