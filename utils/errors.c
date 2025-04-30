/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:20 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/30 10:01:59 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	free_error(t_stack_list **stack, char **av, int is_split)
{
	ft_putendl_fd("Error", 2);
	free_stack(stack);
	if (is_split)
		free_split(av);
	exit(1);
}

void	free_stack(t_stack_list **stack)
{
	t_stack_list	*save_next;

	if (!(*stack))
		return ;
	while (*stack)
	{
		save_next = (*stack)->next;
		free(*stack);
		*stack = save_next;
	}
	*stack = NULL;
}
