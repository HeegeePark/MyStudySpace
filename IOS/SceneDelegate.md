# scene delegate에 대해 설명하시오.

iOS 13 이후, 앱 하나에서 여러 개의 scene을 지원하면서(Multiple Window) AppDelegate에서 UI Life Cycle 부분을 SceneDelegate가 하게 됨.

- AppDelegate에서는 앱 자체의 생명주기를 담당
- 앱이 실행되고난 뒤 UI, Background 처리, 등의 나머지 작업들은 모두 SceneDelegate에서 처리

<img width="1419" alt="image" src="https://user-images.githubusercontent.com/47033052/212704056-ec500afd-8f98-414f-9a56-e283d48b0c58.png">



참고자료

> https://zeddios.tistory.com/811