# 모든 View Controller 객체의 상위 클래스는 무엇이고 그 역할은 무엇인가?

### UIViewController

UIKit 앱의 뷰 계층 구조를 관리하는 객체

```swift
class UIViewController: UIResponder
```

뷰 컨트롤러의 주요 책임

- 기본 데이터의 변경에 대한 응답으로 뷰의 콘텐츠를 업데이트
- 뷰와 사용자 상호 작용에 응답
- 뷰 크기 조정 및 전체 인터페이스의 레이아웃 관리
- 앱에서 다른 뷰 컨트롤러를 포함한 다른 객체와 조정
