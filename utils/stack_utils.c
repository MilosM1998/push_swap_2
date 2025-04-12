/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:25:38 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 00:24:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_node(t_stack_list **a, int n)
{
	t_stack_list	*last;
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		return ;
	new->n = n;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = find_last_node(*a);
	last->next = new;
}

t_stack_list	*find_last_node(t_stack_list *stack)
{
	t_stack_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
int	stack_len(t_stack_list *stack)
{
	int				len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
int	is_sorted(t_stack_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack && stack->next)
	{
		if (stack->n > stack->next->n)
			return (0);
		stack = stack->next;
	}
	return (1);
}