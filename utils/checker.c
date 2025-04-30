/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:15 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 14:08:21 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input(char *n)
{
	int	i;
	int	digits;

	digits = 0;
	i = 0;
	if (n[i] == '-' || n[i] == '+')
		i++;
	if (!ft_isdigit(n[i]))
		return (1);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (1);
		digits++;
		i++;
	}
	if (digits > 19)
		return (1);
	return (0);
}

int	check_if_dup(t_stack_list **stack, int n)
{
	t_stack_list	*tmp;

	if (!*stack)
		return (0);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->n == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_empty(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] != ' ' || split[i][j] != '\t')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
