#include "../includes/push_swap.h"

t_list *duplicate_list(t_list *original)
{
    if (!original)
        return (NULL);
    t_list *new_list = NULL;
    t_list *new_node, *last_node = NULL;
    t_list *current = original;
    while (current)
    {
        new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
            return (NULL);
        new_node->content = current->content;
        new_node->index = current->index;
        new_node->target_index = current->target_index;
        new_node->status = current->status;
        new_node->target_status = current->target_status;
        new_node->next = NULL;
        new_node->previous = last_node;
        if (!new_list)
            new_list = new_node; // First node
        else
            last_node->next = new_node;
        last_node = new_node; // Move forward
        current = current->next;
    }
    return new_list;
}