/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:19:49 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/10 18:19:49 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while(s[len])
		len++;
	write(fd, s, sizeof(char) * len);
	write(fd, "\n", sizeof(char) * 1);
}
