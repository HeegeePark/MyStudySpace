# UIApplication 객체의 컨트롤러 역할은 어디에 구현해야 하는가?

**UIApplicationMain함수**

- 코코아 터치 프레임워크에서 앱의 라이프 사이클을 시작하는 함수
- UIApplication 객체의 인스턴스를 만들고, 해당 객체의 앱으로서 기능하기 위한 기반을 마련하는데 이 과정을 앱 로딩 프로세스라고 불림.
  - 앱에 몇가지 중요한 객체를 생성하고 스토리보드에서 UI를 로딩하고 앱의 초기 셋팅값(info.plist)을 불러오고 앱을 Run loop에 올려 놓으며 함수를 진행

---

## The Structure of an App

모든 iOS앱의 중심에는 시스템과 앱의 여러 객체들간의 대화를 가능하게 해주는 UIApplication 객체 존재.

앱의 Data와 비지니스 로직을 UI요소로부터 분리를 시켜주는 MVC 구조 사용.

![image](https://user-images.githubusercontent.com/47033052/212795958-acf0de34-09b3-4675-8a1f-ec425eb8ef8e.png)

## The Main Run Loop

Main Run Loop는 사용자 관련 이벤트들을 받은 순서대로 처리

UIApplication객체는 앱이 실행될 때, Main Run Loop를 실행하고, 이 Run Loop로 이벤트를 처리한다.

이름에서 알 수 있듯이, Main Run Loop는 앱의 메인 스레드에서 동작한다.

- 사용자가 디바이스에서 특정 액션은 취하면, 그 액션에 해당하는 이벤트가 시스템에 의해 생성되어 UIKit에서 생성한 port를 통해 앱에 전달된다. 전달된 이벤트들은 queue에 보관되고 하나씩 Main Run Loop로 전달되어 처리한다.

![image](https://user-images.githubusercontent.com/47033052/212795768-43a7ea52-48a5-4299-8f9f-97d18657573c.png)



참고자료

> https://jinshine.github.io/2018/05/28/iOS/%EC%95%B1%EC%9D%98%20%EC%83%9D%EB%AA%85%EC%A3%BC%EA%B8%B0(App%20Life%20Cycle)%EC%99%80%20%EC%95%B1%EC%9D%98%20%EA%B5%AC%EC%A1%B0(App%20Structure)/