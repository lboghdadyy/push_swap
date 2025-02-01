#include "../includes/push_swap.h"

#include <limits.h> 

int best_move(t_list *stack_a, t_list *stack_b)
{
    int best_move_index = -1;
    int min_moves = INT_MAX;
    int count_ra, count_rra, count_rb, count_rrb;
    t_list *tmp_a;
    t_list *tmp_b;

    tmp_b = stack_b;
    while (tmp_b)
    {
        tmp_a = stack_a;
        count_ra = 0;
        count_rra = 0;

        // Count ra moves (rotate to bring target to top)
        while (tmp_a)
        {
            if (tmp_a->index == tmp_b->target_index)
                break;
            tmp_a = tmp_a->next;
            count_ra++;
        }

        tmp_a = stack_a;
        while (tmp_a)
        {
            if (tmp_a->index == tmp_b->target_index)
                break;
            tmp_a = tmp_a->previous;
            count_rra++;
        }

        count_rb = tmp_b->index;
        count_rrb = ft_lstsize(stack_b) - tmp_b->index;

        // Calculate the total moves needed
        int total_moves = (count_ra < count_rra ? count_ra : count_rra) +
                          (count_rb < count_rrb ? count_rb : count_rrb);

        // Update the best move if this one is better
        if (total_moves < min_moves)
        {
            min_moves = total_moves;
            best_move_index = tmp_b->index;
        }

        tmp_b = tmp_b->next;
        // printf("hna best move\n");
    }
    return best_move_index;
}

int is_it_above(t_list *list, int index)
{
    while (list)
    {
        if (list->index == index)
            return (list->above_med);
        list = list->next;
    }
    return (-1);
}

void do_this(int is_it, int index, t_list **stack_a, t_list **stack_b)
{
    // Move the correct number in stack B to the top
    while ((*stack_b)->index != index)
    {
        if (is_it)
            rb(stack_b);
        else
            rrb(stack_b);
    }

    // Move the target number in stack A to the top
    while ((*stack_a)->index != (*stack_b)->target_index)
    {
        if (is_it_above(*stack_a, (*stack_b)->target_index))
            ra(stack_a);
        else
            rra(stack_a);
    }

    // Push from stack B to stack A
    pa(stack_a, stack_b);
}

void start_sorting(t_list **stack_a, t_list **stack_b)
{
    int best;

    while (*stack_b)
    {
        best = best_move(*stack_a, *stack_b);
        // printf("best move index -> {%d}", best);
        if (best == -1)
            return; // No valid moves found
        do_this(is_it_above(*stack_b, best), best, stack_a, stack_b);
        set_index(stack_a, stack_b);
        find_target(stack_a, stack_b);
        // print_list(*stack_a, 'a');
        // print_list(*stack_b, 'b');
    }
    while ((*stack_a)->content != get_the_min(*stack_a))
        ra(stack_a);
    // print_list(*stack_a, 'a');
    // print_list(*stack_b, 'b');
}
