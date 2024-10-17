/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:15:23 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/17 14:22:58 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	n;

	n = 1;
	result = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (n < nb)
	{
		result = result * n;
		n++;
	}
	return (result);
}
