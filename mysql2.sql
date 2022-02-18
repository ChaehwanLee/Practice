# JOIN

# 1. INNER JOIN
SELECT e.empname, d.deptname, t.titlename FROM emp e
INNER JOIN dept d
ON e.deptno = d.deptno
INNER JOIN title t
ON e.titleno = t.titleno;

SELECT e.empname, d.deptname, t.titlename, e.salary FROM emp e
INNER JOIN dept d
ON e.deptno = d.deptno
INNER JOIN title t
ON e.titleno = t.titlenoWHERE e.salary > 3000 
ORDER BY e.empname;

SELECT d.deptname, AVG(salary) FROM emp e
INNER JOIN dept dON e.deptno = d.deptno
INNER JOIN title tON e.titleno = t.titleno
GROUP BY d.deptname;

SELECT t.titlename, AVG(salary) FROM emp e
INNER JOIN dept d
ON e.deptno = d.deptno
INNER JOIN title t
ON e.titleno = t.titleno
GROUP BY t.titlename;

SELECT t.titlename, AVG(salary) AS av FROM emp e
INNER JOIN title t
ON e.titleno = t.titleno
GROUP BY t.titlename
HAVING av > 4000;

=====
# 부서별 사원과 대리의 연봉 평균을 구하시오
#SELECT * FROM emp e
#INNER JOIN dept d
#ON e.deptno = d.deptno
#INNER JOIN title t
#ON e.titleno = t.titleno;

# 부서별 사원과 대리의 연봉 평균을 구하시오
SELECT d.deptname, AVG(e.salary) AS av FROM emp e
INNER JOIN dept d
ON e.deptno = d.deptno
INNER JOIN title t
ON e.titleno = t.titleno
WHERE t.titleno IN (10,20)
GROUP BY d.deptname;
=====

# 2. OUTTER JOIN

#INSERT INTO emp VALUES ('9999',NULL,NULL,'이신입',NULL,3000,'2022-01-01');
#INSERT INTO emp VALUES ('9998',NULL,NULL,'김신입',NULL,3000,'2022-01-01');

#INSERT INTO title VALUES('50','고문');

#SELECT * FROM emp e
#INNER JOIN title t
#ON e.titleno = t.titleno;

INSERT INTO emp VALUES ('9999',NULL,NULL,'이신입',NULL,3000,'2022-01-01');
INSERT INTO emp VALUES ('9998',NULL,NULL,'김신입',NULL,3000,'2022-01-01');

INSERT INTO title VALUES('50','고문');

SELECT * FROM emp e
LEFT JOIN title t #LEFT 또는 RIGHT
ON e.titleno = t.titleno;


# 3. SELF JOIN

# 사원정보를 조회한다. 사원의 mgr의 이름 정보도 조회한다.
SELECT e.empname, m.empname FROM emp e 
# 사원과 매니저 별도로 다른 테이블이라고 생각하자 그러나 하나의 테이블 안에서 동작하므로 셀프조인
INNER JOIN emp m
ON e.manager = m.empno;

SELECT e.empname, m.empname FROM emp e 
LEFT JOIN emp m
ON e.manager = m.empno;
#self join 을 하면서 outer join 이 필요한 상황