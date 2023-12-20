/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:46:09 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/04 01:20:23 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

void	signal_handler(int signal_number, siginfo_t *signal_info,
			void *context_pointer);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	send_message(int receiver_pid, char message);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
int		pid_check(char *path);

#endif