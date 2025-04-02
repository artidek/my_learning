/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:17:34 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/01 22:25:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_pix	check_xy(t_pix xy)
{
	int temp;

	if (xy.x > xy.x1 || xy.y > xy.y1)
	{
		temp = xy.x;
		xy.x = xy.x1;
		xy.x1 = temp;
		temp = xy.y;
		xy.y = xy.y1;
		xy.y1 = temp;
	}
	return (xy);
}

static void	draw_line_h(t_pix xy, t_addr *addr, int dx, int dy)
{
	int	p;
	int	i;
	int	dir = dy < 0 ? -1 : 1;
	int	y;

	y = xy.y;
	dy *= dir;
	p = 2 * dy - dx;
	for (i = 0; i <= dx; i++)
	{
		mlx_pixel_put(addr->mlx, addr->win, xy.x + i, y, xy.color);
		if (p >= 0)
		{
			y += dir;
			p -= 2 * dx;
		}
		p += 2 * dy;
	}
}

static void	draw_line_v(t_pix xy, t_addr *addr, int dx, int dy)
{
	int	p;
	int	i;
	int	dir = dx < 0 ? -1 : 1;
	int	x;

	x = xy.x;
	dx *= dir;
	p = 2 * dx - dy;
	for (i = 0; i <= dy; i++)
	{
		mlx_pixel_put(addr->mlx, addr->win, x, xy.y + i, xy.color);
		if (p >= 0)
		{
			x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;
	}
}

void	draw_line(t_pix xy, t_addr *addr)
{
	if (abs(xy.x1 - xy.x) > abs(xy.y1 - xy.y))
	{
		xy = check_xy(xy);
		draw_line_h(xy, addr, xy.x1 - xy.x, xy.y1 - xy.y);
	}
	else
	{
		xy = check_xy(xy);
		draw_line_v(xy, addr, xy.x1 - xy.x, xy.y1 - xy.y);
	}
}
