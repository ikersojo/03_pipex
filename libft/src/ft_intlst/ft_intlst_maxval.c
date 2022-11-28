/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_maxval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:43:26 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/29 17:48:41 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of the first element of a list of integers and
returns the maximum value in the list.
---------------------------------------------------------------------------- */
int	ft_intlst_maxval(t_intlst *lst)
{
	int	max;

	if (lst)
	{
		max = -2147483648;
		while (lst)
		{
			if (lst->value > max)
				max = lst->value;
			lst = lst->next;
		}
		return (max);
	}
	return (0);
}
