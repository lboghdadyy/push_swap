#include "../includes/push_swap.h"

int    check_one_arg(char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        if (str[index] == 32)
            index++;
        else if (str[index] == '-' || str[index] == '+')
        {
            if (str[index - 1] != 32 && str[index - 1])
                return (0);
            if (str[index + 1] > '9' || str[index + 1] < '0' || !str[index + 1])
                return (0);
            index++;
        }
        else if(str[index] >= '0' && str[index] <= '9')
            index++;
        else
            return (0);
    }
    return (1);
}

char    *checking_arguments(int argc, char **argv)
{
    int     i;
    char    *args;
    
    i = 0;
    if (argc == 2)
    {
        if(!check_one_arg(argv[1]))
        {
            write (2, "Error\n", 7);
            return NULL;
        }
        args = argv[1];
    }
    else
    {
        args = ft_strjoin(argc - 1, argv + 1, 32);
        if(!check_one_arg(args))
        {
            write (2, "Error\n", 7);
            return NULL;
        }
    }

    return (args);
}

int duplicate_args(t_list   *list)
{
    t_list  *outer;
    t_list  *inner;


    outer = list;
    while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->content == inner->content)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
    return (0);
}