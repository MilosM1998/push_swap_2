/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:36:33 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 09:36:46 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_rev(t_stack_list **stack)
{
	t_stack_list	*last;
	t_stack_list	*before_last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	before_last_node = *stack;
	while (before_last_node && before_last_node->next->next)
		before_last_node = before_last_node->next;
	before_last_node->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rev_rotate(t_stack_list **stack, char which_stack)
{
	rotate_rev(stack);
	if (which_stack == 'a')
		ft_putendl_fd("rra", 1);
	else if (which_stack == 'b')
		ft_putendl_fd("rrb", 1);
	else
		ft_putendl_fd("REV_ROTATE_ERROR: Stack name must be a or b.", 2);
}

void	rev_rotate_both(t_stack_list **a, t_stack_list **b)
{
	rotate_rev(a);
	rotate_rev(b);
	ft_putendl_fd("rrr", 1);
}
