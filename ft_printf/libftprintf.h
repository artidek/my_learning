/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:35 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/03 10:51:59 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct t_flags
{
	int	minus;
	int	plus;
	int	blank;
	int	hash;
	int	zero;
	int	width;
}		t_flags;

int		ft_check_width(char **temp, int counter);
int		ft_fnd_frmtr(char *pos, char *formats);
t_flags	ft_set_width(t_flags flags, char *format);
int		ft_print_format(char **format);
t_flags	ft_set_flags(t_flags flags, char *format);
void	ft_prt_arg(t_flags flags, va_list args, char *format, t_list *cargs);
void	ft_print_str(t_flags flags, void *args, t_list *cargs);
void	ft_print_char(t_flags flags, char args, t_list *cargs);
void	ft_print_decimal(t_flags flags, int args, t_list *cargs);
char	*ft_utoa(unsigned int n);
void	ft_print_uint(t_flags flags, unsigned int args, t_list *cargs);
void	ft_print_x(t_flags flags, unsigned int args, t_list *cargs);
char	*ft_btoa(long long unsigned int n, char *base);
void	ft_print_cx(t_flags flags, unsigned int args, t_list *cargs);
void	ft_print_pointer(t_flags flags, void *args, t_list *cargs);
void	ft_print_hex(t_flags flags, int size, char **result, char *args);
int		ft_printf(char *format, ...);
#endif
