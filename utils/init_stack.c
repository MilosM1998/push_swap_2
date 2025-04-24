/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:52:06 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:58 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	new_node(t_stack_list **a, int n)
{
	t_stack_list	*last;
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		return ;
	new->n = n;
	new->index = 0;
	new->curr_pos = 0;
	new->cost = 0;
	new->target = NULL;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = find_last_node(*a);
	last->next = new;
}

void	init_stack(t_stack_list **stack, char **av, int is_split)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (check_input(av[i]))
			free_error(stack, av, is_split);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_error(stack, av, is_split);
		if (check_if_dup(stack, (int)n))
			free_error(stack, av, is_split);
		new_node(stack, (int)n);
		i++;
	}
	if (is_split)
		free_split(av);
}
