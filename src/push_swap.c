/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:39:41 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/13 17:41:27 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_first_char(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

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
	int				is_split;

	is_split = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2 && check_first_char(av[1][0]))
	{
		if (av[1][0] == '\0')
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		av = ft_split(av[1], ' ');
		is_split = 1;
	}
	else
		av++;
	init_stack(&a, av, is_split);
	sort_stack(&a, &b);
	/* t_stack_list *curr;
	curr = a;
	while (curr)
	{
		ft_printf("%d->", curr->n);
		curr = curr->next;
	} */
	free_stack(&a);
	return (0);
}
