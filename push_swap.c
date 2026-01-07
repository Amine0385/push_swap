/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:43:40 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 11:09:04 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_larg_position(t_stack *head)
{
	int		size;
	int		ind;
	int		largest;

	if (!head)
		return (-1);
	largest = head->index;
	size = 0;
	while (head)
	{
		if (largest <= head->index)
		{
			largest = head->index;
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

void	last_sort(t_stack **a, t_stack **b)
{
	int		nb;

	while (*b)
	{
		nb = find_larg_position(*b);
		if (nb == 0)
			pa(a, b);
		else if (nb == 1)
			rb(b);
		else if (nb == 2)
			rrb(b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = 0;
	if (ac <= 1)
		return (1);
	parse_input(ac, av);
	filling(&a, ac, av, &size);
	if (check_sort(a))
		free_stack(a);
	chunks_algo(&a, &b, size);
	last_sort(&a, &b);
	free_stack(a);
	free_stack(b);
}
