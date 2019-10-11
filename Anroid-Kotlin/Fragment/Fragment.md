# Fragment (Activity내의 작은 화면 조각)
- 여러 화면을 가지고 있는 애플리케이션을 여러 Activity를 가지고 있는 애플리케이션을 의미.
- Activity는 독립된 실행단위로 메모리를 많이 소모하는데 독립된 실행단위가 아닌 화면만 필요한 경우 Activity보다는 Fragment를 사용하는 것이 효율적.
- Fragment는 Activity내의 작은 화면의 조각으로 Activity의 화면을 여러 영역으로 나누어 관리하는 목적을 가짐.
- Fragment는 안드로이드 5.0에서 추가되었지만 하위 버전에서도 사용할 수 있도록 설계.
- add : Fragment를 지정된 레이아웃에 추가
- replace : 지정된 레이아웃에 설정되어 있는 Fragment를 제거하고 새로운 Fragment 추가