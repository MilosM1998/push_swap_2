/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:36:28 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 22:12:52 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
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
