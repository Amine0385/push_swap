/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouskha <mbouskha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:52:18 by mbouskha          #+#    #+#             */
/*   Updated: 2025/12/30 10:15:53 by mbouskha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}			t_stack;

t_stack	*new_node(int value);
void	add_stack(t_stack **head, int value);
void	free_stack(t_stack *head);
void	sa(t_stack **t_stack_a);
void	sb(t_stack **t_stack_b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **t_stack_a);
void	rb(t_stack **t_stack_b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **t_stack_a);
void	rrb(t_stack **t_stack_b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **t_stack_a, t_stack **t_stack_b);
void	pb(t_stack **t_stack_a, t_stack **t_stack_b);
char	**ft_split(char const *s1, char c);
void	ft_free(char **strs);
void	parse_input(int ac, char **av);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char *str);
void	filling(t_stack	**head, int ac, char **arr, int *size);
void	chunks_algo(t_stack **a, t_stack **b, int size);
#endif
