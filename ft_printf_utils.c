/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:08:57 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/11 17:27:29 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(*str)
	{
		str ++;
		i ++;
	}
	return(i);
}

int ft_putchar(char c) //%c
{
	return(write(1,&c,1));
}

int ft_putstr(char *str) //%s
{
	if(str)
		write(1,str,ft_strlen(str));
	else
	{
		write(1,"(null)",6);
		return(6);
	}
	return(ft_strlen(str));
}

int ft_countnbr(int nbr)
{
	int len;
	
	len = 0;
	if (nbr <= 0)
		len ++;
	while (nbr)
	{
		len ++;
		nbr = nbr / 10;
	}
	return(len);
}

int	ft_putsignednbr(int n) //%i && %d
{
	int len;
	
	len = ft_countnbr(n);
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n *= -1;
		}
		if (n > 9)
		{
			ft_putsignednbr (n / 10);
		}
		ft_putchar ((n % 10) + '0');
	}
	return(len);
}

int	ft_putunsignednbr(unsigned int n) //%u
{
	int len;
	
	len = ft_countnbr(n);
	if (n > 9)
	{
		ft_putunsignednbr (n / 10);
	}
	ft_putchar ((n % 10) + '0');
	return(len);
}