use sqldb;
drop table if exists buytbl, usertbl;

CREATE TABLE usertbl (
    userID CHAR(8) NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL,
    birthYear INT NOT NULL,
    addr CHAR(2) NOT NULL,
    mobile1 CHAR(3) NULL,
    mobile2 CHAR(8) NULL,
    height SMALLINT NULL,
    mDate DATE NULL
);

CREATE TABLE buytbl (
    num INT NOT NULL PRIMARY KEY,
    userID CHAR(8) NOT NULL,
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL,
    FOREIGN KEY (userId)
        REFERENCES usertbl (userID)
);

# Primary Key
describe usertbl;

drop table if exists prodtbl;
CREATE TABLE prodtbl (
    prodCode CHAR(3) NOT NULL,
    prodID CHAR(4) NOT NULL,
    prodDate DATETIME NOT NULL,
    prodCur CHAR(10) NULL
);

alter table prodtbl 
	add constraint pk_prodtbl_proCode_prodID 
    primary key (prodCode,prodID);
    
select * from prodtbl;
describe prodtbl;

drop table if exists prodtbl;
CREATE TABLE prodtbl (
    prodCode CHAR(3) NOT NULL,
    prodID CHAR(4) NOT NULL,
    prodDate DATETIME NOT NULL,
    prodCur CHAR(10) NULL,
    CONSTRAINT pk_prodtbl_proCode_prodID PRIMARY KEY (prodCode , prodID)
);

show index from prodtbl;

# Foreign Key

# 방법 1
drop table if exists buytbl;

CREATE TABLE buytbl (
    num INT NOT NULL PRIMARY KEY auto_increment,
    userID CHAR(8) NOT NULL,
    FOREIGN KEY (userID)
        REFERENCES usertbl (userID),
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL
);

# 방법 2
drop table if exists buytbl;

CREATE TABLE buytbl (
    num INT NOT NULL PRIMARY KEY auto_increment,
    userID CHAR(8) NOT NULL,
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL,
    CONSTRAINT fk_usertbl_buytbl FOREIGN KEY (userID)
        REFERENCES usertbl (userID)
);

# 방법 3
drop table if exists buytbl;

CREATE TABLE buytbl (
    num INT NOT NULL PRIMARY KEY auto_increment,
    userID CHAR(8) NOT NULL,
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL
);

alter table buytbl 
	add CONSTRAINT fk_usertbl_buytbl FOREIGN KEY (userID)
        REFERENCES usertbl (userID);
        
# 외래키 설정 삭제하고 변경
alter table buytbl
	drop foreign key fk_usertbl_buytbl;
alter table buytbl
	add constraint fk_UU_BB foreign key(userID) references usertbl(userID) on update cascade;
    
# 테이블 압축
show variables like 'innodb_file_format';
show variables like 'innodb_large_prefix';

create database if not exists compressDB;

use compressDB;
CREATE TABLE normaltbl (
    emp_no INT,
    first_name VARCHAR(14)
);
CREATE TABLE compresstbl (
    emp_no INT,
    first_name VARCHAR(14)
)  ROW_FORMAT=COMPRESSED;

insert into normaltbl select emp_no, first_name from employees.employees;

insert into compresstbl select emp_no, first_name from employees.employees;

show table status from compressDB;
drop database if exists compressDB;

# 임시 테이블
use employees;

create temporary table if not exists temptbl(ID int, name char(5));
create temporary table if not exists employees(ID int, name char(5));
describe temptbl;
describe employees;

insert into temptbl values(1, 'This');
insert into employees values(2, 'MySQL');

select * from temptbl;
select * from employees;

drop table temptbl;

# 종합 실습
create database tableDB;

use tableDB;

drop table if exists buytbl, usertbl;
CREATE TABLE usertbl (
    userID CHAR(8),
    name NVARCHAR(10),
    brithYear INT,
    addr NCHAR(2),
    mobile1 CHAR(3),
    mobile2 CHAR(8),
    height SMALLINT,
    mDate DATE
);

