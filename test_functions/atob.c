/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:28:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/29 19:28:56 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	base_val(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	atob(char *num)
{
	char	**spltd;
	int		res;
	int		hexval;
	int		i;

	res = 0;
	i = 0;
	spltd = ft_split(num, 'x');
	while (spltd[1][i])
	{
		hexval = base_val(spltd[1][i], "0123456789abcdef");
		res = res * 16 + hexval;
		i++;
	}
	return (res);
}
