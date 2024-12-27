/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:53:07 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/27 16:12:32 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int flg_hndl(char spec, char *format)
{
	//depends on format specifier convert it to the string, calculate strlen
	//check for flags and assign
	//if required check flag specifing field width strlen - field width if > 0 typing size = strlen + (strlen - field width)
	//send to print
}

int	frmt_hndl(va_list args, char *format, int move)
{
	int		i;
	int		counter;
	void	*val;
	int a;

	i = 0;
	counter = 0;
	a = move;
	while (a > 0)
	{
		while (g_formats[i])
		{
			if (g_formats[i] == format[a])
			{
				//go to flg_hndl(format[a], format)
			}
		}
	}
}

int	print_val(char *val)
{
	int	len;

	len = 0;
	if (!val)
		return (len);
	len = strlen(val);
	while (*val)
		write(1, &*val++, 1);
	return (len);
}

int	next_format(char *pos)
{
	int		counter;
	int		i;
	char	*temp;

	counter = 1;
	i = 0;
	temp = pos + 1;
	if (*pos == '%' && *temp != '%')
	{
		while (*pos == ' ' || *pos == '-' || *pos == '+' || *pos == '#'
			|| (*pos >= 48 && *pos <= 57))
		{
			pos++;
			counter++;
		}
		while (g_formats[i] && *pos)
		{
			if (*pos == g_formats[i])
				return (counter);
			i++;
		}
		return (0);
	}
	return (counter);
}

int	ft_printf(char *format, ...)
{
	int		counter;
	va_list	args;
	int		i;
	int		move;

	counter = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		move = next_format(&format[i]);
		if (move > 1)
			counter += frmt_hndl(args, &format[i], move);
		if (move == 1)
		{
			write(1, &format[i], 1);
			counter++;
		}
		if (move == 0)
			return (counter);
		i += move;
	}
	va_end(args);
	return (counter);
}

int	main(void)
{
	char			test[6] = "Hello";
	int				val;
	unsigned long int	pointer;

	ft_printf("Hello -y10s something else %s\n", test, test);
}
