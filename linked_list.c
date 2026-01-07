/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:27:52 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/29 11:42:45 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

void	free_stack(t_stack *head)
{
	t_stack		*tmp;

	if (!head)
		exit(1);
	while (head)
	{
		tmp = (head)->next;
		free(head);
		head = tmp;
	}
	exit(1);
}

void	add_stack(t_stack **head, int value)
{
	t_stack	*tmp;

	if (!head)
		return ;
	if (!*head)
	{
		*head = new_node(value);
		if (!*head)
			free_stack(*head);
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node(value);
		if (!tmp->next)
			free_stack(*head);
	}
}
