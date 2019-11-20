use tableDB;
CREATE VIEW v_userTBL AS
    SELECT 
        userID, name, addr
    FROM
        usertbl;
        
select * from v_userTBl;
select * from userTBl;

-- 뷰 생성 --
use sqldb;
create view v_userbuyTBL
	as select U.userID as 'USER ID', U.name as 'USER NAME',
		B.prodName as 'PRODUCT NAME', U.addr, 
        concat(U.mobile1, U.mobile2) as 'MOBILE PHONE'
        from usertbl u inner join buytbl B on U.userID = B.userID;
        
select `USER ID`, `USER NAME` from v_userbuytbl;

-- 뷰 수정 -- 
alter view v_userbuytbl
	as select U.userID as '사용자 아이디', U.name as '이름',
	B.prodName as '제품 이름', U.addr, 
	concat(U.mobile1, U.mobile2) as '전화번호'
	from usertbl u inner join buytbl B on U.userID = B.userID;
    
select `사용자 아이디`, `이름` from v_userbuyTBl;

-- Replace (덮어씀, 자동으로 지우고 새로 테이블 생성) -- 
create or replace view v_userTBL
	as select userID, name, addr from usertbl;

describe v_userTBL;

show create view v_userTBL;

-- 그룹 합수를 포함한 뷰--
create view v_sum
	as select userID as 'userID', sum(price*amount) as 'total'
	from buytbl group by userID;
    
select * from v_sum;
    
-- 키가 177 이상인 사람의 뷰 생성-- 
create or replace view v_over177
	as select * from usertbl where height >=177;
    
select * from v_over177;

-- 키가 작은 사람 입력-- 
# 177 이상인 사람의 뷰인데 158인 사람의 정보를 넣어도 걸리지가 않는다.
insert into v_over177
	values('KBM', '김병만', 1977, '경기', '010', '55555555', 158, '2019-01-01');
    
# 'with check option'으로 조건을 걸어주면 177이하인 사람의 정보가 삽입되지 않는다.
alter view v_over177
	as select * from userTBL where height >= 177 with check option;
    
insert into v_over177
	values('KBM', '김병만', 1977, '경기', '010', '55555555', 158, '2019-01-01');
	
