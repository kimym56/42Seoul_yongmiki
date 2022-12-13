/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:13:05 by yongmiki          #+#    #+#             */
/*   Updated: 2022/08/03 21:14:43 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_textures(void)
{
	texture_load(map.fd_ea, &win.east);
	texture_load(map.fd_so, &win.south);
	texture_load(map.fd_no, &win.north);
	texture_load(map.fd_we, &win.west);
	texture_to_array(&win.east, win.east_pixels);
	texture_to_array(&win.west, win.west_pixels);
	texture_to_array(&win.south, win.south_pixels);
	texture_to_array(&win.north, win.north_pixels);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = (t_vars){0};
	win.height = HEIGHT;
	win.width = WIDTH;
	if (argc != 2)
		ft_exit(1);
	if (!is_valid(argv[1]))
		ft_exit(2);
	parse(argv[1]);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.width, win.height, "cub3D");
	win.data.img = mlx_new_image(win.mlx, win.width, win.height);
	win.data.addr = mlx_get_data_addr(
			win.data.img, &win.data.bpp, &win.data.length, &win.data.endian);
	load_textures();
	mlx_loop_hook(win.mlx, on_loop, &vars);
	mlx_hook(win.win, E_DESTROY_NOTIFY, 0, on_close, NULL);
	mlx_hook(win.win, E_KEY_PRESS, M_KEY_PRESS, on_key_press, NULL);
	mlx_hook(win.win, E_KEY_RELEASE, M_KEY_RELEASE, on_key_release, NULL);
	mlx_loop(win.mlx);
	cleanup();
	return (0);
}
