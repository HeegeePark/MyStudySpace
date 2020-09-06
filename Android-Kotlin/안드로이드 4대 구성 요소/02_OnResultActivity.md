# OnResultActivity
- 액티비티에서 다른 액티비티를 실행하고 다시 돌아왔을 때 어떤 처리가 필요하다면 startActivityForResult 메서드 사용

## onActivityResult
- startActivityForResult 메서드를 이용해 Activity를 실행하고 돌아오면 자동으로 onActivityResult 메서드가 호출됨.
- 여기에서 필요한 작업 처리를 함.
- 파라미터
	- requestCode : startActivityForResult 메서드를 사용할 때 액티비티에 따른 request code 값을 이용하여 어느 액티비티를 갔다왔는지 알 수 있음.
	- resultCode : 다른 액티비티에서 상황에 따라 설정된 상수값(setResult(num))에 따른 값 설정.
		- RESULT_OK : 결과가 정상적으로 처리되었다는 상수값
		- RESULT_CANCELED : 사용자에 의해 취소되었다는 상수값, 또는 백버튼을 눌르면 설정됨.
		- RESULT_FIRST_USER : 그 외 여러가지 결과에 따른 상수값, 사용자 정의 가능


 