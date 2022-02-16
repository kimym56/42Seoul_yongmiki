/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:16:39 by yongmiki          #+#    #+#             */
/*   Updated: 2022/02/16 22:12:23 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

// ================================= const ================================== //

# define MIN_PID					100
# define MAX_PID					99998
# define PID_BIT_COUNT				18
# define MSG_BIT_COUNT				8

# define ASCII_EOT					0x4



// ================================ library ================================= //


# include <signal.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

// ============================ global variable ============================= //

extern int	g_receive_signal;

/*
** =========================== prototype declaration ===========================
*/

void	print_success_message(char *message);
void	print_failure_message(char *message);
void	print_pid(char *client_or_server, int32_t pid);

void	set_signal(void);

// ============================== libft ====================================== //
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int     ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
void    ft_putchar_fd(char c, int fd);

#endif
