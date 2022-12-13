/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:12:23 by yongmiki          #+#    #+#             */
/*   Updated: 2022/08/03 18:47:27 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_color	rgb(t_u8 r, t_u8 g, t_u8 b)
{
	return (rgba(r, g, b, FULL_OPACITY));
}

t_vector	vector(int x, int y)
{
	return ((t_vector){x, y});
}

t_fvector	fvector(float x, float y)
{
	return ((t_fvector){x, y});
}

t_rect	rect(int x, int y, int w, int h)
{
	return ((t_rect){x, y, w, h});
}
