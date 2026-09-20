# 빅데이터분석

Python · NumPy · Spark로 데이터를 다루는 과목. 강의는 원리 설명, 실습은 노트북 자율 실행. 평가는 코드가 아니라 **결과 해석 보고서**(표·그래프 + 해석 + 제언, A4 1쪽).

환경: 강의 기준 Python 3.9 + PySpark 3.4.1 + Java

## 정리 노트

| 파일 | 내용 |
|---|---|
| `1주차_정리.md` | Python 기초와 함수형 프로그래밍(map/filter/reduce), NumPy 벡터화, Spark 개론, 환경 오류 대처 |

강의 노트북(`ds1_*.ipynb`)은 수업 배포 자료라 저장소에 포함하지 않았다.

## 배운 것

- `map` · `filter` · `reduce` — 반복문을 없애는 연산의 추상화. 요소별 처리가 독립적이라 분산 가능 → Spark의 map-reduce와 같은 사고방식
- NumPy 벡터화: 반복문 없이 배열 전체를 한 번에. Pandas · scikit-learn · PyTorch 모두 NumPy 위에 있다
- 환경 오류는 대부분 경로 문제 — `sys.path`, `PYTHONPATH`, 경로에 한글 금지
