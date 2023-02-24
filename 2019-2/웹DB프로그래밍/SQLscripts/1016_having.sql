# having
use sqldb;
SELECT 
    userID AS '사용자', SUM(price * amount) AS '총구매액'
FROM
    buytbl
GROUP BY userID
HAVING SUM(price * amount) > 1000
ORDER BY SUM(price * amount) DESC;

select * from buytbl;

# with rollup (소계와 총계를 구할 때 사용)
SELECT 
    num, groupname, SUM(price * amount) AS 'cost'
FROM
    buytbl
GROUP BY groupname , num WITH ROLLUP;

# alter table testTBL2 auto_increment = 100;
# insert into testTBL2 values(NULL, '찬미', 23);

create table testTBL3 (id auto_increment primary key, name char(2), age char(3), gender char(1), address char(2));

alter table testTBL3 auto_increment = 1000;
set @@auto_increment_increment = 3;

insert into testTBL3 values('NULL', '나연', '20살', '여', '서울');
insert into testTBL3 values('NULL', '모모', '19살', '남', '경기');
insert into testTBL3 values('NULL', '정연', '21살', '여', '제주');
insert into testTBL3 values('NULL', '윤주', '22살', '여', '대전');

use sqlDB;
select * from employees.employees;

create table testTBL4(id int, Fname varchar(50), Lname varchar(50));
select * from testTBL4;
insert into testTBL4 select emp_no, first_name, last_name from employees.employees;

# very important
create table testTBL5(select emp_no, first_name, last_name from employees.employees);

# edit - preference? 들어가서 safe-update 체크박스 해제할 것.
update testtbl4 set Lname = '없음' where fname = 'kyoichi';
select * from testTBL4

update testtbl4 set Lname = '체크' where fname = 'mary';
select * from testTBL4 order by Fname;

delete from testtbl4 where fname = 'Aamer';

create table bigTBL1(select * from employees.employees);
create table bigTBL2(select * from employees.employees);
create table bigTBL3(select * from employees.employees);

# truncate 는 구조만 남겨놓은 채 데이터만 전부 삭제
delete from bigTBL1;
drop table bigTBL2;
truncate table bigTBL3;


create table memberTBL(select userID, name, addr from userTBL limit 3);
alter table membertbl add constraint pk_memberTBL primary key(userID);

select * from membertbl;

insert ignore into membertbl values('BBK', '비비코', '미국');
insert ignore into membertbl values('SJH', '서장훈', '서울');
insert ignore into membertbl values('HJY', '현주엽', '경기');




