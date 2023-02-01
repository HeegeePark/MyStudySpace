# URLSession에 대해서 설명하시오.

![image](https://user-images.githubusercontent.com/47033052/215957946-921bbdec-2bc7-4ae7-8e5c-0fc307288b84.png)

URLSession은 네트워크 통신과 관련된 작업들의 그룹을 관리하는 객체

Foundation 프레임워크에 포함되어 있는 클래스이다.

## **Overview**

- URLSession은 URL을 통해 특정되는 엔드 포인트에 대해 데이터를 업로드하거나 다운로드 할 수 있도록 API를 제공한다.
- URLSession을 통해서 앱이 실행되지 않아도, 혹은 Suspended 상태여도 백그라운드에서 다운로드를 진행할 수 있게 도와준다.
- URLSessionDelegate나 URLSessionTaskDelegate를 사용하면 권한이나 리다이렉션, 작업 완료에 대한 이벤트를 받을 수 있다.
- 자동으로 백그라운드 스레드에 작업을 할당한다.
  - 그래서 UI 업데이트를 해주려면 DIspatchQueue.main.async로 메인 스레드를 지정해주어야 함.
- 앱에서는 여러개의 URLSession 인스턴스를 만들 수 있고, 각 인스턴스들이 데이터 통신과 관련된 작업들을 그룹지어서 관리한다.
  - 예) 웹 브라우저 앱을 구현한다면, 브라우저의 각 탭이나 창에 대해 세션을 하나씩 만들어줘야할 수도 있고, 사용자가 웹서핑을 하는데 사용하는 세션, 그리고 동시에 백그라운드에서 다운로드를 수행하는 세션으로도 나눌 수 있는..

---



참조

https://jeonyeohun.tistory.com/357