/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:17:43 by aobshatk          #+#    #+#             */
/*   Updated: 2025/02/24 09:06:32 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	p_list	*stack_a;
	p_list	*stack_b;
	p_list	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (!init_stack(argc,argv, &stack_a))
		return (1);
	split_stack(&stack_a, &stack_b);
	temp = stack_a;
	while (temp)
	{
		printf("stack a %d\n", temp->value);
		temp = temp->next;
	}
	if (stack_a)
		clear_list(&stack_a);
	if (stack_b)
		clear_list(&stack_b);
	return (0);
}
