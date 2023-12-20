/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:28:42 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/04 01:35:30 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
void	reception_check(int signal);
int		ft_isdigit(int c);

#endif