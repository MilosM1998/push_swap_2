/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:39:30 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/24 21:21:40 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_node(t_stack_list **src_stack, t_stack_list **dest_stack)
{
	t_stack_list	*push_node;

	if (!src_stack)
		return ;
	push_node = *src_stack;
	*src_stack = (*src_stack)->next;
	if (!(*dest_stack))
	{
		*dest_stack = push_node;
		(*dest_stack)->next = NULL;
	}
	else
	{
		push_node->next = *dest_stack;
		*dest_stack = push_node;
	}
}

void	push(t_stack_list **src_stack, t_stack_list **dest_stack,
		char push_stack_name)
{
	push_node(src_stack, dest_stack);
	if (push_stack_name == 'a')
		ft_putendl_fd("pa", 1);
	else if (push_stack_name == 'b')
		ft_putendl_fd("pb", 1);
	else
	{
		ft_putendl_fd("PUSH ERROR: Stack name must be a or b!", 2);
		return ;
	}
}
