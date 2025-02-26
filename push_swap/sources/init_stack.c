/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:35:49 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:46:37 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_int(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (argv[j][i] == '-' && !ft_isdigit(argv[j][i + 1]))
				return (0);
			if (argv[j][i] != '-' && !ft_isdigit(argv[j][i])
				&& argv[j][i] != ' ')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

static long long int	extract_digit(char *stack)
{
	long long int	node_cont;

	node_cont = ft_atoil(stack);
	if (node_cont > INT_MAX || node_cont < INT_MIN)
	{
		write(2, "some arguments are bigger than integer", 39);
		return (LONG_MIN);
	}
	return (node_cont);
}

int	init_stack(int argc, char **argv, t_plist **stack_a)
{
	long long int	num;
	int				i;

	i = 1;
	if (!check_int(argv, argc))
		return (0);
	while (i < argc)
	{
		num = extract_digit(argv[i++]);
		if (num == LONG_MIN)
		{
			if (*stack_a)
				clear_list(stack_a);
			return (0);
		}
		append_node(stack_a, create_node((int)num));
	}
	return (1);
}
