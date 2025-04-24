/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:29:24 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/23 19:00:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack_list **stack)
{
	t_stack_list	*first;
	t_stack_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack_list **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack_list **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack_list **a, t_stack_list **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
