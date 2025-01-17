/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:28:08 by rde-mour          #+#    #+#             */
/*   Updated: 2024/03/04 12:51:22 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_lnode **orig, t_lnode **dest)
{
	t_lnode	*node;

	if (!orig || !(*orig))
		return ;
	node = *orig;
	*orig = (*orig)->next;
	if (*orig)
		(*orig)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	node->prev = NULL;
	*dest = node;
}

void	push(t_stacks **stacks, int flags, int times)
{
	if (!times)
		return ;
	if (flags == STACK_A && (*stacks)->size_b > 0)
	{
		push_node(&(*stacks)->b, &(*stacks)->a);
		(*stacks)->size_a++;
		(*stacks)->size_b--;
		ft_putendl_fd("pa", 1);
	}
	else if (flags == STACK_B && (*stacks)->size_a > 0)
	{
		push_node(&(*stacks)->a, &(*stacks)->b);
		(*stacks)->size_a--;
		(*stacks)->size_b++;
		ft_putendl_fd("pb", 1);
	}
	if (--times)
		push(stacks, flags, times);
}
