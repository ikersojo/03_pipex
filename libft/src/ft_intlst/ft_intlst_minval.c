/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_minval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:43:24 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/29 17:48:41 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of the first element of a list of integers and
returns the minimum value in the list.
---------------------------------------------------------------------------- */
int	ft_intlst_minval(t_intlst *lst)
{
	int	min;

	if (lst)
	{
		min = 2147483647;
		while (lst)
		{
			if (lst->value < min)
				min = lst->value;
			lst = lst->next;
		}
		return (min);
	}
	return (0);
}
