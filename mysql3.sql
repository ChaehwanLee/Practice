-- 실제로 사용되는 구문들

SELECT select_expr
    FROM table_references
    WHERE where_condition
    GROUP BY {con_name | expr | position}
    HAVING where_condition
    ORDER BY {col_name | expr | position}

SELECT 열이름
FROM 테이블이름
WHERE 조건

USE Employees; -- employees를 사용하겠다

USE mysql;
SELECT * FROM employees; -- employees 라는 테이블에서 선택을 하겠다.

SELECT * FROM titles; -- 선택, 모든열, 테이블/뷰 => titles테이블에서 모든 열의 내용을 가져오라

SELECT * FROM titles.employees; -- 테이블의 이름형식, 데이터베이스이름.테이블이름

SELECT first_name FROM employees; -- 필요로 하는 열만 가져오기 employees 테이블에서 first_name 행을 조회

-- 테이블이름(열 * 행)

SELECT f_name, l_name, s, FROM employees; -- 여러개의 열을 가져오는 것

-- 주석을 사용할 때는 -- 이후에 한 칸 띄우고 사용, 여러줄 주석 /* */ 으로 묶음

SELECT 필드이름 FROM 테이블이름 WHERE 조건식;

USE sqlDB;
SELECT * FROM userTable; -- userTalbe 에 모든 열을 가져오라고 하면 데이터가 너무 많을 수 있음

SELECT * FROM userTable WHERE name = '김사부'; -- userTable의 이름이 김사부 인 사람을 가져와라

SELECT * FROM userID, name FROM userTable WHERE byear >= 1960 AND height >= 170;
SELECT * FROM userID, name FROM userTable WHERE byear >= 1960 OR height >= 170;
