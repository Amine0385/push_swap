/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:02:56 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 11:05:57 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int size, t_stack *head)
{
	int		j;
	int		tmp;

	j = 0;
	while (head)
	{
		arr[j] = head->data;
		head = head->next;
		j++;
	}
	while (size > 0)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		size--;
	}
}

static void	indexing(t_stack *head, int size)
{
	int			*arr;
	int			j;

	arr = malloc(size * sizeof(int));
	if (!arr)
		(free_stack(head),(1));
	sort_arr(arr, size, head);
	while (head)
	{
		j = 0;
		while (j < size)
		{
			if (arr[j] == head->data)
			{
				head->index = j;
				break ;
			}
			j++;
		}
		head = head->next;
	}
	free(arr);
}

void	filling(t_stack	**head, int ac, char **arr, int *size)
{
	char	**strs;
	int		i;
	int		j;

	if (!head)
		exit(1);
	i = 1;
	while (i < ac)
	{
		strs = ft_split(arr[i], ' ');
		if (!strs)
			(free_stack(*head), exit(1));
		j = 0;
		while (strs[j])
		{
			add_stack(head, ft_atoi(strs[j]));
			j++;
			*size += 1;
		}
		ft_free(strs);
		strs = NULL;
		i++;
	}
	indexing(*head, *size);
}
