/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:28 by aobshatk          #+#    #+#             */
/*   Updated: 2025/04/03 13:04:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_coord			*coords;
	t_step_coord	s_coords;

	if (argc <= 1)
	{
		ft_printf("Map in .fdf format is required\n");
		return (1);
	}
	coords = init_list(argv[1]);
	if (!coords)
		return (1);
	s_coords = create_coords(coords);
	start_window(s_coords);
	free(s_coords.colors);
	free(s_coords.z_matrix);
	clear_list(&coords);
	return (0);
}
