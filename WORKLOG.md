# 작업 로그

노트북과 데스크탑을 오가며 작업하므로 **세션이 끝날 때마다 여기에 기록**한다. 최신 항목이 위.
세션을 시작하는 Claude는 `git pull` 후 이 파일의 맨 위 항목부터 읽고 상대 기기에서 무엇을 했는지 파악한다.

형식: `## 날짜 · 기기` → 한 일 / 다음 할 일

---

## 2026-09-20 · 데스크탑 (3차 세션)

**한 일**
- ⚠️ **노트북에 요청**: 인공지능개론 HW3 과제("강의자료 내 모든 KNN 실습 완성 → 깃허브 업로드 → 링크를 `HW3_KNN실습.txt`로 제출")를 위해 **ex3~ex5 kNN 파일을 `인공지능개론/`에 push** 해줄 것. 이 과제는 배포 코드를 올리라는 것이므로 "교수님 배포 코드 제외" 규칙은 이 폴더엔 적용하지 않음. README의 "저장소에는 없다" 문장도 수정. 제출 txt는 데스크탑 바탕화면에 만들어 둠(링크는 폴더 URL)
- 이 PC(`D:\대학과제`)에서 개발한 것들을 찾아 저장소 3개 신규 공개 — 학번·실명 전부 제거, 강의자료·교수님 배포 코드(`sorting/`) 제외
  - `game-voice-translator` — 개인 프로젝트, 실시간 게임 음성 번역 자막 (Python 1,100줄). README 재작성(파이프라인 다이어그램·설계 포인트)
  - `dragon-slayer-arena` — 인터랙션디자인 기말 Unity 게임. 직접 작성한 C# 18개·씬·설정만 포함(에셋스토어 패키지 제외), 스크린샷 2장, 발표 대본
  - `smu-2026-1` — 2학년 1학기: 자료구조 C 8개(MSVC 전부 컴파일 확인, `array_list.c` 미완성 switch 완성 + insert 경계 버그 수정), 객프 Java 5과제(노트북에서 .java 추출, javac 실행 확인), 데이터분석 노트북 4개(출력 비움)
- 프로필 README 전면 개편 — Projects/Coursework 분리, 기술 배지 확장, top-langs 카드. 저장소 4개에 topics 추가
- `CLAUDE.local.md`를 `기기: 데스크탑`으로 정정, `portfolio` 저장소 문서의 기기 라벨도 정정
- 전역 `core.autocrlf=input` 설정 (CRLF 경고 제거)

**다음 할 일**
- [ ] (사용자) GitHub 프로필에서 핀 고정 — API로 불가. Customize your pins → game-voice-translator · dragon-slayer-arena · portfolio · smu-2026-2 · smu-2026-1 · pygame-games
- [x] `dragon-slayer-arena` 플레이 영상 → 보스전 7초 GIF(3.8MB) + 전투/승리 스틸컷을 README에 추가
- [x] 인터디 zip(2.3GB) 확인 — 기말 제출본(기획안 PDF·영상·unitypackage)이라 새 코드 없음, 추가 안 함
- [ ] `코드읽기훈련` 폴더는 개인 학습 로그라 비공개 유지 — 공개할지 결정

---

## 2026-09-20 · 데스크탑

> 라벨 정정 (노트북 세션에서): 원래 "노트북 (2차 세션)"으로 기록됐으나 `D:\GITHUB\` 경로는 데스크탑 것 (노트북은 C:·G:만 있음). 데스크탑 Claude는 `CLAUDE.local.md`에 `기기: 데스크탑`을 만들어 둘 것.

**한 일**
- 실무 포트폴리오 저장소 `portfolio` 공개 — 회사 산출물 2차 검수(식별정보 삭제·치환·이미지 마스킹) 후 push. 상세는 그 저장소 `WORKLOG.md`
- 프로필 README Projects 표에 portfolio 행 추가
- 데스크탑 환경: gh CLI 설치·로그인, 전역 git 설정, 저장소 4개를 `D:\GITHUB\` 아래에 모음 (`portfolio`·`smu-2026-2`·`pygame-games`·`yes-moon`)

**다음 할 일**
- [ ] (노트북) `portfolio` 클론 후 README·스크린샷 꾸미기 — 그 저장소 WORKLOG 참고

---

## 2026-09-20 · 노트북

**한 일**
- GitHub 계정 `yes-moon` 생성, Git·gh 설치, 저장소 3개 공개
  - `smu-2026-2` (이 저장소) — 과목별 README, 실습 코드, SQL 연습 파일
  - `pygame-games` — 1학년 옷입히기·뱀 게임 정리, 경로 수정 후 실행 검증
  - `yes-moon` — 프로필 README
- 인공지능개론 3주차 kNN 실습: ex1·ex2 직접 작성, ex1~5 헤드리스 실행 검증 완료
- 노트북↔데스크탑 협업 프로토콜 구축 (이 파일 + CLAUDE.md). 이메일은 커밋 기록에 이미 있으므로 CLAUDE.md에 그대로 두기로 결정
- 세션 종료 시점에 사용자는 데스크탑으로 이동 → **다음 세션은 데스크탑에서 시작될 가능성 높음**

**다음 할 일**
- [ ] 인공지능개론 4주차 자료 나오면 읽고 실습
- [ ] 빅데이터분석 1주차 과제 — 커피 워드카운트에 SNS 5문장 추가 → 상위 5단어 표·그래프 → A4 1p 해석 보고서 (미착수)
- [ ] 데이터베이스 pymysql 과제(ch01 58~59쪽) 제출 여부 확인
- [ ] 알고리즘 `1.1 Sequential Search.c` main 완성, `1.2.c` 수정 (현재 컴파일 안 됨)
- [ ] GitHub 프로필 bio 설정 (웹 Settings → Profile)
- [ ] 데스크탑 최초 설정 (CLAUDE.md "데스크탑 설정" 참고)
