/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:26 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 11:03:35 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack_list	*new_node(t_stack_list **a, int n)
{
	t_stack_list	*last;
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		return (NULL);
	new->n = n;
	new->index = 0;
	new->curr_pos = 0;
	new->cost = 0;
	new->target = NULL;
	new->next = NULL;
	if (!*a)
		*a = new;
	else
	{
		last = find_last_node(*a);
		last->next = new;
	}
	return (new);
}
static int	is_there_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}
static char	**do_split(t_stack_list **stack, char *av)
{
	long			n;
	int				i;
	char			**split;
	t_stack_list	*node;

	i = 0;
	split = ft_split(av, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		if (check_input(split[i]))
			free_error(stack, split, 1);
		n = ft_atol(split[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_error(stack, split, 1);
		if (check_if_dup(stack, (int)n))
			free_error(stack, split, 1);
		node = new_node(stack, (int)n);
		if (!node)
			free_error(stack, split, 1);
		i++;
	}
	return (split);
}
static void	allocate_node(t_stack_list **stack, char *av)
{
	long			n;
	t_stack_list	*node;

	if (check_input(av))
		free_error(stack, &av, 0);
	n = ft_atol(av);
	if (n < INT_MIN || n > INT_MAX)
		free_error(stack, &av, 0);
	if (check_if_dup(stack, (int)n))
		free_error(stack, &av, 0);
	node = new_node(stack, (int)n);
	if (!node)
		free_error(stack, NULL, 0);
}
void	init_stack(t_stack_list **stack, char **av)
{
	int		i;
	char	**split;

	split = NULL;
	i = 0;
	while (av[i])
	{
		if (is_there_space(av[i]))
		{
			split = do_split(stack, av[i]);
			if (!split)
				free_error(stack, split, 1);
			free_split(split);
		}
		else
			allocate_node(stack, av[i]);
		i++;
	}
}
