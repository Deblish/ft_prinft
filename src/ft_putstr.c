/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:09 by aapadill          #+#    #+#             */
/*   Updated: 2024/05/10 16:01:32 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_putstr(const char *s, int *count)
{
	if (!s)
		return (-1);
	while (*s)
    {
		if (write(1, s++, 1))
            (*count)++;
        else
            return (-1);
    }
    return (1);
}