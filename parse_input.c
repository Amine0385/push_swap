/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:52:59 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/27 18:42:49 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char *str)
{
	int			sign;
	double long	sum;
	int			i;

	i = 0;
	sign = 1;
	sum = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	if (str[i])
		return (1);
	if (sum * sign > 2147483647 || sum * sign < -2147483648)
		return (1);
	return (0);
}

static int	helper(char *str, char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		if (ft_atoi(str) == ft_atoi(strs[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_next(char *str, char **arr, int start, int size)
{
	char	**tmp;

	while (start < size)
	{
		tmp = ft_split(arr[start++], ' ');
		if (!tmp)
			exit(1);
		if (helper(str, tmp))
			return (ft_free(tmp), 1);
		ft_free(tmp);
	}
	return (0);
}

static int	check_repeat(char **arr, int size)
{
	char	**strs;
	int		i;
	int		k;

	i = 0;
	while (i < size)
	{
		strs = ft_split(arr[i], ' ');
		if (!strs || !*strs || !**strs)
			(write(2, "Error\n", 6), ft_free(strs), exit(1));
		k = 0;
		while (strs[k])
		{
			if (helper(strs[k], &strs[k + 1]))
				return (ft_free(strs), 1);
			if (check_next(strs[k], arr, i + 1, size))
				return (ft_free(strs), 1);
			k++;
		}
		ft_free(strs);
		strs = NULL;
		i++;
	}
	return (0);
}

void	parse_input(int ac, char **av)
{
	int		i;
	int		j;
	char	**strs;

	i = 1;
	while (i < ac)
	{
		j = 0;
		strs = ft_split(av[i], ' ');
		if (!strs)
			(exit(1));
		while (strs[j])
		{
			if (check_int(strs[j]))
				(write(2, "Error\n", 6), ft_free(strs), exit(1));
			j++;
		}
		ft_free(strs);
		strs = NULL;
		i++;
	}
	if (check_repeat(&av[1], ac - 1))
		(write(2, "Error\n", 6), exit(1));
}
