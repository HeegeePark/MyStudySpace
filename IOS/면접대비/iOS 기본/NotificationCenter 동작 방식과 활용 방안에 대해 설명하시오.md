# NotificationCenter 동작 방식과 활용 방안에 대해 설명하시오.

## Notification Center

- Listener (observer) : notifications를 감지
- Sender : 필요할 때 notifications 를 보내주는 역할
- itself : notification center 그 자체.

### 동작 방식

1. Observer가 관찰 시작
2. 작업이 발생하면 Sender가 Post
3. Observer selector 실행

<img width="620" alt="image" src="https://user-images.githubusercontent.com/47033052/212813290-d1614588-fb96-42f8-b816-2183c3a5e1d1.png">

``` swift
NotificationCener.default.addObserver(self, selector: #selector(noti(_:)), name: .noti, object: nil)
NotificationCenter.default.post(name: .noti, object: "전달값")
```

extension으로 Notification.Name의 태그를 정의해주면 편하게 쓸 수 있음.

``` swift
extension Notification.Name {
    static let noti = Notification.Name("noti")
}
```



### 활용 방안

- 특정 Event의 실행에 따라 동작해야하는 것 또는 동시적으로 여러 View에서 동작해야하는 것 등을 처리할 때에 활용할 수 있다.