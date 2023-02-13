# Intrinsic Size에 대해서 설명하시오.

### IntrinsicContentSize

**컨텐츠의 고유 사이즈** (UILabel, UIButton, UIImageView 등은 만들 때 너비와 높이를 지정하지 않아도 고유 사이즈가 설정된다.)
대부분의 뷰들은 intrinsicContentSize를 가지며, 표시되는 내용이 변경될 때 intrinsicContentSize도 함께 변경된다.
**하지만, UIView와 같은 컨테이너 역할을 하는 일부 컨텐츠들은 intrinsicContentSize가 없기 때문에 오토 레이아웃을 설정해주지 않으면 오류가 일어난다.**

- Content Hugging & Compression Resistance : intrinsicContentSize를 갖고 있는 컨텐츠에서 설정 가능
