# 하나의 View Controller 코드에서 여러 TableView Controller 역할을 해야 할 경우 어떻게 구분해서 구현해야 하는지 설명하시오.

1. tableView로 구별

   tableview 종류로 구별해 cell 생성

2. tag로 구별

   tag로 구별해 각 테이블 뷰 헤더 등록

   ``` swift
   func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
           if tableView.tag == 1 {
               return "First TableView Header"
           } else {
               return "Second TableView Header"
           }
   }
   ```

   
