/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:33:01 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/19 02:22:15 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(t_complete *game)
{
	int	j;
	int	height;
	int	width;

	j = 0;
	height = 0;
	width = game->widthmap;
	while (j < width)
	{
		if (!(game->map[0][j] == '1'
			&& game->map[game->heightmap - 1][j] == '1'))
			return (0);
		j++;
	}
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	walls_valid(t_complete *game)
{
	int	walls;

	walls = check_wall(game);
	if (!walls)
	{
		printf("Error\nThis map is missing the walls\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("Error\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->itemcount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->itemcount > 0
			&& game->exitcount > 0))
	{
		printf("Error\nSomething is wrong,\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	walls_valid(game);
	character_valid(game);
}
