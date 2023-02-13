# Convenience init에 대해 설명하시오.

보조 이니셜라이저로, 클래스의 원래 이니셜라이저인 init을 도와주는 역할

convenience init은 같은 클래스에서 다른 이니셜라이저를 호출해야한다는 규칙이 있다.

Convenience init 내부에서 반드시 Designated init이 호출되어야 한다. like self.init()

파라미터로 넘어간 것들만 넣어주면 된다.

``` swift
class Person {
    var name: String
    var age: Int
    var gender: String

    init(name: String, age: Int, gender: String) {
        self.name = name
        self.age = age
        self.gender = gender
    }
		
		convenience init(age: Int, gender: String) {
        self.init(name: "zedd", age: age, gender: gender)
    }
}
```

