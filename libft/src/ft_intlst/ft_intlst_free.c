/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:13 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/16 10:54:13 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and frees all elements of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_free(t_intlst **lst)
{
	t_intlst	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
