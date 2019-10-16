use sqldb;
select userID as '사용자 아이디', avg(amount) as '평균 구매 개수' from buytbl group by userID;

select * from usertbl;

# 키가 가장 작고 큰 사람 출력
select name, height from usertbl
	where height=(select max(height) from usertbl)
	or height=(select min(height) from usertbl);
    
# 12 구매 가격이 제일 높은 사람과 제일 낮은 사람의 ID 출력 (아이디별 묶기, 내림차순)
select userID, price from buytbl
	where price = (select max(price) from buytbl)
    or price = (select min(price) from buytbl)
    group by userID
    order by price desc;
    
select count(*) from usertbl;

select count(mobile1) as '휴대폰이 있는 사용자' from usertbl;

# 13 employees 테이블에 직원이 몇명있는지
use employees;
select * from employees;
select count(first_name) from employees;


