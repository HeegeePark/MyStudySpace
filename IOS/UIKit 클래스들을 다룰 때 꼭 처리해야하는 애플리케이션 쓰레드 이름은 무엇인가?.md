# UIKit 클래스들을 다룰 때 꼭 처리해야하는 애플리케이션 쓰레드 이름은 무엇인가?

### Main Thread

UIKit은 앱의 메인 스래드 혹은 메인 디스패치큐에서만 사용이 가능하다.

UIResponder에서 파생되거나 어떤 방식으로든 앱의 사용자 인터페이스를 조작하는 것과 관련된 클래스에 해당 제한이 있는데,

앱의 UI event는 일반적으로 UIApplication -> UIWindow -> UIViewController -> UIView -> subviews (UIButton 등)와 같이 chain으로 연결되고, 이 responder chain을 따라 UIResponder로 전달된다.

Responder는 버튼 누르기, 탭, pinch, 확대/축소, 스와이프 등의 이벤트를 UI 변경사항으로 처리한다. 따라서 이러한 일련의 event chain이 UIKit의 main thread에서 작동하는 이유이다. 



>  [참고자료](https://zeddios.tistory.com/519)

