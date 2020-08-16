/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:24:20 by lcouto            #+#    #+#             */
/*   Updated: 2020/01/30 19:11:46 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = (void*)content;
	new->next = NULL;
	return (new);
}
