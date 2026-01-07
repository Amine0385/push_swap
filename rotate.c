/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:48:44 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 10:51:31 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **rr)
{
	t_stack	*tmp;

	if (!rr || !*rr || !(*rr)->next)
		return ;
	tmp = *rr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *rr;
	tmp = (*rr)->next;
	(*rr)->next = NULL;
	*rr = tmp;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
