/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_before_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:19:42 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/23 10:26:31 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter a pointer to the first element of an integer list and
returns the element before the last of the list.
---------------------------------------------------------------------------- */

t_intlst	*ft_intlst_before_last(t_intlst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
