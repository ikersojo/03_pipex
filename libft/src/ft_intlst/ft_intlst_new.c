/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:20:07 by isojo-go          #+#    #+#             */
/*   Updated: 2022/10/30 10:38:01 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Allocates (with malloc(3)) and returns a new element of integer list.
The value is initialized with the value of the parameter.
The variable next is initialized to NULL.
If the allocation fails, the function returns NULL.
---------------------------------------------------------------------------- */
t_intlst	*ft_intlst_new(int value)
{
	t_intlst	*new;

	new = (t_intlst *)malloc(sizeof(t_intlst));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
