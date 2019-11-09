use sqlDB;

select * from buytbl inner join usertbl on buytbl.userID = usertbl.userID
	where buytbl.userID = 'JYP';

select * from buytbl;

# 에러 코드 (컬럼이 어디 테이블인지 알려줘야함, 겹치치 않는 컬럼은 에러는 안나지만 해주면 좋음)
select userID, name, prodName, addr, mobile1 + mobile2 as '연락처'
	from buytbl inner join usertbl on buytbl.userID = usertbl.userId;
select buytbl.userID, name, prodName, addr, mobile1 + mobile2 as '연락처'
	from buytbl inner join usertbl on buytbl.userID = usertbl.userId;
    
# 올바른 코드
select buytbl.userID, usertbl.name, buytbl.prodName, usertbl.addr, usertbl.mobile1 + usertbl.mobile2 as '연락처'
	from buytbl inner join usertbl on buytbl.userID = usertbl.userId;
    
# 테이블 별칭 붙여 사용하기
select B.userID, U.name, B.prodName, U.addr, U.mobile1 + U.mobile2 as '연락처'
	from buytbl B inner join usertbl U on B.userID = U.userId;

# order by로 정렬
select B.userID, U.name, B.prodName, U.addr, U.mobile1 + U.mobile2 as '연락처'
	from buytbl B inner join usertbl U on B.userID = U.userId
    order by U.userID;
    
# distinct
select distinct U.userID, U.name, U.addr from usertbl U inner join buytbl B
	on U.userID = B.userID
    order by U.userID;
    
