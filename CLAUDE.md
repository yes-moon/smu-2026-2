# 2학년 2학기 과제 저장소

상명대학교 휴먼AI공학전공 2학년 2학기(2026-2) 수업의 실습 코드·과제·정리 노트. **공개 저장소**다.

## 작업 원칙

- 프로그램·코드·실습 방식은 **강의자료를 최우선**으로 따른다. 강의자료와 로컬 환경 버전이 다르면 차이만 짚어주고 강의자료 방식으로 간다.
- 코드는 넘기기 전에 반드시 실제로 실행해서 검증한다.
- 커밋하지 않는 것 (`.gitignore` 참고): 강의자료(pdf/pptx), 강의 녹음·녹취, 교수님 배포 코드, 학번이 들어간 파일, 비밀번호가 박힌 코드.
  - **예외:** 과제가 배포 코드 업로드를 명시적으로 요구하면 그 파일은 포함한다 (예: 인공지능개론 HW3 — ex3~ex5). `.gitignore`에 예외 사유를 주석으로 남길 것.
- 커밋 전 `git status`로 위 항목이 섞이지 않았는지 확인한다.
- **커밋 메시지에 AI 공동 작성자 서명(`Co-Authored-By: Claude …`)을 넣지 않는다.** 이 저장소는 과제 제출용으로 교수님께 링크를 드리므로, 사용자가 명시적으로 요청한 규칙이다. 메시지는 한 줄 요약 + 필요하면 본문, 사람이 쓴 것처럼 간결하게.

## 세션 프로토콜 — 노트북 ↔ 데스크탑 협업

두 기기의 Claude가 이 저장소를 통해 서로의 진행 상황을 공유한다. **반드시 지킬 것:**

**세션 시작**
1. `git pull` 을 먼저 실행한다.
2. `WORKLOG.md` 맨 위 항목을 읽는다. 상대 기기에서 한 일과 "다음 할 일"을 사용자에게 두세 줄로 요약해 준다.
3. 현재 기기 이름은 `CLAUDE.local.md`의 `기기:` 항목에서 읽는다. 파일이 없으면 사용자에게 묻고 만든다.

**세션 종료** (사용자가 "저장", "올려줘", "quit" 등을 말하면)
1. `WORKLOG.md` 맨 위에 새 항목을 추가한다 — `## 날짜 · 기기`, 한 일, 다음 할 일(체크리스트). 이전 항목의 완료된 체크박스는 `[x]`로 바꾼다.
2. `git status`로 제외 대상이 섞이지 않았는지 확인 → 커밋 → `git push`.
3. push 결과를 사용자에게 알린다.

**충돌 시** `WORKLOG.md`는 양쪽 항목을 모두 살린다(날짜순). 코드 충돌은 사용자에게 어느 쪽을 택할지 묻는다.

**pull이 "divergent branches"로 실패하면** 상대 기기가 히스토리를 다시 쓴 것이다 (WORKLOG 맨 위에 경고가 있을 것). 커밋 안 한 로컬 변경이 없으면 `git fetch origin` → `git reset --hard origin/main`. 있으면 `git stash` → reset → `git stash pop`.

## 데스크탑 최초 설정

1. `winget install Git.Git` → `winget install GitHub.cli` → 새 터미널에서 `gh auth login` (GitHub.com / HTTPS / Y / 브라우저)
2. `git config --global user.name "yes-moon"` / `git config --global user.email "yesmoon8663@gmail.com"` / `git config --global core.quotepath false`
3. `git clone https://github.com/yes-moon/smu-2026-2.git` (원하는 위치에)
4. 저장소 루트에 `CLAUDE.local.md` 를 만들고 `기기: 데스크탑` 과 학번을 적는다 (gitignore됨)
5. 강의자료 PDF/PPTX는 저장소에 없으므로 e-campus에서 받아 같은 과목 폴더에 넣는다
6. MATLAB R2025b + Statistics and Machine Learning Toolbox, MySQL 8.0, Python 3.12 설치

## 과목별 환경

| 과목 | 도구 | 비고 |
|---|---|---|
| 인공지능개론 | MATLAB R2025b + Statistics and Machine Learning Toolbox | 헤드리스 실행: `matlab -batch "스크립트명"` (창 없이 stdout으로 결과). 교수님은 R2026a |
| 데이터베이스 | MySQL 8.0, Python 3.12 + pymysql/pandas/matplotlib | 접속 `mysql -u root -p` |
| 빅데이터분석 | 강의 노트북 기준 Python 3.9 + PySpark 3.4.1 | 로컬은 3.12, pyspark 미설치 — 버전 차이 주의 |
| 알고리즘 | C (Visual Studio) | 강의 의사코드(1..n)를 C 배열(0..n-1)로 옮길 때 인덱스 주의 |

## 강의자료 읽는 법

PDF/PPTX는 대부분 이미지 슬라이드라 텍스트 추출이 비어 나온다. 빈 결과를 "내용 없음"으로 결론내지 말 것. PyMuPDF(`pymupdf`)로 페이지를 PNG로 렌더링해서 이미지로 읽는다. `.pptx`는 PowerPoint COM으로 PDF 변환 먼저.

## 제출 파일명 규칙

과제 파일은 `HW1_학번.m` 형식 — 반드시 문자로 시작해야 MATLAB 스크립트로 실행된다. 학번 파일은 로컬에만 두고, 저장소에는 학번을 뺀 `HW1.m` 사본을 둔다. 학번 등 로컬 전용 정보는 `CLAUDE.local.md`(gitignore됨)에 있다.
