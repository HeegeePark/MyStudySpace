# 자신만의 Custom View를 만들려면 어떻게 해야하는지 설명하시오.

## XIB 사용하기

1. UIView를 상속하는 Class 생성

UIView는 두개의 필수 생성자가 있다

<img width="306" alt="image" src="https://user-images.githubusercontent.com/47033052/214487631-09a5b66f-78e6-482a-a023-b73424b43ea0.png">

- override init

  코드로 뷰를 만들때 사용되는 생성자

  ```swift
  class ViewController: UIViewController {
      override func viewDidLoad() {
          super.viewDidLoad()
          let view = MyView(frame: self.view.frame)
          self.view.addSubview(view)
      }
  }
  ```

- required init

  스토리보드를 통해서 View를 연결 할때 사용되는 생성자

  

2. XIB File 만들기