CREATE TABLE buytbl (
    num INT AUTO_INCREMENT PRIMARY KEY,
    userID CHAR(8),
    prodName NCHAR(6),
    groupName NCHAR(4),
    price INT,
    amount SMALLINT
);

insert into usertbl values('LSG', '이승기', 1987, '서울', '011', '11111111', 182, '2008-8-8');
insert into usertbl values('KBS', '김범수', NULL, '경남', '011', '22222222', 173, '2012-4-4');
insert into usertbl values('KKH', '김경호', 1871, '전남', '019', '33333333', 177, '2007-7-7');
insert into usertbl values('JYP', '조용필', 1950, '경기', '011', '44444444', 166, '2009-4-4');
insert into buytbl values(null, 'KBS', '운동화', null, 30, 2);
insert into buytbl values(null, 'KBS', '노트북', '전자', 1000, 1);
insert into buytbl values(null, 'JYP', '모니터', '전자', 200, 1);
insert into buytbl values(null, 'BBK', '모니터', '전자', 200, 5);

# 제약조건 생성
alter table usertbl 
	add constraint PK_usertbl_userID 
    primary key (userID);

# 외래키 설정 (오류지우고 설정)
delete from buytbl where userID = 'BBK';

alter table buytbl 
	add constraint FK_usertbl_userID 
     foreign key(userID) references usertbl(userID) on update cascade;
     
# BBK 정보 다시 입력
insert into buytbl values(null, 'BBK', '모니터', '전자', 200, 5);

# 잠시 외래키를 비활성화 & 입력
set foreign_key_checks = 0;
insert into buytbl values(null, 'BBK', '모니터', '전자', 200, 5);
set foreign_key_checks = 1;

# 회원 테이블에 입력
insert into usertbl values('BBK', '바비킴', 1973, '서울', '010', '00000000', 176, '2013-5-5');

# 체크제약조건
alter table usertbl
	add constraint CK_birthYear check (birthYear >= 1990 
    and birthYear <= year(curdate()));
    
# 바비킴 회원 아이디 변경
set foreign_key_checks = 0;
update usertbl set userID = 'VVK' where userID = 'BBK';
set foreign_key_checks = 1;

# 구매테이블의 물품 배송을 위해 회원 테이블과 조인
select B.*, U.* from buytbl B
	inner join usertbl U on B.userID = U.userID;
    
# 구매 테이블 기준 외부조인
select B.userID, name, B.prodName, U.addr, U.mobile2 as '연락처'
	from buytbl B left outer join usertbl U on B.userID = U.userID;
    
# 다시 원상복귀(bbk로)
update usertbl set userID = 'BBK' where userID = 'VVK';

select * from usertbl;
select * from buytbl;

# 구매 테이블 기준 외부조인 다시 췍췍
select B.userID, name, B.prodName, U.addr, U.mobile2 as '연락처'
	from buytbl B left outer join usertbl U on B.userID = U.userID;
    
# 그래도 모두 바꾸기 바랄 때
alter table buytbl drop foreign key FK_usertbl_userID;
alter table buytbl add constraint FK_usertbl_buytbl
	foreign key(userID) references usertbl(userID)
	on update cascade;
    
# vvk 변경
update usertbl set userID = 'VVK' where userID = 'BBK';

select * from usertbl;
select * from buytbl;

# 내부 조인 확인
select B.*, U.* from buytbl B
	inner join usertbl U on B.userID = U.userID;
    
# VVK 탈퇴 시
# 기준 테이블 행 삭제 시 외래 키 데이블의 연고나 행 데이터 함께 삭제 후 탈퇴
alter table buytbl drop foreign key FK_usertbl_buytbl;
alter table buytbl add constraint FK_usertbl_buytbl
	foreign key(userID) references usertbl(userID)
	on update cascade
    on delete cascade;

delete from usertbl where userID = 'VVK';

# 회원 데이블에서 확인
select * from usertbl;