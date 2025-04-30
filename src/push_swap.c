/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:36:04 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 12:14:21 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack_list **a, t_stack_list **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_len(*a);
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3 && !is_sorted(*a))
		sort_3(a);
	else if (size <= 5 && !is_sorted(*a))
		sort_4_5(a, b);
	else
		sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_stack_list	*a;
	t_stack_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (av[1][0] == '\0')
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	av++;
	init_stack(&a, av);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
