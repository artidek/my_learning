/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:26:26 by aobshatk          #+#    #+#             */
/*   Updated: 2024/12/26 11:31:13 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h> 
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Test(string_test, test1)
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
	char long_str[4096];
	int i = 0;
	int a = 0;
	while(i < 4096)
	{
		if (a == 26)
			a = 0;
		long_str[i] = (char)65 + a;
		a++;
		i++;
	}
	printf("it is a very long string %s\n", long_str);
	char test[] = "Hello";
	printf("string\n", test); 
	printf("flag in caps %S\n", test);
	printf("\n");
	printf("some strings %s %s\n", str1);
	fclose(stdout);
}

Test(character_test, test2)
{
	freopen("output.txt", "a+", stdout);
	//pass series of chars
	printf("%c %c %c %c\n", 'a', 'b', 'c', 'd');
	//pass ascii nums include 8 bit ascii
	printf("l%c%c%cl%c%c\n", 68, 71 , 85, 33, 48);
	printf("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
	char c = 'a';
	printf(&c);
	printf("\n");
	printf("this is char %c\n", c);
	fclose(stdout);
}

Test(wrong_val3, sigsegv, .signal = SIGSEGV)
{
	printf("string with format no argument passed %s\n");
}

Test(wrong_val, sigsegv, .signal = SIGSEGV)
{
	char *ptr;
	printf("%s\n", ptr);
}

Test(wrong_val2, sigsegv, .signal = SIGSEGV)
{
	char c;
	//pass just char without format
	printf(c);
	printf("\n");
}
