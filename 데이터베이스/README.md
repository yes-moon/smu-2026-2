# 데이터베이스

MySQL로 SQL을 익히고 Python(pymysql)으로 연동하는 과목.

환경: MySQL 8.0, Python 3.12 + pymysql · pandas · matplotlib

## 실습 기록

| 파일 | 차시 | 내용 |
|---|---|---|
| `practice/ch01_test_db.sql` | 1차시 | DB 생성, 테이블 생성, INSERT, SELECT — MySQL 첫 실습 |
| `practice/ch03_shopping_mall_queries.sql` | 2차시 | 쇼핑몰 DB(5개 테이블, FK 관계)에서 WHERE / AND 조건 검색 |

쇼핑몰 DB 스키마와 Python 그래프 예제는 수업 배포 자료라 저장소에 포함하지 않았다.

## 배운 것

- `CREATE DATABASE` → `USE` → `CREATE TABLE` → `INSERT` → `SELECT` 흐름
- 조건 검색: 필터 컬럼이 있는 테이블에서 `WHERE`로 먼저 거르고, 다른 테이블 정보가 필요할 때만 `JOIN`
- 외래키(FK)로 테이블 간 관계 표현 — customers ← orders ← order_items → products → categories
