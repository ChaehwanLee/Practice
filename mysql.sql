-- select 구문
/*
SQL 공부
*/

SELECT empno, empname, salary, salary / 12 AS 'monthly salary' FROM emp;
SELECT empno, empname FROM emp;
DESC emp;
SELECT * FROM emp WHERE empname = '킹'
SELECT * FROM emp WHERE salary > 3000;
SELECT * FROM emp WHERE DATE_FORMAT(hdate, '%YYYY') > '2000';

# 1월에 입사한 직원을 조회
SELECT * FROM emp WHERE DATE_FORMAT(hdate, '%m') = 01;
SELECT empname, DATE_FORMAT(hdate, '%Y%m%d') AS hdate FROM emp;
SELECT * FROM emp WHERE MONTH(hdate) = 01;
SELECT * FROM emp WHERE YEAR(hdate) = 2000;

SELECT * FROM emp;

# 월급이 4000~5000 인 직원을 조회 하시오
SELECT * FROM emp WHERE salary >= 4000 AND salary <= 5000;
SELECT * FROM emp WHERE salary BETWEEN 4000 AND 5000;

# deptno 가 10, 30, 40 인 직원을 조회하시오
SELECT * FROM emp WHERE deptno = 10 or deptno = 30 or deptno = 40;
SELECT * FROM emp WHERE deptno IN (10,30,40);
SELECT * FROM emp WHERE deptno NOT IN (20);

# 이씨를 조회
SELECT * FROM emp WHERE empname LIKE '이%';
SELECT * FROM emp WHERE empname LIKE '_영자';

# 서브 쿼리
# 이영자가 속한 부서원들을 조회 하시오
SELECT deptno FROM emp WHERE empname = '이영자';

SELECT * FROM emp 
WHERE deptno = (SELECT deptno FROM emp WHERE empname = '이영자');
AND salary >= 3000;


# titleno 가 30 번인 직원들의 deptno와 같은 직원들의 사번과 이름을 출력
SELECT deptno FROM emp WHERE titleno = 30;

SELECT empno, empname FROM emp 
WHERE deptno IN (SELECT deptno FROM emp WHERE titleno = 30);

SELECT * FROM emp ORDER BY deptno, empname;
SELECT * FROM emp ORDER BY 3, 4;

SELECT * FROM emp ORDER BY salary DESC;


SELECT DISTINCT(manager) FROM emp;

SELECT * FROM emp ORDER BY salary DESC LIMIT 1,3;

# CASE WHEN THEN
# salary가 4000이상이면 '상'출력 미만 이면 '하'출력
# 칼럼명은 grade로 출력
# 단, empname, salary, grade로 출력하시오

SELECT empname, salary,
CASE
WHEN salary >= 4000 THEN '상'
ELSE '하'
END
FROM emp;

# NULL CHECK
SELECT empno, manager FROM emp;
SELECT empno, IFNULL(manager, 'NONE') FROM emp;





# Group by
# 집계함수
# SUM, AVG, MIN, MAX

SELECT * FROM emp;

SELECT deptno, AVG(salary) FROM emp
GROUP BY deptno;
HAVING AVG(salary) > 4000
AND deptno = 30;

# 이말숙과 같은 부서 직원의 평균을 구하라

SELECT AVG(salary) FROM emp
GROUP BY deptno;
HAVING depetno = (SLECT deptno FROM emp WHERE mepname = '이말숙');

# 이말숙과 홍영자가 속한 부서의 연봉평균을 구하시오
# 단 부서명, 연봉 평균을 출력하시오

SELECT deptono, AVG(salary) AS avg FROM emp
GROUP BY deptno
HAVINg deptno IN
(SELECT dopno FROM emp WHERE empname IN ('이말숙','홍영자')
AND av > 3500;

# 직급 별 월급의 평균을 구하시오
SELECT titleno, AVG(salary), AVG(salary/12) FROM emp
GROUP BY titleno;

SELECT deptno, count(*) FROM emp
GROUP BY deptono;

# 우리회사 직급의 개수를 구하시오.
SELECT COUNT(DISTINCT(titleno)) FROM emp;

SELECT deptno, MIN(salary), MAX(salary) FROM emp;
GROUP BY deptno;

# 이영자가 속한 부서의 연봉 평균
#SELECT empname, AVG(salary) FROM emp
#WHERE deptno IN (SELECT deptno FROM emp WHERE empname='이영자');

# 이영자가 속한 부서의 연봉 평균보다 많이 받는 직원을 조회
SELECT * FROM emp
WHERE salary > (
SELECT AVG(salary) FROM emp
WHERE deptno IN (SELECT deptno FROM emp WHERE empname='이영자')
);



DROP TABLE itemtbl;
CREATE TABLE itemtbl(
id INT AUTO_INCREMENT PRIMARY KEY,
name VARCHAR(20),
price INT
);

ALTER TABLE itemtbl AUTO_INCREMENT = 1000;

INSERT INTO itemtbl VALUES (id,'pants2',20000);
SELECT * FROM itemtbl;

=====

DROP TABLE itemtbl;
CREATE TABLE itemtbl(
id INT AUTO_INCREMENT PRIMARY KEY,
name VARCHAR(20),
price INT
);

ALTER TABLE itemtbl AUTO_INCREMENT = 1000;

INSERT INTO itemtbl VALUES (id,'pants2',20000);
SELECT LAST_INSERT_ID();
SELECT * FROM itemtbl;

=====

DROP TABLE itemtbl;
CREATE TABLE itemtbl(
	id INT AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(20),
	price INT,
	regdate DATETIME
);

ALTER TABLE itemtbl AUTO_INCREMENT = 1000;

INSERT INTO itemtbl VALUES (id,'pants2',20000,NOW());

SELECT LAST_INSERT_ID();
SELECT id,name,DATE_FORMAT(regdate, '%y%m%d%h%i%s') FROM itemtbl;

UPDATE itemtbl SET NAME = 'shirts' WHERE id = 1000;




GROUP BY deptno;

SELECT * FROM emp
WHERE salary > (
SELECT AVG(salary) FROM emp
WHERE deptno IN (SELECT deptno FROM emp WHERE empname='이영자')
);

# CONCAT

SELECT CONCAT(titleno,'+',deptno,'+',empname,salary) FROM emp;

# 순위

SELECT ROW_NUMBER() OVER(ORDER BY salary), empname, salary FROM emp LIMIT 3;

SELECT ROW_NUMBER() OVER(ORDER BY salary), empname, salary FROM emp;

# JSON

SELECT JSON_OBJECT('name',empname, 'sal',salary) FROM emp;