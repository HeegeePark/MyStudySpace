# String은 왜 subscript로 접근이 안되는지 설명하시오.

Swift 단점: String에서 subscript index로 접근 안된다. ㅡㅡ 왜 안되냐면 ,,



Swift에서의 String은 문자들의 집합

-> Character는 1개 이상의 유니코드 스칼라가 조합

-> 조합되어 만들어진다는것 자체가 그럼 한개의 유니코드 스칼라로 만들어질 수도 있고 여러개의 유니코드 스칼라로 만들어질 수도 있다는것

-> 하나의 Character에 들어오는 유니코드 스칼라의 갯수가 다를 수 있다는것이고 그 말인즉슨 **크기가 매번 일정치 않은 가변적**일 수 있기 때문에 서브스크립트 접근이 불가능하다.



- 서브스크립트를 String에서 extension해서 사용하기

``` swift
extension String {
  subscript(idx: Int) -> String? {
    guard(0..<count).contains(idx) else {
      return nil
    }
    let target = index(startIndex, offsetBy: idx)
    return String(self[target])
  }
}
```



참조

https://green1229.tistory.com/286