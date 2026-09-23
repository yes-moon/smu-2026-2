# 데이터베이스

MySQL로 SQL을 익히고 Python(pymysql)으로 연동하는 과목.

환경: MySQL 8.0, Python 3.12 + pymysql · pandas · matplotlib

## 실습 기록

| 파일 | 차시 | 내용 |
|---|---|---|
| `practice/ch01_test_db.sql` | 1차시 | DB 생성, 테이블 생성, INSERT, SELECT — MySQL 첫 실습 |
| `practice/ch03_shopping_mall_queries.sql` | 2차시 | 쇼핑몰 DB(5개 테이블, FK 관계)에서 WHERE / AND 조건 검색 |
| `practice/ch04_group_join_queries.sql` | 3차시 | 집계 함수와 GROUP BY, 테이블 2~3개 조인, DATE_FORMAT |

쇼핑몰 DB 스키마와 Python 그래프 예제, 워크북 판매 DB 스크립트는 수업 배포 자료라 저장소에 포함하지 않았다.

## 배운 것

- `CREATE DATABASE` → `USE` → `CREATE TABLE` → `INSERT` → `SELECT` 흐름
- 조건 검색: 필터 컬럼이 있는 테이블에서 `WHERE`로 먼저 거르고, 다른 테이블 정보가 필요할 때만 `JOIN`
- 외래키(FK)로 테이블 간 관계 표현 — customers ← orders ← order_items → products → categories
- "~별로"는 `GROUP BY`, 여러 행을 한 줄로 합친다. 같은 값끼리 모아서 보기만 하는 `ORDER BY`와 다르다
- 두 테이블에 같은 이름의 컬럼이 있으면 `테이블.컬럼`으로 소속을 밝혀야 한다 (안 하면 ambiguous 에러)
- 값의 일부만 맞는 조건은 `=`가 아니라 `LIKE '서울%'`
- 관계 대수 용어와 SQL의 대응 — 셀렉트(σ)는 행 고르기(WHERE), 프로젝트(π)는 열 고르기(SELECT 목록)
