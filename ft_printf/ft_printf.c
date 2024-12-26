/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:53:07 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/26 23:32:16 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	print_arg(va_list args, char *format, int pos)
{
	int	i;
	int	counter;
	char *val;

	i = 0;
	counter = 0;
	//format += pos;
	while (g_formats[i].key)
	{
		if (g_formats[i].key == *format && *format == 's')
		{
			val = va_arg(args, char *);
			counter += print_val(val);
		}
		i++;
	}
	return (counter);
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
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (*pos == ' ' || *pos == '-' || *pos == '+' || *pos == '#'
		|| (*pos >= 48 && *pos <= 57))
	{
		pos++;
		counter++;
	}
	while (g_formats[i].key && *pos)
	{
		if (*pos == g_formats[i].key)
			return (counter += 1);
		i++;
	}
	
	return (NULL);
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
		if (format[i] == '%' && format[i + 1] != '%')
			move = next_format(&format[i + 1]);
		else
			write(1, &format[i], 1);
		if (move > 0)
		{
			counter += print_arg(args, &format[i + 1], move);
			i += move;
			move = 0;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

int	main(void)
{
	char	test[6] = "Hello";

	ft_printf("Hello %-y10s something else %s\n", test, test);
}
