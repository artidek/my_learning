/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:35 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/27 15:34:55 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>

# define MAX_SIZE 4096

int			print_val(char *val);
const char	g_formats[] = {'s', 'c', 'd', 'p', 'i', 'u', 'x', 'X'};

#endif
