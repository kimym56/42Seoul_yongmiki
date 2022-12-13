/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:06:51 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/19 01:52:37 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 64, height * 64);
	game->playersecond = height;
	game->playerfirst = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 64, height * 64);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor2.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall2.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player2.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit2.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item2.xpm", &i, &j);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = -1;
	while (++height < game->heightmap)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, width * 64, height * 64);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 64, height * 64);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 64, height * 64);
		}
	}
}
