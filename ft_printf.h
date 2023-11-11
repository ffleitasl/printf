/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:09:01 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/11 17:30:14 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int ft_printf(char const *format, ...);

int ft_strlen(char *str);
int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putsignednbr(int n);
int	ft_putunsignednbr(unsigned int n);

int	ft_hexlower(unsigned long long n);
int	ft_hexupper(unsigned long long n);
int ft_countnbr(int n);

#endif