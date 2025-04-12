/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:39:23 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 00:27:30 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_stack(t_stack_list **stack)
{
	t_stack_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
    last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}
void	rotate(t_stack_list **stack, char stack_name)
{
	rotate_stack(stack);
	if (stack_name == 'a')
		ft_putendl_fd("ra", 1);
	else if (stack_name == 'b')
		ft_putendl_fd("rb", 1);
	else
		ft_putendl_fd("ROTATE ERROR: Stack name must be a or b!", 2);
}
void	rr(t_stack_list **a, t_stack_list **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putendl_fd("rr", 1);
}