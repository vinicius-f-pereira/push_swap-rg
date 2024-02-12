/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:18:27 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 22:21:18 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller(t_lnode *stack, int size)
{
	t_lnode	*node;
	int		small;

	node = stack;
	small = node->nbr;
	while (node && size--)
	{
		if (node->nbr < small)
			small = node->nbr;
		if (node->next)
			node = node->next;
	}
	return (small);
}

int	bigger(t_lnode *stack, int size)
{
	t_lnode	*node;
	int		big;

	node = stack;
	big = node->nbr;
	while (node && size--)
	{
		if (node->nbr > big)
			big = node->nbr;
		 if (node->next)
			 node = node->next;
	}
	return (big);
}

static int	sort_middle(int nbr[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (*(nbr + j) > *(nbr + j + 1))
			{
				tmp = *(nbr + j + 1);
				*(nbr + j + 1) = *(nbr + j);
				*(nbr + j) = tmp;
			}
		}
	}
	return (*(nbr + 2));
}

int	middle(t_lnode *stack)
{
	t_lnode	*node;
	int		nbr[5];
	int		i;

	i = 0;
	node = stack;
	while (i < 5)
	{
		*(nbr + i++) = node->nbr;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (sort_middle(nbr));
}

void	init_counters(t_counters *counters)
{
	counters->ra = 0;
	counters->rb = 0;
	counters->pa = 0;
	counters->pb = 0;
}

void	set_pivots(t_lnode *stack, t_counters *counters, int size)
{
	int	min;
	int	max;

	min = smaller(stack, size);
	max = bigger(stack, size);
	counters->big = (min + max) / 2;
	counters->small = (min + counters->big) / 2;
}