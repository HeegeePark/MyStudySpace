create database assDB;
use assDB;

# 1 - (1) deptTBL 생성 및 데이터 삽입
select * from deptTBL;
CREATE TABLE deptTBL (
    DEPTNO INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    DNAME CHAR(2) NOT NULL,
    LOC CHAR(3) NOT NULL
);


INSERT INTO deptTBL VALUES(NULL, '회계', '서울');
INSERT INTO deptTBL VALUES(NULL, '기획', '경기');
INSERT INTO deptTBL VALUES(NULL, '영업', '서울');
INSERT INTO deptTBL VALUES(NULL, '개발', '제주도');
INSERT INTO deptTBL VALUES(NULL, '관리', '대전');

# 1 - (2) empTBL 생성
SELECT * FROM emptbl;
CREATE TABLE empTBL (
    EMPNO INT PRIMARY KEY NOT NULL,
    ENAME CHAR(2) NOT NULL,
    JOB CHAR(10) NOT NULL,
    MGR INT,
    HIREDATE DATE NOT NULL,
    SAL INT NOT NULL,
    COMM INT,
    DEPTNO INT NOT NULL,
    FOREIGN KEY (DEPTNO)
        REFERENCES deptTBL (DEPTNO)
);

INSERT INTO empTBL VALUES(7369, '영희', '회계사', '7902', '1980-12-17', 800, NULL, 1); 
INSERT INTO empTBL VALUES(7499, '상현', '영업사원', '7698', '1981-02-20', 1600, 300, 3); 
INSERT INTO empTBL VALUES(7521, '경희', '영업사원', '7698', '1981-02-22', 1250, 500, 3); 
INSERT INTO empTBL VALUES(7566, '혁신', '기획자', '7839', '1981-04-02', 2975, NULL, 2); 
INSERT INTO empTBL VALUES(7654, '정수', '영업사원', '7698', '1981-09-28', 1250, 1400, 3); 
INSERT INTO empTBL VALUES(7698, '성진', '매니저', '7839', '1981-05-01', 2850, NULL, 3); 
INSERT INTO empTBL VALUES(7782, '지현', '매니저', '7839', '1981-06-09', 2450, NULL, 1); 
INSERT INTO empTBL VALUES(7788, '현석', '분석가', '7566', '1987-06-28', 3000, NULL, 2); 
INSERT INTO empTBL VALUES(7839, '나라', '대표', NULL, '1981-11-17', 5000, NULL, 1); 
INSERT INTO empTBL VALUES(7844, '민지', '영업사원', '7698', '1981-09-08', 1500, 0, 3); 
INSERT INTO empTBL VALUES(7876, '필두', '기획보조', '7788', '1987-07-13', 1100, NULL,2); 
INSERT INTO empTBL VALUES(7900, '주혁', '회계사', '7698', '1981-12-03', 950, NULL, 3); 
INSERT INTO empTBL VALUES(7902, '윤희', '프로그래머', '7566', '1981-12-03', 3000, NULL, 4); 
INSERT INTO empTBL VALUES(7934, '송이', '프로그래머', '7782', '1982-01-23', 1300, NULL, 4); 

# 1 - (3) gradeTBL 생성
SELECT * FROM gradeTBL;
CREATE TABLE gradeTBL (
    GRADE INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    LOWSAL INT NOT NULL,
    HIGHSAL INT NOT NULL
);

INSERT INTO gradeTBL VALUES(NULL, 700, 1200);
INSERT INTO gradeTBL VALUES(NULL, 1201, 1400);
INSERT INTO gradeTBL VALUES(NULL, 1401, 2000);
INSERT INTO gradeTBL VALUES(NULL, 2001, 3000);
INSERT INTO gradeTBL VALUES(NULL, 3001, 9999);


# 2 - (1) 경희와 현석의 부서명 조회하기
SELECT E.ENAME AS '직원이름', D.DNAME AS '부서이름'
	FROM empTBL E
    INNER JOIN deptTBL D 
		ON E.DEPTNO = D.DEPTNO
	WHERE E.ENAME = '경희' OR E.ENAME = '현석';
    
# 2 - (2) 모든 직원들의 이름, 월급여, 월급여등급 조회
SELECT E.ENAME AS '직원이름', E.SAL AS '월급여', G.GRADE AS '월급여등급'
	FROM empTBL E
    RIGHT OUTER JOIN gradeTBL G
    ON E.SAL BETWEEN G.LOWSAL AND G.HIGHSAL;
    
# 2 - (3) 각 직원의 이름 및 해당 직속상사 이름 조회
SELECT E.ENAME AS '직원이름', M.ENAME AS '직속상사 이름'
	FROM empTBL E
    INNER JOIN empTBL M
    ON E.MGR = M.EMPNO;
    
# 2 - (4) 이름 및 부서명 조회 (모든 부서 조회)
SELECT E.ENAME AS '직원이름', D.DNAME AS '부서'
	FROM empTBL E
    RIGHT OUTER JOIN deptTBL D
    ON E.DEPTNO = D.DEPTNO;
    
# 2 - (5) 부서번호가 3인 직원들의 이름, 직급, 부서번호, 부서위치 조회
SELECT E.ENAME AS '직원이름', E.JOB AS '직급', D.DEPTNO AS '부서번호', D.LOC AS '부서위치'
	FROM empTBL E
    INNER JOIN deptTBL D 
		ON E.DEPTNO = D.DEPTNO
	WHERE E.DEPTNO = 3;
    
# 2 - (6) 커미션을 받는 직원의 이름, 커미션, 부서이름, 부서위치 조회
SELECT E.ENAME AS '직원이름', E.COMM AS '커미션', D.DNAME AS '부서이름', D.LOC AS '부서위치'
	FROM empTBL E
    INNER JOIN deptTBL D 
		ON E.DEPTNO = D.DEPTNO
	WHERE E.ENAME NOT IN (SELECT ENAME FROM empTBL WHERE COMM IS NULL OR COMM = 0);
    
# 2 - (7) 제주도에서 근무하는 직원이름, 직급, 부서번호, 부서명 조회
SELECT E.ENAME AS '직원이름', E.JOB AS '직급', D.DEPTNO AS '부서번호', D.DNAME AS '부서명'
	FROM empTBL E
    INNER JOIN deptTBL D 
		ON E.DEPTNO = D.DEPTNO
	WHERE D.LOC = '제주도';
    
# 2 - (8) 이름에 '현'자가 들어간 직원의 이름, 부서명 조회
SELECT E.ENAME AS '직원이름', D.DNAME AS '부서명'
	FROM empTBL E
    INNER JOIN deptTBL D 
		ON E.DEPTNO = D.DEPTNO
	WHERE E.ENAME LIKE '현%' OR E.ENAME LIKE '%현';