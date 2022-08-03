/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:13:50 by yongmiki          #+#    #+#             */
/*   Updated: 2022/08/03 19:09:30 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_dir(void)
{
	if (player.dir_symb == 'S')
	{
		player.dir_y = 1;
		player.plane_x = -0.71;
	}
	else if (player.dir_symb == 'N')
	{
		player.dir_y = -1;
		player.plane_x = 0.71;
	}
	else if (player.dir_symb == 'E')
	{
		player.dir_x = 1;
		player.plane_y = 0.71;
	}
	else if (player.dir_symb == 'W')
	{
		player.dir_x = -1;
		player.plane_y = -0.71;
	}
}
