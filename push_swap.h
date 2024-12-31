#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct      s_stack_list
{
    int n;
    int mid_point;
    int curr_pos;
    int push_cost;
    bool is_above_mid;
    bool is_min_node;
    struct s_stack_list *next;
    struct s_stack_list *prev;
    struct s_stack_list *target;

}                   t_stack_list;

#endif
