/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:15 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 09:37:16 by mmilicev         ###   ########.fr       */
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
