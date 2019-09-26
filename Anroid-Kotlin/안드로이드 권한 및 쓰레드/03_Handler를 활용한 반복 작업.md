# Handler를 활용한 반복 작업
## Main Thread에서의 반복
- Main Thread에서 처리한느 코드(Activity내의 코드) 중에 일정 작업을 계속 반복 처리해야할 경우가 있음.
- 하지만 무한 루프를 쓰면 화면처리 불가능
- Handler를 통해 원하는 코드를 반복해서 작업하는 것이 가능함.
	- Handler를 통해서 어떤 작업을 요청하게 되면, 안드로이드 OS가 한가할 때 한번 작업을 수행
	- 위 과정을 계속 반복
	- 반복 속 쉬는 시간에 안드로이드는 화면 처리
	- 그래서 무한 루프는 쉬는 시간이 없어서 화면 처리가 불가능함.

## Handler
- Handler는 개발자가 안드로이드 OS에게 작업 수행을 요청하는 역할을 함.
- 개발자가 작업을 요청하면 안드로이드 OS는 작업을 하지 않을 때 개발자가 요청한 작업을 처리하게 됨.
- Main Thread에서 처리함.
	- 네트워크와 같은 작업 또는 오래 걸리는 작업들은 보통 개발자가 만드는 일반 쓰레드로 처리하기 때문에 Main Thread는 비교적 여유로워서 Handler가 요청한 작업을 수행함.
- 5초 이상 걸리는 작업 불가.
	- 5초 이상 걸리면 일반 쓰레드를 만들어서 수행함.
	- 왜냐면 Handler는 메인 쓰레드에 일을 시키기 때문.
- 화면 처리가 가능

## 실습
- src link : https://github.com/HeegeePark/Study_Kotlin/tree/master/src/Permissions%20and%20Thread/03_HandlerIterativeTasks
