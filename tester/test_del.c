/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:03:05 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/25 19:40:51 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <signal.h>

void test_str ()
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
	fclose(stdout);
}

void test_str_fl ()
{
	freopen("output.txt", "a+", stdout);
	//pass empty pointer
	char *ptr;
	printf("%s\n", ptr);
	fclose(stdout);
}

void test_chr()
{
	freopen("output.txt", "a+", stdout);
	//pass series of chars
	printf("%c %c %c %c\n", 'a', 'b', 'c', 'd');
	//pass ascii nums include 8 bit ascii
	printf("%c %c %c %c %c\n", 68, 0 , 250, 33, 48);
	//pass series of chars
	printf("%c %c %c %c\n", 'a', 'b', 'c', 'd');
	//pass ascii nums include 8 bit ascii
	printf("%c %c %c %c %c\n", 68, 0 , 250, 33, 48);
	// pass address of a char without format
	char c = 'a';
	printf(&c);
	printf("\n");
	fclose(stdout);
}

void test_chr_fl()
{
	freopen("output.txt", "a+", stdout);
	char c;
	//pass just char without format
	printf(c);
	printf("\n");
	fclose(stdout);
}

void test_seq()
{
	freopen("output.txt", "a+", stdout);
	printf("fifth test\n");
	fclose(stdout);
}

void (*tests[])() = {test_str, test_str_fl, test_chr, test_chr_fl, test_seq};

void run_test (int index)
{
	pid_t  pid;

	if (pid = 0)
	{
		tests[index]();
		exit(0);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			int sig = WTERMSIG(status);
			if (sig == SIGSEGV)
				printf("segmentation fault");
		}
	}
}

int main()
{
	int tests = 5;
	int i = 0;
	
	while (i < tests)
		run_test(i);
	
	return (0);
}
