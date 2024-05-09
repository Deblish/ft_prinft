/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:59:39 by aapadill          #+#    #+#             */
/*   Updated: 2024/05/09 20:18:32 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	char ch;

	ch = 'a';
	ft_printf("%c, %i, %s, %x, %X", ch, 214, "amosaver", 121121, 121121);
	write(1, "\n", 1);
	//printf("%c, %i, %s, string2: %s", ch, 2147483649, "amosaver", "segundo string");
	return 0;
}
