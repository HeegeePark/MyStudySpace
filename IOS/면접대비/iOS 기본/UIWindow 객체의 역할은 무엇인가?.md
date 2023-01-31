# UIWindow 객체의 역할은 무엇인가?

## UIWindow

The backdrop for your app’s user interface and the object that dispatches events to your views.

UI를 위한 환경을 제공하고 어플리케이션의 뷰, 객체에 이벤트를 전달하는 역할을 담당함

대부분의 iOS App은 하나의 window객체를 가지며 필요에 따라서 하나 이상의 window를 가질 수 있다.

- A 2nd UIWindow can be used to bring views on the screen that float on top of everything. Without creating a dummy controller just to embed that in a UIPopoverController.

- 앱이 외부 디스플레이나 비디오를 지원하는 앱은 추가 윈도우를 생성하기도 합니다.

- 여러개의 window를 사용할 경우 키보드 이벤트를 처리할 수 있는 window는 오직 한개만 존재해야하며 makeKey() 메소드를 사용해 key winndow(키보드 이벤트를 받는) 설정 할 수 있다.

window는 뷰에 이벤트를 전달하는 역할 뿐 아니라 뷰를 담는 컨테이너 역할을 하는데 window가 화면을 보여주는 것이 아니라 window에 속한 view가 contents를 보여준다.
