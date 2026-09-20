-- ch03 2차시 (2026-09-09) — 쇼핑몰 DB 조건 검색
-- 전제: 수업에서 배포된 shopping_mall 스키마가 구축되어 있어야 함
--   customers(3) / categories(3) / products(7) / orders(3) / order_items(6)

USE shopping_mall;

-- 배송중인 주문의 고객 ID
SELECT customer_id
FROM orders
WHERE status = '배송중';
-- 결과: 2 (이영희)

-- 단가 50,000 이상이고 수량 1 이상인 주문 상세
SELECT *
FROM order_items
WHERE unit_price >= 50000 AND quantity >= 1;
-- 결과: 4건 (노트북 1,200,000 / 키보드 70,000 / 청바지 55,000 / 운동화 90,000)

-- 배운 점: 필터 컬럼이 있는 테이블에서 WHERE로 먼저 거르고,
-- 다른 테이블 정보(고객 이름, 상품 이름)가 필요할 때만 JOIN한다.
