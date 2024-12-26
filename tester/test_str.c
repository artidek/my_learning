/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:13:54 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/25 10:56:22 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <signal.h>
void handle_sigsegv (int sig)
{
	freopen("output.txt", "a+", stdout);
	printf("Segmentation fault\n");
	fclose(stdout);
}

int	main(void)
{
	signal(SIGSEGV, handle_sigsegv);
	pid_t pid = fork();

	if (pid == 0)
	{
		//pass empty pointer
		char *ptr;
		printf("%s\n", ptr);
		//pass just char without format
		char c = 'a';
		printf(c);
		exit(0);
	}
	else
	{
		freopen("output.txt", "a+", stdout);
		// pass just string without format
		char str[13] = "Hello, World";
		printf(str);
		printf("\n");
		//pass string without pointer
		printf("string\n");
		//pass empty string
		char *empty = "";
		printf("%s\n", empty);
		//pass two strings without format
		char str1[6] = "hello";
		char str2[6] = "world";
		printf(str1, str2);
		printf("\n");
		//pass format string
		printf("test\n");
		//pass three strings with format
		printf("%s %s %s\n", str1, str2, "string");
		//pass string with all 0
		char nl[5] = {0, 0, 65, 0};
		printf("%s\n", nl);
		printf("\n");
		//pass series of chars
		printf("%c %c %c %c\n", 'a', 'b', 'c', 'd');
		//pass ascii nums include 8 bit ascii
		printf("%c %c %c %c %c\n", 68, 0 , 250, 33, 48);
		// pass address of a char without format
		char c = 'a';
		printf(&c);
		printf("\n");
		fclose(stdout);
		wait(NULL);
	}

	return (1);
}
