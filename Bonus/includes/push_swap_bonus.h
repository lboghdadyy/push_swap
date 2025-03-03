/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:49 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/27 13:55:03 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_instr
{
	char			*instr;
	struct s_instr	*next;
}	t_instr;

char	**ft_split(char *s, char c);
long	ft_atoi(char *s);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_duplicate_args(t_list *list);
int		ft_are_they_sorted(t_list *list);
int		ft_isdigit(int c);
int		ft_check_one_arg(char *s);
int		ft_is_it_empty(char *arg);
int		ft_check_multi_arguments(char **array);
char	**ft_checking_arguments(int argc, char **argv);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char	*str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_convert(char	**args, t_list **stack_a);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
t_instr	*ft_last_instruction(t_instr *lst);
void	add_instruction_back(t_instr **alst, t_instr *new);
t_instr	*ft_new_instr(char *line);
int		ft_instr_size(t_instr *list);
void	ft_clear_instructions(t_instr **lst);
void	ft_free_tab(char **str);
void	ft_apply_instrcutions(t_instr *instrs, t_list **s_a, t_list **s_b);
int		ft_strcmp(char *s1, char *s2);

#endif