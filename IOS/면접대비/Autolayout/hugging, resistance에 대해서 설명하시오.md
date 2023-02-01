# hugging, resistance에 대해서 설명하시오.

### IntrinsicContentSize

**컨텐츠의 고유 사이즈** (UILabel, UIButton, UIImageView 등은 만들 때 너비와 높이를 지정하지 않아도 고유 사이즈가 설정된다.)
대부분의 뷰들은 intrinsicContentSize를 가지며, 표시되는 내용이 변경될 때 intrinsicContentSize도 함께 변경된다.
**하지만, UIView와 같은 컨테이너 역할을 하는 일부 컨텐츠들은 intrinsicContentSize가 없기 때문에 오토 레이아웃을 설정해주지 않으면 오류가 일어난다.**

- Content Hugging & Compression Resistance : intrinsicContentSize를 갖고 있는 컨텐츠에서 설정 가능

------

### Content Hugging

고유 사이즈의 최대 크기에 제한을 두는 것으로, 크기가 그 값보다 ***작아질 수 있다.\***
즉, 최대 크기보다 더 커지지 않는다.

### Compression Resistance

고유 사이즈의 최소 크기에 제한을 두는 것으로, 크기가 그 값보다 ***커질 수 있다.\***
즉, 최소 크기보다 더 작아지지는 않는다.

**Content Hugging과 Compression Resistance에서 `Priority`가 중요하다.**

A, B 두 개의 UILabel 에서 A보다 B의 Content Hugging 우선순위가 높다면 A의 크기가 커진다.
**B의 우선순위가 높으므로 작아질 수 있다고 해석되기 때문이다.**

또, 한 개의 버튼의 width값의 우선순위가 Compression Resistance의 우선순위보다 작다면 width로 설정한 값보다 버튼의 width가 커진다.
**Compression Resistance의 우선순위가 높으므로 커질 수 있다고 해석되기 때문이다.**