/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:11:33 by yongmiki          #+#    #+#             */
/*   Updated: 2022/08/03 18:47:23 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	on_close(void)
{
	ft_exit(0);
	return (0);
}

int	on_key_press(int keycode)
{
	if (keycode == KEY_ESC)
		return (on_close());
	if (keycode == KEY_LEFT || keycode == KEY_A)
		player.move |= PLAYER_LEFT;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		player.move |= PLAYER_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W)
		player.move |= PLAYER_UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player.move |= PLAYER_DOWN;
	return (0);
}

int	on_key_release(int keycode)
{
	if (keycode == KEY_ESC)
		return (on_close());
	if (keycode == KEY_LEFT || keycode == KEY_A)
		player.move &= ~PLAYER_LEFT;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		player.move &= ~PLAYER_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W)
		player.move &= ~PLAYER_UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player.move &= ~PLAYER_DOWN;
	return (0);
}

int	on_loop(t_vars *vars)
{
	player_move();
	draw_rect(rect(0, 0, win.width, win.height), rgb(0, 0, 0));
	draw_rect(rect(0, 0, WIDTH, HEIGHT / 2), map.ceiling);
	draw_rect(rect(0, HEIGHT / 2, WIDTH, HEIGHT / 2), map.floor);
	raycaster(vars);
	do_sync();
	return (0);
}
