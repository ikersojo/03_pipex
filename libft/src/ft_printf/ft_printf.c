/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:49:09 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/12 11:02:11 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

//conversion specifier "cs"
static int	conv_sel(va_list *ap, char cs)
{
	int	count;

	count = 0;
	if (cs == '%')
		count += ft_putchar_fd('%', 1);
	else if (cs == 'c')
		count += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (cs == 's')
		count += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (cs == 'd' || cs == 'i')
		count += ft_putnbr_fd(va_arg(*ap, int), 1);
	else if (cs == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putuhexnbr_fd(va_arg(*ap, size_t), 1, cs);
	}
	else if (cs == 'u')
		count += ft_putunbr_fd(va_arg(*ap, unsigned int), 1);
	else if (cs == 'x' || cs == 'X')
		count += ft_putuhexnbr_fd(va_arg(*ap, unsigned int), 1, cs);
	return (count);
}

/* DESCRIPTION:
The printf utility exits 0 on success, and >0 if an error occurs.
The printf utility formats and prints its arguments, after the first, under
control of the format specified by cs (conversion specifier).
---------------------------------------------------------------------------- */
int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += conv_sel(&ap, *(str));
		}
		else
			count += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
