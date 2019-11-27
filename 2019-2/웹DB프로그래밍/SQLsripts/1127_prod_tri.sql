-- <Stored Procedure>-- 
use sqldb;
drop procedure if exists userProc;
delimiter $$
create procedure userProc()
begin 
	select * from userTBL; 
end $$ 
delimiter ;

call userProc();


# 매개변수 사용해서
use tabledb;
select * from usertbl;
drop procedure if exists userProc1;
delimiter $$
create procedure userProc1(IN userName varchar(10))
begin
	select * from userTBL where name = userName;
end $$ 
delimiter ;

call userProc1('김범수');

# 태어난 해가 입력한 연도보다 크고, 입력한 수치보다 키가 큰 사람 procedure
drop procedure if exists userProc2;
delimiter $$
create procedure userProc2(IN userbirthYear int, IN userHeight int)
begin
	select * from usertbl where birthYear > userbirthYear and height > userHeight;
end $$
delimiter ;

call userProc2(1980, 180);

# 인, 아웃이 있는 매개변수
drop procedure if exists userProc3;
delimiter $$
create procedure userProc3(
	IN txtValue char(10),
    OUT outValue int)
begin
	insert into testTBL values(null, txtValue);
    select max(id) into outValue from testtbl;
end $$
delimiter ;

CREATE TABLE IF NOT EXISTS testTBL (
    id INT AUTO_INCREMENT PRIMARY KEY,
    txt CHAR(10)
);

select * from testtbl;

call userProc3('테스트값', @myValue);
select concat('현재 입력된 ID 값 ==>', @myValue);

# 분기에 따른 프로시저
drop procedure if exists ifelseProc;
delimiter $$
create procedure ifelseProc(IN userName varchar(10))
begin
	declare bYear INT;
    select birthYear into bYear from usertbl
		where name = userName;
    if(bYear >=1980) then select '아직 젊군요..';
    else select '나이가 지긋하네요..';
	end if;
end $$
delimiter ;

call ifelseProc('이승기');

-- 트리거-- 
# after delete
create database if not exists testDB;
use testDB;
create table if not exists testtbl (id int, txt varchar(10));
insert into testtbl values(1, '이엑스아이디');
insert into testtbl values(2, '애프터스쿨');
insert into testtbl values(3, '에이오에이');

select * from testtbl;

drop trigger if exists testTrg;
delimiter //
create trigger testTrg
	after delete
    on testtbl
    for each row
begin
	set @msg = '가수 그룹이 삭제됨';
end //
delimiter ;

set @msg = '';

insert into testTBL values(4,'나인뮤지스');
select @msg;
update testtbl set txt = '에이핑크' where id =3;
select @msg;
delete from testtbl where id = 4;
select @msg;

# backup테이블 생성 및 트리거 생성
use tabledb;
CREATE TABLE backup_userTBL (
    userID CHAR(8) NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL,
    brithYear INT NOT NULL,
    addr CHAR(2) NOT NULL,
    mobile1 CHAR(3),
    mobile2 CHAR(8),
    height SMALLINT,
    mDate DATE,
    modType CHAR(2),	-- 변경 타입 (수정 or 삭제)
    modDate DATE,		-- 변경된 날짜
    modUser VARCHAR(256)		-- 변경한 사용자
);

# update하면 트리거 작동
drop trigger if exists backuptbl_updateTrg;
delimiter //
create trigger backuptbl_updateTrg
	after update
    on userTBL
    for each row
begin
	insert into backup_userTBL values(old.userID, old.name, old.birthYear, old.addr,
		old.mobile1, old.mobile2, old.height, old.mDate,
        '수정', curdate(), current_user());
end //
delimiter ;

update usertbl set name = '최희수' where userID = 'JYP';

select * from usertbl;
select * from backup_userTBL;

# delete 하면 트리거 작동 -> 삭제로 표시
drop trigger if exists backuptbl_deleteTrg;
delimiter //
create trigger backuptbl_deleteTrg
	after delete
    on userTBL
    for each row
begin
	insert into backup_userTBL values(old.userID, old.name, old.birthYear, old.addr,
		old.mobile1, old.mobile2, old.height, old.mDate,
        '삭제', curdate(), current_user());
end //
delimiter ;

delete from usertbl where name = '최희수';

select * from usertbl;
select * from backup_userTBL;

# 입력 되지 못하게 트리거
drop trigger if exists usertbl_insertTrg;
delimiter //
create trigger userTBL_InsertTrg
	after insert
    on usertbl
    for each row
begin
	signal sqlstate '45000'
		set message_text = '데이터의 입력을 시도했습니다. 귀하의 정보가 서버에 기록되었습니다.';
end //
delimiter ;

# befrore 테이블
drop trigger if exists userTBL_BeforeinsertTrg;
delimiter //
create trigger userTBL_BeforeinsertTrg
	before insert
    on userTBL
    for each row
begin
	if new.birthYear < 1900 then set new.birthYear = 0;
    elseif new.birthYear > year(curdate()) then set new.birthYear = year(curdate());
    end if;
end //
delimiter ;

insert into usertbl values('AAA', '에이', 1877, '서울', '011', '1112222', 181, '2019-12-25');
insert into usertbl values('BBB', '비이', 2977, '경기', '011', '1113333', 171, '2011-3-25');

select * from userTBL;
show triggers from tabledb;

# 중첩 테이블
drop database if exists triggerDB;
create database if not exists trggerdb;

use trggerdb;
drop table if exists orderTBL, prodTBL, deliverTBL;

CREATE TABLE IF NOT EXISTS orderTBL (
    orderNo INT AUTO_INCREMENT PRIMARY KEY,
    userID VARCHAR(5),
    prodName VARCHAR(5),
    orderamount INT
);

CREATE TABLE prodTBL (
    prodName VARCHAR(5),
    account INT
);

CREATE TABLE delivertbl (
    deliverNo INT AUTO_INCREMENT PRIMARY KEY,
    prodName VARCHAR(5),
    account INT UNIQUE
);

insert into prodTBL values('사과', 100);
insert into prodTBL values('배', 100);
insert into prodTBL values('귤', 100);

select * from prodTBL;

# 물품 테이블에서 개수슬 감소시키는 트리거
drop trigger if exists orderTrg;
delimiter //
create trigger orderTrg
	after insert
    on ordertbl
    for each row
begin
	update prodTBL set account = account - new.orderAmount
    where prodName = new.prodName;
end //
delimiter ;

# 배송 테이블에 새 배송 건을 입력하는 트리거
drop trigger if exists prodTrg;
delimiter //
create trigger prodTrg
	after update
    on prodTBL
    for each row
begin
	declare orderAmount int;
    set orderAmount = old.account - new.account;
    insert into deliverTBL(prodName, account) values(new.prodName, orderAmount);
end //
delimiter ;

insert into ordertbl values(null, 'JOHN', '배', 5);
select * from ordertbl;
select * from prodtbl;
select * from delivertbl;