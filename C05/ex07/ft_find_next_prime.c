/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:33:54 by aobshatk          #+#    #+#             */
/*   Updated: 2024/10/19 11:51:29 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	check_num;

	check_num = nb - 2;
	if (nb <= 1)
		return (0);
	while (check_num > 0)
	{
		if (nb % check_num == 0 && check_num != 1)
			return (0);
		check_num -= 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	divider;

	divider = 2;
	if (ft_is_prime(nb))
		return (nb);
	nb = ft_find_next_prime(nb + 1);
	while (divider < nb)
	{
		if (nb % divider == 0)
			break ;
		divider++;
	}
	if (divider == nb)
		return (nb);
	return (nb);
}

/*int	main(int argc, char *argv[])
{
	int result = ft_find_next_prime(atoi(argv[1]));
	printf("%d\n", result);
	return(0);
}*/
