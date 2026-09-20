-- ch01 1차시 (2026-09-02) — MySQL 첫 실습
-- 접속: mysql -u root -p

-- 기본 DB 확인 (information_schema, mysql, performance_schema, sys)
SHOW DATABASES;

-- 실습용 DB 생성
CREATE DATABASE test;
SHOW DATABASES;
USE test;

-- 학생 테이블 생성
CREATE TABLE TEST (
    code INT,
    name VARCHAR(30),
    grade INT,
    department VARCHAR(50)
);

-- 데이터 삽입
INSERT INTO TEST VALUES (202411096, '김지수', 3, '휴먼AI공학전공');
INSERT INTO TEST VALUES (202510075, '이정민', 2, '게임전공');
INSERT INTO TEST VALUES (202611080, '김민수', 1, '휴먼AI공학전공');

-- 확인
SHOW TABLES;
SELECT * FROM TEST;
