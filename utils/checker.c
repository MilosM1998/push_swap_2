/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:36:28 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/12 16:15:07 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_av(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!ft_isdigit(av[i]))
		return (1);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}
int	check_if_dup(t_stack_list **stack, long n)
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
