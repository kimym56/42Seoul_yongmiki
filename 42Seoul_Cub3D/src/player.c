/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:15:03 by yongmiki          #+#    #+#             */
/*   Updated: 2022/08/03 21:15:09 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	player_rotate(void)
{
	double	old_dir_x;
	double	old_plane_x;
	double	sin_value;
	double	cos_value;

	if ((player.move & MOVE_LEFT) != 0)
	{
		sin_value = sin(-ROT_SPEED);
		cos_value = cos(-ROT_SPEED);
	}
	if ((player.move & MOVE_RIGHT) != 0)
	{
		sin_value = sin(ROT_SPEED);
		cos_value = cos(ROT_SPEED);
	}
	if ((player.move & MOVE_LEFT) != 0 || (player.move & MOVE_RIGHT) != 0)
	{
		old_dir_x = player.dir_x;
		player.dir_x = player.dir_x * cos_value - player.dir_y * sin_value;
		player.dir_y = old_dir_x * sin_value + player.dir_y * cos_value;
		old_plane_x = player.plane_x;
		player.plane_x = player.plane_x * cos_value - player.plane_y
			* sin_value;
		player.plane_y = old_plane_x * sin_value + player.plane_y * cos_value;
	}
}

void	player_move(void)
{
	if ((player.move & MOVE_UP) != 0)
	{
		player.x += player.dir_x * SPEED;
		player.y += player.dir_y * SPEED;
	}
	if ((player.move & MOVE_DOWN) != 0)
	{
		player.x -= player.dir_x * SPEED;
		player.y -= player.dir_y * SPEED;
	}
	player_rotate();
}
