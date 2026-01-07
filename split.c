/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:54:44 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 11:02:24 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *s1, char c)
{
	size_t	i;
	size_t	count;
	int		check;

	i = 0;
	check = 1;
	count = 0;
	while (s1[i] && s1[i] == c)
		i++;
	while (s1[i])
	{
		if (s1[i] != c)
		{
			if (check == 1)
				count++;
			check = 0;
		}
		else
			check = 1;
		i++;
	}
	return (count);
}

static size_t	ft_len(char const *s1, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[i] == c && s1[i])
		i++;
	while (s1[i] != c && s1[i])
	{
		i++;
		len++;
	}
	return (len);
}

void	ft_free(char **strs)
{
	size_t		i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_helper(char const *s1, char **strs, char c, size_t count)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (s1[j] == c)
			j++;
		len = ft_len(s1 + j, c);
		strs[i] = ft_substr(s1, j, len);
		if (!strs[i])
		{
			ft_free(strs);
			return (0);
		}
		i++;
		j += len;
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s1, char c)
{
	char		**strs;
	size_t		count;

	if (!s1)
		return (NULL);
	count = count_word(s1, c);
	strs = malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!ft_helper(s1, strs, c, count))
		return (NULL);
	return (strs);
}
