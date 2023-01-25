# UINavigationController 의 역할이 무엇인지 설명하시오.

### UINavigationController

A container view controller that defines a stack-based scheme for navigating hierarchical content.

→ 스택구조로 하위 뷰컨트롤러들을 감싸고 있는 컨테이너 뷰컨트롤러

네비게이션 컨트롤러는 navigation stack( ordered Array)를 가지고 있으며 스택 내부에는 child ViewController가 들어간다.

첫번째 뷰컨트롤러는 root 뷰컨롤러로 스택에 최하단에 위치하며 마지막 viewcontroller는 navigation stack의 최상단에 위치하며 현재 보여주고있는 present viewcontroller이다.
