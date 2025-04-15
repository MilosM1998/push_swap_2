/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:05:41 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/16 00:02:24 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_targets(t_stack_list *a, t_stack_list *b)
{
	int				closest_bigger;
	int				smallest_n;
	t_stack_list	*smallest;
	t_stack_list	*target;
	t_stack_list	*tmp;

	tmp = a;
	closest_bigger = find_biggest_node(tmp);
	smallest_n = find_smallest_node(tmp);
	target = NULL;
	smallest = NULL;
	while (tmp)
	{
		if (tmp->n > b->n && tmp->n < closest_bigger)
		{
			target = tmp;
			closest_bigger = tmp->n;
		}
		if (tmp->n == smallest_n)
			smallest = tmp;
		tmp = tmp->next;
	}
	if (!target)
		b->target = smallest;
	else
		b->target = target;
}
static void	calculate_cost(t_stack_list *a, t_stack_list *b)
{
	int	pos_a;
	int	pos_b;

	if (!b || !b->target)
		return ;
	pos_a = get_curr_position(a, b->target->n);
	pos_b = get_curr_position(b, b->n);
	if (pos_b <= stack_len(b) / 2)
		b->cost = pos_b;
	else
		b->cost = stack_len(b) - pos_b;
	if (pos_a <= stack_len(a) / 2)
		b->cost = b->cost + pos_a;
	else
		b->cost = b->cost + stack_len(a) - pos_a;
}
static t_stack_list	*find_low_cost_node(t_stack_list *b)
{
	t_stack_list	*low_cost_node;
	int				cost;
	
	if (!b)
		return (NULL);
	low_cost_node = NULL;
	cost = INT_MAX;
	while (b)
	{
		if(!b->target)
		{
			b = b->next;
			continue;
		}
		if (b->cost < cost)
		{
			cost = b->cost;
			low_cost_node = b;
		}
		b = b->next;
	}
	return (low_cost_node);
}
static void	prepare_for_push(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*tmp;

	tmp = b;
	while (tmp)
	{
		set_targets(a, tmp);
		calculate_cost(a, tmp);
		tmp = tmp->next;
	}
}
static void	find_and_rotate(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*low_cost_node;
	int				low_cost_node_pos_b;
	int				low_cost_node_pos_a;

	low_cost_node = find_low_cost_node(*b);
	if(!low_cost_node || !low_cost_node->target)
		return ;
	low_cost_node_pos_b = get_curr_position(*b, low_cost_node->n);
	low_cost_node_pos_a = get_curr_position(*a, low_cost_node->target->n);
	if (low_cost_node_pos_b <= stack_len(*b) / 2
		&& low_cost_node_pos_a <= stack_len(*a) / 2)
		while (*a != low_cost_node->target && *b != low_cost_node)
			rr(a, b);
	else if (low_cost_node_pos_a > stack_len(*a) / 2
		&& low_cost_node_pos_b > stack_len(*b) / 2)
		while (*a != low_cost_node->target && *b != low_cost_node)
			rev_rotate_both(a, b);
	// else if (low_cost_node_pos_a <= stack_len(*a) / 2
	// 	&& low_cost_node_pos_b > stack_len(*b) / 2)
	// 	while (*a != low_cost_node->target && *b != low_cost_node)
	// 	{
	// 		rotate(a, 'a');
	// 		rev_rotate(b, 'b');
	// 	}
	// else if (low_cost_node_pos_a > stack_len(*a) / 2
	// 	&& low_cost_node_pos_b <= stack_len(*b) / 2)
	// 	while (*a != low_cost_node->target && *b != low_cost_node)
	// 	{
	// 		rev_rotate(a, 'a');
	// 		rotate(b, 'b');
	// 	}
}
void	push_b_to_a(t_stack_list **a, t_stack_list **b)
{
	while (*b)
	{
		prepare_for_push(*a, *b);
		find_and_rotate(a, b);
		push(b, a, 'a');
		set_index(a);
		set_index(b);
	}
}