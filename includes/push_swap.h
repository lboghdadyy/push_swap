#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
	int				target_index;
	int				status;
	int				target_status;
}	t_list;

char	*checking_arguments(int argc, char **argv);
char	*ft_strjoin(int size, char **strs, char sep);
char	**ft_split(char const *s, char c);
int		handel_this(char	*args);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		duplicate_args(t_list	*list);
size_t	ft_strlen(const char *s);
long	ft_atoi(char *s);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	sort_three(t_list **list);
void	sort_five(t_list **list);
void	sort_four(t_list **list);
int		get_the_min(t_list *list);
int		are_they_sorted(t_list *list);
int		index_of_min(t_list *list);
int		get_the_max(t_list *lst);
int		ft_lstsize(t_list *lst);
int		find_target(t_list **stack_a, t_list **stack_b);
void	set_index(t_list **stack);
int		start_sorting(t_list **stack_a, t_list **stack_b);
void	just_sort(t_list	**stack_a);
int		get_the_index(int value, t_list *list);
void	rotat(t_list **list);
void	swap(t_list **stack);
void	reverse_rotate(t_list **list);
int		status_index(t_list *list, int index);
void	cont_the_proc(int i, int t, t_list **s_a, t_list **s_b);
int		best_move(t_list *stack_a, t_list *stack_b);
int		get_target(t_list *list, int index);

/*shortcuts*/

void	down_up(t_list **stack_a, t_list **stack_b);
void	up_down(t_list **stack_a, t_list **stack_b);

/*instructions :*/

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack);
void	ra(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif