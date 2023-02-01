# NSCache와 딕셔너리로 캐시를 구성했을때의 차이를 설명하시오.

딕셔너리는 메모리가 부족하면 값을 삭제하는 코드를 작성해야 하지만 NSCache는 메모리가 자동으로 관리된다.

- 시스템 메모리를 과도하게 사용하지 않도록하는 자동 삭제 정책

NSCache 는Thread-safe하다. lock하지 않아도 다른 스레드에서 캐시의 항목을 추가, 제거, 검색할 수 있다.

NSCache는 객체를 복사하지 않고 그대로 가져가지만, NSMutableDictionary의 Key는 객체를 복사해서 새로운 객체를 생성해서 Key로 등록한다.

참조

https://inuplace.tistory.com/1050