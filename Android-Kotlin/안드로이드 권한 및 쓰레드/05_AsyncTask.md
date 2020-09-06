# AsynTask

- AsynTask는 비 동기 처리를 위해 제공되는 클래스
- 개발자가 발생 시키는 쓰레드와 핸들러의 조합으로 쓰레드 운영 중 화면 처리가 가능했던 구조를 클래스로 제공하는 것
# 메서드
- onPreExecute : doInBackground 메서드가 호출되기 전에 호출되는 메서드
	- Main Thread가 처리

- doInBackground : 새로운 쓰레드를 발생해서 일반 쓰레드에서 처리

- onProgressUpdate : doInBackground 메서드에서 publishProgress 메서드를 호출하면 Main Thread가 처리하는 메서드
	- doInBackground 메서드 내에서 화면 처리가 필요할 때 사용

- onPostExecute : doInBackground 메서드 수행 완료 후 호출 (Main Thread가 처리)
