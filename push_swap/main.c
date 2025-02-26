/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:17:43 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/26 19:36:47 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four(t_plist **stack_a, t_plist **stack_b)
{
	push(stack_a, stack_b, 'b');
	sort_three(stack_a);
	final_merge(stack_a, stack_b);
}

static void	sort_two(t_plist **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap('a', 1, stack_a);
}

int	main(int argc, char **argv)
{
	t_plist	*stack_a;
	t_plist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!init_stack(argc, argv, &stack_a))
		return (1);
	if (find_duplicates(stack_a))
		return (1);
	if (argc - 1 == 2)
		sort_two(&stack_a);
	if (argc - 1 == 3)
		sort_three(&stack_a);
	if (argc - 1 == 4)
		sort_four(&stack_a, &stack_b);
	if (argc - 1 > 4)
		split_stack(&stack_a, &stack_b);
	if (stack_a)
		clear_list(&stack_a);
	return (0);
}
