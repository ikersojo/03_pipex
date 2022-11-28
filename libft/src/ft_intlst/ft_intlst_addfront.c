/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_addfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:48:42 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/20 17:13:43 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and adds the element new at the top of the list.
---------------------------------------------------------------------------- */
void	ft_intlst_addfront(t_intlst **lst, t_intlst *new)
{
	if (new && *lst)
		new->next = *lst;
	else if (new)
		new->next = NULL;
	*lst = new;
}
