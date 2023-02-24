create database sqldb;
use sqldb;

create table stdTBL (stdName char(3) primary key not null, addr char(2) not null);
create table clubTBL (clubName char(2) primary key not null, roomNo char(4) not null);
create table stdclubTBL (id int auto_increment primary key not null, stdName char(3) not null, clubName char(2) not null,
	foreign key(stdName) references stdTBL(stdName),
    foreign key(clubName) references clubTBL(clubName));
    
select * from stdtbl;
select * from clubtbl;
select * from stdclubtbl;

insert into stdtbl value('김범수', '경남');
insert into stdtbl value('성시경', '서울');
insert into stdtbl value('조용필', '경기');
insert into stdtbl value('은지원', '경북');
insert into stdtbl value('바비킴', '서울');

insert into stdclubtbl value(null, '김범수', '바둑');
insert into stdclubtbl value(null, '김범수', '축구');
insert into stdclubtbl value(null, '조용필', '축구');
insert into stdclubtbl value(null, '은지원', '축구');
insert into stdclubtbl value(null, '은지원', '봉사');
insert into stdclubtbl value(null, '바비킴', '봉사');

insert into clubtbl value('수영', '101호');
insert into clubtbl value('바둑', '102호');
insert into clubtbl value('축구', '103호');
insert into clubtbl value('봉사', '104호');

select S.stdName, S.addr, C.clubName, C.roomNo
	from stdtbl S inner join stdclubtbl SC on S.stdName = SC.stdName
    inner join clubtbl C on SC.clubName = C.clubName
    order by S.stdName;
    
select C.clubName, C.roomNo, S.stdName, S.addr
	from stdtbl S inner join stdclubtbl SC on SC.stdName = S.stdName
    inner join clubtbl C on SC.clubName = C.clubName
    order by C.clubName;
    
# Outer join
use sqlDB;

select U.userID, U.name, B.prodName, U.addr, CONCAT(U.mobile1, U.mobile2) as '연락처'
	from usertbl U left outer join buytbl B on U.userID = B.userID
    order by U.userID;
    
select U.userID, U.name, B.prodName, U.addr, CONCAT(U.mobile1, U.mobile2) as '연락처'
	from buytbl B right outer join usertbl U on U.userID = B.userID
    order by U.userID;
    
select U.userID, U.name, B.prodName, U.addr, CONCAT(U.mobile1, U.mobile2) as '연락처'
	from buytbl B right outer join usertbl U on U.userID = B.userID
    where B.prodName is null
    order by U.userID;

# 실습
# 1
select S.stdName, S.addr, C.clubName, C.roomNo
	from stdtbl S left outer join stdclubtbl SC on S.stdName = SC.stdName
    left outer join clubtbl C on SC.clubName = C.clubName
    order by S.stdName;

# 2
select C.clubName, C.roomNo, S.stdName, S.addr
	from stdtbl S left outer join stdclubtbl SC on S.stdName = SC.stdName
    right outer join clubtbl C on SC.clubName = C.clubName
    order by C.clubName;
    
# 3 (1,2 결과 합치기)
select S.stdName, S.addr, C.clubName, C.roomNo
	from stdtbl S left outer join stdclubtbl SC on S.stdName = SC.stdName
    left outer join clubtbl C on SC.clubName = C.clubName
union
select C.clubName, C.roomNo, S.stdName, S.addr
	from stdtbl S left outer join stdclubtbl SC on S.stdName = SC.stdName
    right outer join clubtbl C on SC.clubName = C.clubName;
    
# Self join
# 1 테이블 만들기
create table empTBL(emp char(3) primary key not null, manager char(3), num char(10) not null);
insert into empTBL value('나사장', null, '0000');
insert into empTBL value('김재무', '나사장', '2222');
insert into empTBL value('김부장', '김재무', '2222-1');
insert into empTBL value('이부장', '김재무', '2222-2');
insert into empTBL value('우대리', '이부장', '2222-2-1');
insert into empTBL value('지사원', '이부장', '2222-2-2');
insert into empTBL value('이영업', '나사장', '1111');
insert into empTBL value('한과장', '이영업', '1111-1');
insert into empTBL value('최정보', '나사장', '3333');
insert into empTBL value('윤차장', '최정보', '3333-1');
insert into empTBL value('이주임', '윤차장', '3333-1-1');

# 2 우대리의 상관 연락처 확인
select A.emp as '부하직원', B.emp as '직속상관', B.num as '직속상관 구내번호'
	from emptbl A inner join emptbl B on A.manager = B.emp
	where A.emp = '우대리';
    
# Union
select stdName, addr from stdtbl
union all
select clubName, roomNo from clubtbl;
select name, concat(mobile1, nobile2) as '전화번호' from usertbl
	where name not in (select name from usertbl where mobile1 is null);
    
select name, concat(mobile1, mobile2) as '전화번호' from usertbl
	where name in (select name from usertbl where mobile1 is null);

