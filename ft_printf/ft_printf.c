/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:53:07 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/06 21:15:24 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size(char *format, char *content)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (content == NULL)
		return (len += 1);
	len = (int)ft_strlen(content);
	if (content[0] == '\0' && *format == 'c')
		return (len += 1);
	return (len);
}

static int	print_result(char *format, t_list *args)
{
	int		len;
	int		move;
	char	*content;

	content = NULL;
	len = 0;
	if (!args)
		return (0);
	while (*format)
	{
		move = ft_fnd_frmtr(format, "cspdiuxX");
		if (move > 0)
		{
			args = args->next;
			if (args->content != NULL)
				content = (char *)args->content;
			len += size(format + move, content);
			write(1, content, size(format + move, content));
			format += move;
			format++;
		}
		else
			len += ft_print_format(&format);
	}
	return (len);
}

static void	del(void *ptr)
{
	if (ptr)
	{
		free((char *)ptr);
	}
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		move;
	int		len;
	t_list	*carg;

	len = 0;
	carg = ft_lstnew(NULL);
	va_start(args, format);
	while (format[len])
	{
		move = ft_fnd_frmtr(&format[len], "cspdiuxX");
		if (move > 0)
		{
			flags = ft_set_flags(&format[len + 1]);
			ft_prt_arg(flags, args, &format[len + move], carg);
			len += move;
		}
		len++;
	}
	va_end(args);
	len = print_result(format, carg);
	ft_lstclear(&carg, del);
	return (len);
}

/*int	main(void)
{
	int	val;
	int	val1;
	//char *null_str = NULL;
	//printf("%d\n", (int)sizeof(t_flags));
	//puts("0123456789");
	val = ft_printf("%.4d %.2d %.20d %.0d %.0d %.d %.d %.d\n", 127, 0, 1023, 0,
			(int)-2147483648, 0, 1, (int)-2147483648);
	printf("%d\n", val);
	val1 = printf("%.4d %.2d %.20d %.0d %.0d %.d %.d %.d\n", 127, 0, 1023, 0,
			(int)-2147483648, 0, 1, (int)-2147483648);
	//val1 = printf("%.1s", null_str);
	printf("%d\n", val1);
	//ft_printf("this is a %s\n", "test");
}*/
