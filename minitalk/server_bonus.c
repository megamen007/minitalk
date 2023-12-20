/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:28:57 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/04 01:38:46 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signal_number, siginfo_t *signal_info,
		void *context_pointer)
{
	static char	received_char;
	static int	current_bit_index;
	static int	sender_pid;

	(void)context_pointer;
	if (sender_pid != signal_info->si_pid)
	{
		sender_pid = signal_info->si_pid;
		received_char = 0;
		current_bit_index = 0;
	}
	if (signal_number == SIGUSR1)
		received_char |= (1 << current_bit_index);
	current_bit_index++;
	if (current_bit_index == 8)
	{
		ft_putchar(received_char);
		if (received_char == '\0')
			kill(signal_info->si_pid, SIGUSR1);
		current_bit_index = 0;
		received_char = 0;
		sender_pid = signal_info->si_pid;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					pid;

	(void)argv;
	action.sa_sigaction = signal_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	ft_putnbr(pid);
	if (argc != 1)
	{
		write(1, "Error : please check argument count again !\n", 45);
		return (0);
	}
	ft_putstr("\n");
	while (1)
		sleep(1);
}
