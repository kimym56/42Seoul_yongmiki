/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:34:24 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/19 16:58:32 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_complete *game, int i, int j);

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->playerfirst;
	j = game->playersecond;
	if (movement == 13)
	{
		if (game->map[--j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Number of movements: %i\n", game->counter);
	printf("Item Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->playerfirst;
	j = game->playersecond;
	if (movement == 0)
	{
		if (game->map[j][--i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[j][++i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Number of movements: %i\n", game->counter);
	printf("Item Left: %i\n", game->collectables);
	return (1);
}

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("You Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = keyboard_w_s(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
