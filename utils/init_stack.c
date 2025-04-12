/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:52:06 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/12 16:29:08 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    init_stack(t_stack_list **stack, char **av, int is_split)
{
    int i;
    long    n;
    
    i = 0;
    while(av[i])
    {
        if(check_av(av[i]))
            free_error(stack, av, is_split);
        n = ft_atol(av[i]);
        if(n < INT_MIN || n > INT_MAX)
            free_error(stack, av, is_split);
        if(check_if_dup(stack, n))
            free_error(stack, av, is_split);
        new_node(stack, (int)n);
        i++;
    }
    if(is_split)
        free_split(av);
}