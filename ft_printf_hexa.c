/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:08:55 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/11 17:30:10 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlower(unsigned long long n) 
{
	char hexadecimal[16];
	int reminder;
	int i;

	i = 0;
	if (n == 0)
		return(ft_putchar('0'));
	while (n > 0)
	{
		reminder = n%16;
		if (reminder >= 0 && reminder <= 9)
			hexadecimal[i] = reminder + 48;
		if (reminder >= 10 && reminder <= 15)
			hexadecimal[i] = reminder + 87;
		n = n/16;
		i ++;
	}
	hexadecimal[i] = '\0';
	while(i >= 0)
	{
		ft_putchar(hexadecimal[i]);
		i --;
	}
	return(ft_strlen(hexadecimal));
}

int	ft_hexupper(unsigned long long n) 
{
	char hexadecimal[16];
	int reminder;
	int i;

	i = 0;
	if (n == 0)
		return(ft_putchar('0'));
	while (n > 0)
	{
		reminder = n%16;
		if (reminder >= 0 && reminder <= 9)
			hexadecimal[i] = reminder + 48;
		if (reminder >= 10 && reminder <= 15)
			hexadecimal[i] = reminder + 55;
		n = n/16;
		i ++;
	}
	hexadecimal[i] = '\0';
	while(i >= 0)
	{
		ft_putchar(hexadecimal[i]);
		i --;
	}
	return(ft_strlen(hexadecimal));
}