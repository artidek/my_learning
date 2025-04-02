/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:16:21 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/02 22:54:26 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

/*static void rotate_z(t_pix *xy, float degrees) {
    t_pix temp;
    float angle;
    float x;
    float y;

    angle = degrees * (M_PI / 180.0);
    temp = *xy;

    // Rotate (x, y) around the z-axis
    x = (float)temp.x * cos(angle) - (float)temp.y * sin(angle);
    y = (float)temp.x * sin(angle) + (float)temp.y * cos(angle);
    xy->x = (int)round(x);
    xy->y = (int)round(y);

    x = (float)temp.x1 * cos(angle) - (float)temp.y1 * sin(angle);
    y = (float)temp.x1 * sin(angle) + (float)temp.y1 * cos(angle);
    xy->x1 = (int)round(x);
    xy->y1 = (int)round(y);
}

static void rotate_y(t_pix *xy, float degrees, float *z, float *z1)
{
	t_pix	temp;
	float	angle;
	float	x;
	float	x1;

	angle = degrees * (M_PI/180.0);
	temp = *xy;
	x = ((float)temp.x) * cos(angle) + (*z) * sin(angle);
	x1 = ((float)temp.x1) * cos(angle) + (*z1) * sin(angle);
	xy->x = (int)round(x);
	xy->x1 = (int)round(x1);
	*z = -((float)temp.x) * sin(angle) + (*z) * cos(angle);
	*z1 = -((float)temp.x1) * sin(angle) + (*z1) * cos(angle);
}

static void rotate_x(t_pix *xy, float degrees, float *z, float *z1)
{
	t_pix	temp;
	float	angle;
	float	y;
	float	y1;

	angle = degrees * (M_PI/180.0);
	temp = *xy;
	y = (float)temp.y * cos(angle) - (float)*z * sin(angle);
	y1 = (float)temp.y1 * cos(angle) - (float)*z1 * sin(angle);
	xy->y = (int)round(y);
	xy->y1 = (int)round(y1);
	*z = (float)temp.y * sin(angle) + (float)*z * cos(angle);
	*z1 = (float)temp.y1 * sin(angle) + (float)*z1 * cos(angle);
}*/

static float	scale_factor(int size, int len)
{
	float	res;

	res = (float)size / (float)len;
	if (res / 2.0 < 1)
		return (1.0);
	else
		return (res / 2.0);
}

static t_pix	isometric(t_pix xy, t_step_coord coord, float z, float z1)
{
	t_pix	temp;
	float	x;
	float	x1;
	float	y;
	float	y1;

	temp = xy;
	x = (float)(temp.x - temp.y) * cos(0.523599);
	x1 = (float)(temp.x1 - temp.y1) * cos(0.523599);
	y = (float)(temp.x + temp.y) * sin(0.523599) - z;
	y1 = (float)(temp.x1 + temp.y1) * sin(0.523599) - z1;
	xy.x = (int)round(x * scale_factor(640, coord.width));
    xy.x1 = (int)round(x1 * scale_factor(640, coord.width));
    xy.y = (int)round(y * scale_factor(480, coord.height));
    xy.y1 = (int)round(y1 * scale_factor(480, coord.height));
	xy.x += 640;
	xy.x1 += 640;
	xy.y += 480;
	xy.y1 += 480;
	return (xy);
}

static void	bresenham(t_pix xy, t_addr *addrs, t_step_coord coords)
{
	t_pix temp;
	float	z;
	float	z1;

	z = ((float)(coords.z_matrix)[xy.y][xy.x]);
	z1 = ((float)(coords.z_matrix)[xy.y1][xy.x1]);
	xy.color = (coords.colors)[xy.y][xy.x];
	//rotate_y(&xy, -30.0, &z, &z1);
	//rotate_x(&xy, 330.0, &z, &z1);
	temp = isometric(xy, coords, z, z1);
	//rotate_z(&temp, -30.0);
	draw_line(temp, addrs);
}

void	draw_map(t_addr *addrs, t_step_coord coords)
{
	t_pix	xy;
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < coords.height)
	{
		while (x < coords.width - 1)
		{
			xy.x = x;
			xy.x1 = x + 1;
			xy.y = y;
			xy.y1 = y;
			bresenham(xy, addrs, coords);
			xy.x = x;
			xy.x1 = x;
			xy.y = y;
			xy.y1 = y + 1;
			bresenham(xy, addrs, coords);
			x++;
		}
		x = 0;
		y++;
	}
}
