-- ch04 3차시 (2026-09-23) — 집계·그룹화·조인
-- 전제: shopping_mall 스키마, 그리고 워크북 실습용 판매 DB(고객 7 / 제품 7 / 주문 10)

-- ────────────────────────────────────────────────
-- 1. shopping_mall — 조건 검색과 집계
-- ────────────────────────────────────────────────
USE shopping_mall;

-- 5만원 이상 10만원 미만 상품
SELECT product_name
FROM products
WHERE price < 100000 AND price >= 50000;
-- 결과: 키보드(70,000) / 청바지(55,000) / 운동화(90,000)

-- 10만원 이하 상품의 재고를 50으로 수정
UPDATE products
SET stock = 50
WHERE price <= 100000;
-- 6건 수정 (노트북 1,200,000만 제외)

-- 카테고리별 제품 수·총재고·최고가
SELECT category_id, COUNT(*) AS 제품수, SUM(stock) AS 총재고, MAX(price) AS 최고가
FROM products
GROUP BY category_id;

-- 카테고리별 평균 가격
SELECT category_id, AVG(price) AS 평균가격
FROM products
GROUP BY category_id;
-- 결과: 1번 435,000 / 2번 40,000 / 3번 65,000

-- 고객별 주문 배송상태 (주문 없는 고객은 제외됨)
SELECT o.customer_id, c.name, o.order_id, o.status
FROM orders o
JOIN customers c ON o.customer_id = c.customer_id
ORDER BY o.customer_id;

-- 주문 건별 총수량 — 수량은 orders가 아니라 order_items에 있다
SELECT order_id, SUM(quantity) AS 총수량
FROM order_items
GROUP BY order_id;

-- 날짜 형식 바꿔 출력 (ch04 DATE_FORMAT)
SELECT DATE_FORMAT(created_at, '%y/%m/%d') AS 일자,
       DATE_FORMAT(created_at, '%W')       AS 요일
FROM customers;

-- ────────────────────────────────────────────────
-- 2. 판매 DB (워크북) — 그룹화와 다중 테이블 조인
-- ────────────────────────────────────────────────
USE 판매;

-- 등급별 적립금 총액
SELECT 등급, SUM(적립금) AS 총적립금
FROM 고객
GROUP BY 등급;
-- 결과: gold 10,500 / vip 2,500 / silver 800

-- 제조업체별 제품 수와 재고량 합계
SELECT 제조업체, COUNT(*) AS 제품수, SUM(재고량) AS 총재고량
FROM 제품
GROUP BY 제조업체;
-- 결과: 대한식품 2/7,200 · 민국푸드 2/3,500 · 한빛제과 3/6,500

-- 배송지가 서울인 주문의 고객 이름과 제품 이름 (테이블 3개 조인)
SELECT 고객.고객이름, 제품.제품명
FROM 고객, 제품, 주문
WHERE 주문.배송지 LIKE '서울%'
  AND 고객.고객아이디 = 주문.주문고객
  AND 제품.제품번호 = 주문.주문제품;
-- 결과: 정소화 / 쿵떡파이 (마포구, 영등포구 2건)

-- 위와 같은 질의를 JOIN 문법으로
SELECT 고객.고객이름, 제품.제품명
FROM 주문
JOIN 고객 ON 고객.고객아이디 = 주문.주문고객
JOIN 제품 ON 제품.제품번호 = 주문.주문제품
WHERE 주문.배송지 LIKE '서울%';

-- 주문 고객별로 묶어서 보기 — 합치는 게 아니라 정렬
SELECT 주문.주문고객, 고객.고객이름, 제품.제품명
FROM 고객, 제품, 주문
WHERE 고객.고객아이디 = 주문.주문고객
  AND 제품.제품번호 = 주문.주문제품
ORDER BY 주문.주문고객;

-- 배운 점
-- · "~별로"는 GROUP BY, COUNT는 행 개수 / SUM은 값의 합.
-- · 여러 행을 한 줄로 합치는 GROUP BY와, 같은 값끼리 모아 보여주는 ORDER BY는 다르다.
-- · 테이블 두 곳에 같은 이름의 컬럼이 있으면 '테이블.컬럼'으로 소속을 밝혀야 한다(ambiguous 에러).
-- · 배송지처럼 값의 일부만 맞는 조건은 = 가 아니라 LIKE '서울%'.
-- · 테이블 N개를 이으려면 연결 조건은 N-1개 필요하다.
