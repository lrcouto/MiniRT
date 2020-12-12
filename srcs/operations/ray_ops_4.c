/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ops_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:31:41 by lcouto            #+#    #+#             */
/*   Updated: 2020/12/12 19:41:57 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	insert_new_node(t_intersec *current, t_intersec *new)
{
	if (current->next)
	{
		new->next = (t_intersec *)ec_malloc(sizeof(t_intersec));
		new->next->poly = current->next->poly;
		new->next->t = current->next->t;
		new->next->count = current->next->count;
		new->next->qty = current->next->qty;
		new->next->next = current->next->next;
	}
	if (current->next == NULL)
		current->next = (t_intersec *)ec_malloc(sizeof(t_intersec));
	current->next->next = new->next;
	current->next->count = new->count;
	current->next->t = new->t;
	current->next->poly = new->poly;
	current->next->qty = current->qty + 1;
}

static void	replace_head(t_intersec *current, t_intersec *new)
{
	new->next = (t_intersec *)ec_malloc(sizeof(t_intersec));
	new->next->count = current->count;
	new->next->t = current->t;
	new->next->poly = current->poly;
	new->next->qty = current->qty;
	new->next->next = current->next;
	current->next = new->next;
	current->count = new->count;
	current->t = new->t;
	current->poly = new->poly;
	current->qty = current->qty;
}

static void	first_node(t_intersec *current, t_intersec *new)
{
	current->count = new->count;
	current->t = new->t;
	current->poly = new->poly;
	current->next = NULL;
	current->qty = current->qty + 1;
}

void		push_intersec(t_intersec *head, t_intersec *new)
{
	t_intersec *current;

	current = head;
	new->next = NULL;
	if (current->qty == 0)
	{
		first_node(current, new);
		return ;
	}
	if (new->t < current->t)
	{
		replace_head(current, new);
		return ;
	}
	else
	{
		while (current->next && new->t > current->next->t)
			current = current->next;
		insert_new_node(current, new);
		return ;
	}
}
