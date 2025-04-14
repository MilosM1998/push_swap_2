/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:05:41 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/14 22:38:48 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_targets(t_stack_list *a, t_stack_list *b)
{
	int				closest_bigger;
    int             smallest_n;
	t_stack_list	*smallest;
	t_stack_list	*target;

	closest_bigger = find_biggest_node(a);
    smallest_n = find_smallest_node(a);
    while (a)
	{
		if (a->n > b->n && a->n < closest_bigger)
		{
			target = a;
			closest_bigger = a->n;
		}
		if (a->n == smallest)
			smallest = a;
		a = a->next;
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
static void	prepare_for_push(t_stack_list *a, t_stack_list *b)
{
	set_targets(a, b);
	calculate_cost(a, b);
}
void	push_b_to_a(t_stack_list **a, t_stack_list **b)
{
	t_stack_list *tmp;

	tmp = *b;
	while (tmp)
	{
		prepare_for_push(*a, tmp);
        
		tmp = tmp->next;
	}
}