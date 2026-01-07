/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:18:33 by mbouskha          #+#    #+#             */
/*   Updated: 2026/01/01 10:22:09 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small_position(t_stack *head)
{
	int		size;
	int		ind;
	int		smallest;

	if (!head)
		return (-1);
	smallest = head->index;
	size = 0;
	while (head)
	{
		if (smallest >= head->index)
		{
			smallest = head->index;
			ind = size;
		}
		head = head->next;
		size++;
	}
	if (ind == 0)
		return (0);
	if (size / 2 >= ind)
		return (1);
	return (2);
}

void	sort_3(t_stack **a, int size)
{
	if (size == 3 && (*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (size == 3 && (*a)->index < (*a)->next->index
		&& (*a)->next->index > (*a)->next->next->index)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else
	{
		if (size > 1 && (*a)->index > (*a)->next->index)
			sa(a);
	}
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	int		nb;
	int		count;

	count = 0;
	while (*a && (size - count) != 3)
	{
		nb = find_small_position(*a);
		if (nb == 0)
		{
			count++;
			pb(a, b);
		}
		else if (nb == 1)
			ra(a);
		else if (nb == 2)
			rra(a);
	}
	sort_3(a, 3);
	pa(a, b);
	if (*b)
		pa(a, b);
}

static int	has_in_chunk(t_stack *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (1);
		a = a->next;
	}
	return (0);
}

void	chunks_algo(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (size <= 3)
		(sort_3(a, size), free_stack(*a), exit(1));
	if (size <= 5)
		(sort_5(a, b, size), free_stack(*a), exit(1));
	chunk_size = 40;
	if (size <= 100)
		chunk_size = 20;
	chunk_start = 0;
	chunk_end = chunk_size - 1;
	while (chunk_start < size)
	{
		while (has_in_chunk(*a, chunk_start, chunk_end))
		{
			if ((*a)->index >= chunk_start && (*a)->index <= chunk_end)
				pb(a, b);
			else
				ra(a);
		}
		chunk_start += chunk_size;
		chunk_end += chunk_size;
	}
}
