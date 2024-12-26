/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:35 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/26 23:05:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>

# define MAX_SIZE 4096

int				print_val(char *val);
typedef int	*(*t_func_pntr)(void *);
typedef struct t_formats
{
	char		key;
	t_func_pntr	function;
}				t_formats;

const t_formats	g_formats[] = {{'s', print_val}, {'c', NULL}, {'d', NULL},{'\0', NULL}};

#endif
