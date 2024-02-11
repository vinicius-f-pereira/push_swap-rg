/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:26 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/11 20:53:36 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define PS_MIN -2147483648
# define PS_MAX	+2147483647

typedef struct s_lnode	t_lnode;
struct s_lnode
{
	int		nbr;
	t_lnode	*next;
	t_lnode	*prev;
};

typedef struct s_stacks	t_stacks;
struct s_stacks
{
	t_lnode	*a;
	t_lnode	*b;
	size_t	size;
};

typedef struct s_counters t_counters;
struct s_counters
{
	int	small;
	int	big;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
};

enum e_moves
{
	STACK_A,
	STACK_B,
	STACKS
};

void	stack_a(int size, t_stacks **stacks, int *count);
void	stack_b(int size, t_stacks **stacks, int *count);

void	two_handler(t_stacks **stacks, int flag);
void	three_handler_a(int size, t_stacks **stacks);
void	three_handler_b(int size, t_stacks **stacks);
void	under_three_handler(int size, t_stacks **stacks, int flag);
void	sort_five_handler(int size, t_stacks **stacks, int flag);

void	init_counters(t_counters *counters);
void	set_pivots(t_lnode *stack, t_counters *counters, int size);
int		smaller(t_lnode *stack, int size);
int		middle(t_lnode *stack);
int		bigger(t_lnode *stack, int size);
void	check_sorting(t_stacks **stacks);

//void	sort_two(t_stacks **stacks, int flag);
//void	sort_three(t_stacks **stacks, int flag);
//void	sort_four(t_stacks **stacks, int flag);
//void	sort_five(t_stacks **stacks);

void	clear_stacks(t_stacks **stacks);
void	ft_error(t_stacks **stacks);
void	llstadd_back(t_lnode **stack, t_lnode *new);
void	llstadd_front(t_lnode **stack, t_lnode *new);
void	llstclear(t_lnode **stack);
t_lnode	*llstlast(t_lnode *stack);
t_lnode	*llstnew(int nbr);
size_t	llstsize(t_lnode *stack);
void	swap(t_stacks **stacks, int moves);
void	rotate(t_stacks **stacks, int moves, int times);
void	push(t_stacks **stacks, int moves, int times);
void	reverse(t_stacks **stacks, int moves, int times);

// DELETE ----------------------------------------------------------------------
void	print_stacks(t_stacks **stacks);
// DELETE ----------------------------------------------------------------------

#endif
