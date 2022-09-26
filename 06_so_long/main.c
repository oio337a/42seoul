/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:24:51 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/24 20:05:24 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // printf()
#include <stdlib.h> // exit()
#include <mlx.h>

#define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
#define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값

#define KEY_W 13    // MacOS의 키보드 코드들이다.          
#define KEY_A 0     //
#define KEY_S 1     // 위에서 부터 차례대로
#define KEY_D 2     //
#define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.

typedef	struct s_param // 키 값을 입력 받고 정해진 동작을 수행했는지
{                      // 여부를 판단하기 위해 선언하였다.
	int x;               // x값
	int y;               // y값
} t_param;

void param_init(t_param *param) // 구조체 param 초기화 함수
{
	param->x = 0;
	param->y = 0;
}

int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
{                                                // 정의된 행동을 수행하는 함수
	if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
		param->x++;
	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
		param->x--;
	else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
		param->y++;
	else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
		param->y--;
	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	printf("(x, y): (%d, %d)\n", param->x, param->y); // param의 값 확인
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	t_param param;
	
	mlx_ptr = mlx_init();
	param_init(&param);
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "Hello, World!");
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param); // 키를 잡는 함수
	mlx_loop(mlx_ptr);
	return (0);
}
