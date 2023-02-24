-- 자동 인덱스 --
use sqldb;
create table tbl1
	(a int primary key, b int, c int);
    
show index from tbl1;

create table tbl2
	(a int primary key, b int unique, c int unique);
    
show index from tbl2;

create table tbl3
	(a int unique, b int unique, c int unique);
    
show index from tbl3;

create table tbl4
	(a int unique not null, b int unique, c int unique, d int);
    
show index from tbl4;

insert into tbl4 values(3,3,3,3);
insert into tbl4 values(2,2,2,2);

select * from tbl4;

create table tbl5
	(a int unique not null, b int unique, c int unique, d int primary key);
    
show index from tbl5;

# 테이블을 생성하고 데이터 입력
create database if not exists testdb;
use testDB;
drop table if exists userTBL;
CREATE TABLE usertbl (
    userID CHAR(8) NOT NULL,
    name VARCHAR(10) NOT NULL,
    birthYear INT NOT NULL,
    addr NCHAR(2) NOT NULL
);

insert into userTBl values('LSG', '이승기', 1987, '서울');
insert into userTBl values('KBS', '김범수', 1979, '경남');
insert into userTBl values('KKH', '김경호', 1987, '서울');
insert into userTBl values('JYP', '조용필', 1987, '서울'); 

select * from usertbl;

# primary key 지정으로 자동 인덱스 생성 및 테이블 데이터 확인
alter table usertbl
	add constraint primary key (userID);

-- 혼합 인덱스 --
# 테이블 생성 및 데이터 입력
create database if not exists testdb;
use testdb;
drop table if exists mixedtbl;
create table mixedtbl 
	(userID char(8) not null, name varchar(10) not null, addr char(2));

select * from mixedtbl;

insert into mixedtbl values('LSG', '이승기', '서울');
insert into mixedtbl values('KBS', '김범수', '경남');
insert into mixedtbl values('KKH', '김경호', '전남');
insert into mixedtbl values('JYP', '조용필', '경기');
insert into mixedtbl values('SSK', '성시경', '서울'); 
insert into mixedtbl values('LFB', '임재범', '서울');
insert into mixedtbl values('YJS', '윤종신', '경남');
insert into mixedtbl values('EJW', '은지원', '경북');
insert into mixedtbl values('JKW', '조관우', '경기');
insert into mixedtbl values('BBK', '바비킴', '서울');

# userID에 클러스터형 인덱스, name에 보조형 인덱스 생성 및 확인
alter table mixedtbl
	add constraint primary key (userID);
alter table mixedtbl    
    add constraint unique key (name);
    
show index from mixedtbl;

-- 생성 및 제거 --
use tabledb;
select * from usertbl;
show index from usertbl;

show table status like 'userTBL';

create index idx_userTBL_addr on userTBL(addr);		# 보조형 인덱스

analyze table usertbl;
show table status like 'userTBL';

# birthYear과 nmae에 인덱스 생성 후 오류 나는 경우 확인 및 테이블 인덱스 확인
	# birthYear는 생일이 겹칠 수 있으니 보조 인덱스 생성 불가 (유니크하지 못함)
create index idx_userTBL_birthYear on userTBL(birthYear);
create index idx_userTBL_name on userTBL(name);

show index from usertbl;

	# 두 개의 컬럼을 엮어서 하나의 인덱스 생성하면 해결 가능
create index idx_userTBL_name_birthYear on usertbl(name,brithYear);

drop index idx_usertbl_name on usertbl;
show index from usertbl;