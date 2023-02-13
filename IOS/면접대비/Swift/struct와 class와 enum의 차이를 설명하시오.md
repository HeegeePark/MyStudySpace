# struct와 class와 enum의 차이를 설명하시오.

<img src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/3639ca50-aad1-4f6b-b795-778187b9467e/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230213%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230213T050922Z&X-Amz-Expires=86400&X-Amz-Signature=2fbba4c0ac892552c197f1c71cdd7394667f12db945a57d6c4c52e8a5af00f0e&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject" width=50% />

- class는 레퍼런스타입, struct는 value 타입

  대입 연산하면 class는 레퍼런스 복사돼서 공유하고, struct는 값 자체가 복사돼서 공유 안 됨

  → 멀티스레딩할 때는 class는 lock해야 함

- class는 힙 영역에 저장됨. 주소 값이 스택 영역

- class는 상속 가능, struct는 불가능. 프로토콜은 가능!!



### value type, reference type

value type: enum, colletion(array, dictionary, set)

reference type: function, closure