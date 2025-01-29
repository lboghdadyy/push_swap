#include "includes/push_swap.h"

int main(int ac, char **av)
{
    char *args;
    int status;

    args = checking_arguments(ac, av);
    if (args == NULL)
        return (1);
    status = handel_this(args);
    if (status == -1)
    {
        write (2, "Error\n", 7);
        return (1);
    }
}