/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:07:41 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/10 18:07:41 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while(s[len])
		len++;
	write(fd, s, sizeof(char) * len);
}
