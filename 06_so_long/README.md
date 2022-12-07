# so_long 구현
---

이 과제는 miniLibX를 사용하여 최소한의 움직임으로 모든 수집품을 모으고 탈출하는 2d게임을 만드는 것이 목표입니다.

## 사용 언어
C

## 학습내용
- 라이브러리 설치
- 키 hook
- images 사용해서 이미지 적용
- 파일 가져와서 맵 만들기
- 게임처럼 동작 하도록 만들기
- 에러 핸들링
- 누수 관리

### 컴파일

```
gcc -lmlx -framework OpenGL -framework AppKit main.c
```