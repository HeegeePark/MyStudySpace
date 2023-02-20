# Singleton 패턴을 활용하는 경우를 예를 들어 설명하시오.

### 활용 예

- `UIApplication` , `NotificationCenter` , `URLSession`, `URLCache`
- 혹시 다른 클래스에서 NSCache 타입의 변수를 선언하면 클래스가 메모리에서 해제되거나 초기화될 때 캐시도 초기화되므로 싱글톤을 통해서 실수로 초기화하는 일이 없게 하기 위해서
- NotificationCenter.default를 사용하면 앱 전체에서 해당 알림을 광범위하게 관찰할 수 있기 때문에 defualt는 Singleton 패턴으로 구현되어 있다.
- UIApplication은 앱에서 하나만 존재해야 하기 때문에 싱글톤 패턴으로 구현되어 있다.

---

## Singleton Pattern

특정 용도로 객체를 하나만 생성하여, 공용으로 사용하고 싶을 때 사용하는 디자인 유형

객체가 앱에서 유일하게 하나만 존재하여 다른 객체들 그 안에 내용을 공유하는 방식!

- 생성자가 여러 차례 호출되더라도 실제로 생성되는 객체는 하나이고, 최초 생성 이후에 호출된 생성자는 최초의 생성자가 생성한 객체를 리턴한다.

``` swift
class Singleton {
		static let shared = Singleton()  // static 변수로 자신을 반환
		private init() {}  // private이기 때문에 다른 곳에서 new 할 수 없음
}
```

- 해당 클래스와 같은 타입의 타입 프로퍼티를 생성하여 객체를 생성하지 않아도 접근이 가능하도록 한다.
- static 전역 변수로 선언하는데 이 프로퍼티는 지연생성(lazy)되기 때문에 처음 Singleton Class를 생성하기 전 까지는 메모리에 올라가지 않는다.
- 생성자를 prvate으로 선언해줌으로써 여러 개의 객체 생성을 방지함.



참조

https://hackmd.io/@GKiRpG6sSDi20vYC81NlzA/BJGnKHtMj