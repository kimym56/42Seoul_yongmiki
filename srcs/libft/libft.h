/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 03:52:02 by yongmiki          #+#    #+#             */
/*   Updated: 2022/03/09 21:24:01 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);

#endif
