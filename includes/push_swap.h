#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int			    content;
	struct s_list	*next;
	struct s_list	*previous;
} t_list;

char    *checking_arguments(int argc, char **argv);
char	*ft_strjoin(int size, char **strs, char sep);
char	**ft_split(char const *s, char c);
int    handel_this(char    *args);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		duplicate_args(t_list   *list);
size_t	ft_strlen(const char *s);
long	ft_atoi(char *s);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void    sort_three(t_list **list);
void    sort_five(t_list **list);
void    sort_four(t_list **list);
int     get_the_min(t_list *list);
int		are_they_sorted(t_list *list);
int     index_of_min(t_list *list);

/*instructions :*/

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void    rb(t_list **stack);
void    ra(t_list **stack);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack);
void    rrb(t_list **stack);
void    rrr(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);


#endif