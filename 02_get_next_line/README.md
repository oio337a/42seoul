# 주어진 버퍼만큼 파일을 읽고 한줄씩 출력하는 과제입니다.
---
이 과제는 주어진 버퍼만큼 파일을 읽고, 개행 (`\n`)을 만나게 되면 개행까지의 문자열을 출력하는 과제입니다.
버퍼만큼 읽던 중 개행을 만나게 되면 개행 전까지를 출력하고, 개행 이후 부터 남은 버퍼의 양만큼 읽은 값들은 정적변수에 저장하여 다음에 읽어들이는 버퍼에 추가해 주어 해결해여야 합니다.


## 사용 언어
C
## 학습내용
- `static` 변수
- fd(File Descriptor)가 무엇이고, 어떻게 사용할 수 있는가 read, open 함수
- 배열과 연결리스트의 차이와 장단점
- leaks 관리
- EOF의 의미와 사용
