#include "push_swap.h"

int parce_arguments(int argc,char **argv)
{
    int i;
    int j;

    i = 0;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_strchr("0123456789", argv[i][j]));
                return (0);
            j++;
        }
        i++;
    }
    retrun (1);
}

t_list    *split_args(char   **argv)
{
    int     i;
    char    **args;
    t_list  *list;

    args = ft_split(argv[1], ' ');
    i = 0;
    while (args[i])
        i++;
    if(i < 2)
        return (free_tab(args), NULL);
    list = ft_new_lst(args, 0);
    free_tab(args);
    if (!list)
        return (NULL);
    return (list);
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    int     value;
    int     could_not_sort;

    if(argc == 1 || parce_arguments(argc, argv) == 0)
    {
        printf("Please enter some arguments. :)\n");
        return (0);
    }
    if (argc == 2)
        stack_a = split_args(argv);
    else
        stack_a = ft_new_lst(argv, 1);
    sort_it(stack_a);
}