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

### mlx 관련
```C
void * mlx_init(void);
// - 나의 소프트웨어와 OS의 디스플레이를 연결해주는 함수.

void * mlx_new_window ( void mlx_ptr, int size_x, int size_y, char *title );
// - 디스플레이에 새로운 윈도우를 띄우는 함수. 앞서 받아온 포인터와 가로 세로 크기, 그리고 창의 제목을 받아서 띄운다.

int mlx_loop ( void *mlx_ptr );
// - 띄운 창에서 키보드와 마우스의 입력을 기다린다. 혹은 창의 일부를 다시 그리는 역할도 함

int	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
// - 위 세가지 함수는 모두 같은 방식으로 작동한다.
// - funct_ptr는 이벤트 발생시 당신이 호출하고 싶은 함수를 가리키는 함수 포인터 이다.
// - param의 주소는 호출될 때마다 전달되고 필요한 매개 변수를 저장하는 데 사용해야한다.
```