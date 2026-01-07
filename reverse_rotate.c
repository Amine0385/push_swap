/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 08:52:37 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 10:54:05 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **rrr)
{
	t_stack	*tmp;

	if (!rrr || !*rrr || !(*rrr)->next)
		return ;
	tmp = *rrr;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *rrr;
	*rrr = tmp->next;
	tmp->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
