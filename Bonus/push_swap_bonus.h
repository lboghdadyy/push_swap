/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:40:30 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/13 17:39:33 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

#define BUFFER_SIZE 1024

char	*checking_arguments(int argc, char **argv);
int		handel_this(t_list **stack_a, char	*args);
char	*ft_strjoin(int size, char **strs, char sep);
char	*ft_substr(char *s, unsigned int start, size_t len);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
long	ft_atoi(char *s);
int		duplicate_args(t_list *list);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
size_t	ft_strlen(char *s);
int		ft_contains_number(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
void	free_tab(char **str);
char	*ft_strdup(char *s1);
int		are_they_sorted(t_list **list);
int		getting_instructions(t_list **s_a, t_list **s_b, char *line, char **ins);
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