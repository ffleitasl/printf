/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:00:06 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/12 17:45:41 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const*format, ...);
void	ft_puthexupper(unsigned long long nbr, int *count);
void	ft_puthexlower(unsigned long long nbr, int *count);
void	ft_putunsignednbr(unsigned int nbr, int *count);
void	ft_putnbr(int nbr, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putchar(char c, int *count);

#endif