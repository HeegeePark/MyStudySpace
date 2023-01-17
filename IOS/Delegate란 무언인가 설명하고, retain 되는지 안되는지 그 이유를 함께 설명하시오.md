# Delegate란 무언인가 설명하고, retain 되는지 안되는지 그 이유를 함께 설명하시오.

## Delegate

- 하나의 객체가 모든 일을 처리하는 것이 아니라 처리해야 할 일 중 일부를 다른 객체에게 위임하는 것
- 객체의 행동을 단순화

### retain

- 메모리가 해제되지 않아서 낭비되는 현상
- Memory Leak, 메모리 누수

### retain이 일어나는가?

- Delegate는 객체 간의 작업이여서 참조 값을 사용하기 때문에 retain 현상이 발생한다.
- Tableview와 같이 delegate를 weak으로 선언하여 메모리가 해제될 시 자동으로 해제시켜 주어야 한다.

``` swift
weak var delegate: UITableViewDelegate? { get set }
```

