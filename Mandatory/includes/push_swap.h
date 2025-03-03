/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:31:01 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/27 10:45:06 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
	int				target_index;
	int				status;
	int				target_status;
}	t_list;

char	**ft_checking_arguments(int argc, char **argv);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char *s, char c);
int		ft_pre_sort(char	**args, t_list **stack_a, t_list **stack_b);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_duplicate_args(t_list	*list);
size_t	ft_strlen(char *s);
long	ft_atoi(char *s);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_sort_three(t_list **list);
void	ft_sort_five(t_list **stack_a, t_list	**stack_b);
void	ft_sort_four(t_list **stack_a, t_list	**stack_b);
int		ft_get_the_min(t_list *list);
int		ft_are_they_sorted(t_list *list);
int		ft_index_of_min(t_list *list);
int		ft_get_the_max(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_find_target(t_list **stack_a, t_list **stack_b);
void	ft_set_index(t_list **stack);
int		ft_start_sorting(t_list **stack_a, t_list **stack_b);
void	ft_big_sort(t_list **stack_a, t_list **stack_b);
int		ft_get_the_index(int value, t_list *list);
void	ft_rotat(t_list **list);
void	ft_swap(t_list **stack);
void	ft_reverse_rotate(t_list **list);
int		ft_index_st(t_list *list, int index);
void	ft_cont_the_proc(int i, int t, t_list **s_a, t_list **s_b);
int		ft_best_move(t_list *stack_a, t_list *stack_b);
int		ft_get_target(t_list *list, int index);
void	ft_free_tab(char **str);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
int		ft_status_of_min(t_list *stack);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s1);

/*shortcuts*/

void	ft_down_up(t_list **stack_a, t_list **stack_b);
void	ft_up_down(t_list **stack_a, t_list **stack_b);

/*instructions :*/

void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_rb(t_list **stack);
void	ft_ra(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);

#endif