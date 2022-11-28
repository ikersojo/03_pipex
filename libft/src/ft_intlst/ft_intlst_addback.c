/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:15 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/15 22:38:04 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and adds the element new at the end of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_addback(t_intlst **lst, t_intlst *new)
{
	t_intlst	*tmp;

	if (new && *lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_intlst_last(*lst);
			tmp->next = new;
		}
	}
}
