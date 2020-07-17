/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:16:50 by svet              #+#    #+#             */
/*   Updated: 2020/07/17 12:35:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	char *s = "";
	char str[31] = "-123456789 This is test";
	char *ptr;
	unsigned long ret;
	unsigned long max = NL_ARGMAX;
	// size_t l = INT_MAX;
	// int min = INT_MIN;
	//double a = -1;
	//free(p);
   //ret = strtoul(str, &ptr, 10);
   //printf("The number(long integer) is %hlhd\n", ret);
   //printf ("%#.0o",0);
   //printf("String part is |%s|", ptr);
   //min = INT_MAX;
   //printf("\n|%d|\n", -(ssize_t)l <= INT_MAX);
   //printf("\n%zu %zu %zu %zu\n", sizeof(unsigned int), sizeof(long), sizeof(long double), sizeof(void *));
   //printf("\n%10$d %9$d %8$d %7$d %6$d %5$d %4$d %3$d %2$d %1$d %11$d %12$d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, NL_ARGMAX);
	//#error "HELLO "
	printf("%9$lu", max, max, max);
	//printf("%1$*2$d", 5, 10);
	//long a = INT_MAX;
	//++a;
	//char *str = ft_strnew(++a);
	//ft_memset(str, 'A', a);
	
	

	//printf("[");
	//printf("]\n{%d}\n", printf("%.*d", INT_MIN, 3));

	//printf("%d", printf("%2147483647d %s", -10 < INT_MAX, "Hello"));
	return (0);
}
