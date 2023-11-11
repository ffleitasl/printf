/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:08:59 by ffleitas          #+#    #+#             */
/*   Updated: 2023/11/11 19:47:47 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_checkplaceholders(char const *format)
{
	char *str;
	int	placeholders;
	int i;

	str = (char *)format;
	placeholders = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			if(str[i + 1] == 's' || str[i + 1] == 'd' ||
				str[i + 1] == 'i' || str[i + 1] == 'u' ||
				str[i + 1] == 'c' || str[i + 1] == 'x' ||
				str[i + 1] == 'X' || str[i + 1] == 'p' ||
				str[i + 1] == '%')
					placeholders += 1;
					i ++;
		}
		i ++;
	}
	return (i - (placeholders * 2));
}
int ft_printfcases(char const *format, int index ,va_list args)
{
	int count;

	count = 0;
	if(format[index] == 's')
		count += ft_putstr(va_arg(args,char *));
	if(format[index] == 'c')
		count += ft_putchar(va_arg(args,int));
	if(format[index] == 'd' || format[index] == 'i') 
		count += ft_putsignednbr(va_arg(args,int));
	if(format[index] == 'u')
		count += ft_putunsignednbr(va_arg(args,int));
	if(format[index] == 'x')
		count += ft_hexlower(va_arg(args,unsigned int));
	if(format[index] == 'X')
		count += ft_hexupper(va_arg(args,unsigned int));
	if(format[index] == '%')
		count += (ft_putchar('%'));
	if(format[index] == 'p')
	{
		ft_putstr("0x");
		count += (ft_hexlower(va_arg(args,unsigned long long)) + 2);
	}
	return (count);
}

int ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args,format);
	void	*result;
	int i;
	int lenft;
	int lenformat;

	i = 0;
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i ++;
			lenft += ft_printfcases(format, i, args);
		}
		else
			ft_putchar(format[i]);
		i ++;
		
	}
	lenformat = ft_checkplaceholders(format);
	va_end(args);
	return(lenft + lenformat);
}
/*int main()
{
 	char *x = "";
	
	printf("TEST:\n");
	printf("Mi printf:\n");
	int count = ft_printf("Test -> c:%c s:%s d:%d i:%i u:%u x:%x X:%X %%:%% p:%p\n", 'a',"Hello",40,-55,42,15242,15242,&x);
	printf("--------------------------------------------------------------------\n");
	printf("Original printf:\n");
	int count2 = printf("Test -> c:%c s:%s d:%d i:%i u:%u x:%x X:%X %%:%% p:%p\n", 'a',"Hello",40,-55,42,15242,15242,&x);
	printf("--------------------------------------------------------------------\n");
	printf("Cantidad de caracteres impresos mi printf:%d\n",count);
	printf("Cantidad de caracteres impresos printf:%d\n",count2); 
	
 
	// char *p = "Hello World";
	// printf("%d\n",(ft_printf("")));
	// printf("%d\n",(printf("")));
 	int count = printf("%p","");
	printf("\n%d",count);
	int count2 = ft_printf("%p","");
	ft_printf("\n%d",count2);
}*/

// c = 1
// s = 5
// d = 2
// i = 3
// u = 2
// x = 4
// X = 4 
// % = 1
// p = 14
