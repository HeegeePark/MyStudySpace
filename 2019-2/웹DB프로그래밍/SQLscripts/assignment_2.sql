# 1. 구구단 프로시저
USE sqlDB;
DROP TABLE IF EXISTS guguTBL;
CREATE TABLE guguTBL (
    exp VARCHAR(100)
);
DROP PROCEDURE IF EXISTS guguProc;
DELIMITER $$
CREATE PROCEDURE guguProc()
begin 
	DECLARE str varchar(100);
    DECLARE i int;
    DECLARE j int;
    SET i=2;
    SET j=1;
    WHILE(i<10) DO
		SET str = ' ';
        WHILE(j<10) DO
			SET str = CONCAT(str,' ',i,'x',j,'=',i*j);
            SET j = j+1;
		END WHILE;
        SET i = i+1;
        SET j = 1;
    INSERT INTO guguTBL VALUE(str);
    END WHILE;
    SELECT exp AS '구구단' FROM guguTBL;
END $$ 
DELIMITER ;
CALL guguProc();


# 2. 테이블 만들고 트리거 생성
DROP DATABASE IF EXISTS assDB;
CREATE DATABASE assDB;
USE assDB;
-- (1) 제품 테이블 생성
DROP TABLE IF EXISTS prodTBL;
CREATE TABLE prodtbl (
    prodCode varchar(6) PRIMARY KEY NOT NULL,
    prodName VARCHAR(20),
    prodCompany VARCHAR(3),
    consumPrice INT,
    rmAmount INT
);

INSERT INTO prodtbl VALUES('D00001','SMART TV', 'LG', 1100000, 1);
INSERT INTO prodtbl VALUES('D00002','스피커', 'LG', 990000, 5);
INSERT INTO prodtbl VALUES('D00003','전기밥솥', '쿠쿠', 380000, 10);

SELECT 
    prodCode AS '상품코드',
    prodName AS '상품명',
    prodCompany AS '제조사',
    consumPrice AS '소비자가격',
    rmAmount AS '재고수량'
FROM
    prodTBL;


-- (2) 입고 테이블 생성
DROP TABLE IF EXISTS wrhTBL;
CREATE TABLE wrhTBL (
    wrhNum INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    prodCode VARCHAR(6) NOT NULL,
    wrhDate DATE,
    wrhAmount INT,
    rwhPrice INT
);

SELECT 
    wrhNum AS '입고번호',
    prodCode AS '상품코드',
    wrhDate AS '입고일자',
    wrhAmount AS '입고수량',
    rwhPrice AS '입고단가'
FROM
    wrhTBL;
    
-- (3) 새 물건이 입고되었을때, 제품 테이블의 재고 수량이 변경되는 트리거 생성
DROP TRIGGER IF EXISTS wrhTrg;
DELIMITER //
CREATE TRIGGER wrhTrg
	AFTER INSERT
    ON wrhTBL
    FOR EACH ROW
BEGIN
	UPDATE prodTBL SET rmAmount = rmAmount + NEW.wrhAmount
    WHERE prodCode = NEW.prodCode;
END //
DELIMITER ;

-- (4) SAMRT TV(단가 1000000) 10대가 19.10.21에 입고테이블에 삽입하여 트리거가 작동된 결과
INSERT INTO wrhTBL VALUES(NULL, 'D00001', '2019-10-21', 10, 1000000);

SELECT 
    wrhNum AS '입고번호',
    prodCode AS '상품코드',
    wrhDate AS '입고일자',
    wrhAmount AS '입고수량',
    rwhPrice AS '입고단가'
FROM
    wrhTBL;
    
SELECT 
    prodCode AS '상품코드',
    prodName AS '상품명',
    prodCompany AS '제조사',
    consumPrice AS '소비자가격',
    rmAmount AS '재고수량'
FROM
    prodTBL;
    
-- (5) 입고 테이블에서 물건 삭제 시, 제품 테이블의 재고 수량이 변경되는 트리거 생성
DROP TRIGGER IF EXISTS delTrg;
DELIMITER //
CREATE TRIGGER delTrg
	AFTER DELETE
    ON wrhTBL
    FOR EACH ROW
BEGIN
	UPDATE prodTBL SET rmAmount = rmAmount - OLD.wrhAmount
    WHERE prodCode = OLD.prodCode;
END //
DELIMITER ;

-- (6) 1번으로 입고되었던 물건 데이터 삭제 시 트리거 작동 결과
DELETE FROM wrhTBL WHERE wrhNum = 1;

SELECT 
    wrhNum AS '입고번호',
    prodCode AS '상품코드',
    wrhDate AS '입고일자',
    wrhAmount AS '입고수량',
    rwhPrice AS '입고단가'
FROM
    wrhTBL;
    
SELECT 
    prodCode AS '상품코드',
    prodName AS '상품명',
    prodCompany AS '제조사',
    consumPrice AS '소비자가격',
    rmAmount AS '재고수량'
FROM
    prodTBL;