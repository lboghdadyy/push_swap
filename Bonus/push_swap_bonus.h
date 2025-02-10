/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:40:30 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 20:21:43 by sbaghdad         ###   ########.fr       */
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
	struct s_list	*previous;
	int				index;
	int				target_index;
	int				status;
	int				target_status;
}	t_list;

char	*checking_arguments(int argc, char **argv);
int		handel_this(t_list **stack_a, char	*args);
char	*ft_strjoin(int size, char **strs, char sep);

char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
long	ft_atoi(char *s);
int		duplicate_args(t_list *list);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);

#endif