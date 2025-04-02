/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:06:00 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/01 20:57:39 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*static int	scale_factor(t_coord *coords)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (coords)
	{
		coords = coords->next;
		i++;
	}
	if (i <= 20)
		return (20);
	if (i > 20 && i <= 50)
		return (10);
	if (i > 50 && i <= 200)
		return (5);
	return (res);
}*/

static void	add_pix(t_coord *coords, t_step_coord *res, int **colors, int **z_matrix)
{
	char	**spltd;
	char	**spltdx;
	int	i;

	i = 0;
	res->width = arr_len(coords->heights);
	*colors = malloc(sizeof(int) * (res->width));
	*z_matrix = malloc(sizeof(int) * (res->width));
	while(i < res->width)
	{
		if (ft_strchr((coords->heights)[i], 'x'))
		{
			spltd = ft_split((coords->heights)[i], ',');
			spltdx = ft_split(spltd[1], 'x');
			(*colors)[i] = atob(spltdx[1]);
			(*z_matrix)[i] = ft_atoi(spltd[0]);
		}
		else
		{
			(*colors)[i] = 16777215;
			(*z_matrix)[i] = ft_atoi((coords->heights)[i]);
		}
		i++;
	}
}

t_step_coord	create_coords(t_coord *coords)
{
	t_step_coord	res;
	t_coord	*temp;
	int	height;
	int	i;

	temp = coords;
	i = 0;
	while (temp)
	{
		height = temp->y;
		temp = temp->next;
	}
	res.height = height;
	printf("height %d\n", height);
	res.colors = malloc(sizeof(int *) * (height + 1));
	res.z_matrix = malloc(sizeof(int *) * (height + 1));
	(res.colors)[height] = NULL;
	(res.z_matrix)[height] = NULL;
	while (coords)
	{
		add_pix(coords, &res, &((res.colors)[i]), &((res.z_matrix)[i]));
		i++;
		coords = coords->next;
	}
	return (res);
}
