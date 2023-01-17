# Global DispatchQueue 의 Qos 에는 어떤 종류가 있는지, 각각 어떤 의미인지 설명하시오.

## Global Queue

- **Concurrent** 특성을 가진 Queue
  - 작업을 보낼 때 순서가 중요하지 않음.
- QoS (Quality Of Service)에 따라 여러개의 종류로 나뉨 (6종류)
  - 작업의 중요도 결정 가능
  - qos에 의해 우선순위가 더 높은 task를 더 많은 스레드에 배치함.

## QoS 종류

### userInteractive

- 사용자와 직접 상호작용 (UI 업데이트, 애니메이션 등)
- 사용자 행동에 대한 즉각적인 반응이 기대되나, 메인 스레드에서 처리하기 많은 로드가 걸릴 작업들을 이곳에서 처리해서 바로 동작하는 것처럼 보이게 함.

### userInitiated

- 클릭 시 작업을 수행하는 것과 같은 즉각적인 결과가 필요한 작업(저장된 문서 열기)
- userInteractive보다는 오래 걸리고 유저도 어느 정도 인지하고 있음.

### default

- 일반적인 작업(기본값)

### utility

- 보통 progress bar와 함께 길게 실행되는 작업(데이터 다운로드)

### background

- 유저가 직접적으로 인지하지 않는 시간이 덜 중요한 작업(동기화, 백업)

### unspecified

- Qos 정보가 없음을 의미, 거의 사용할 일 없음.



참고자료

> https://sujinnaljin.medium.com/ios-%EC%B0%A8%EA%B7%BC%EC%B0%A8%EA%B7%BC-%EC%8B%9C%EC%9E%91%ED%95%98%EB%8A%94-gcd-5-c8e6eee3327b