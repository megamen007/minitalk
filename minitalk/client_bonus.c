/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 00:28:53 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/04 21:59:55 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_message(int receiver_pid, char message)
{
	int	current_bit_index;

	current_bit_index = 0;
	while (current_bit_index <= 7)
	{
		if ((1 << current_bit_index) & message)
			kill(receiver_pid, SIGUSR1);
		else
			kill(receiver_pid, SIGUSR2);
		usleep(100);
		current_bit_index++;
	}
}

void	reception_check(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("Message received successfully");
}

int	pid_check(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '\0')
	{
		if (ft_isdigit(path[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Error : please check argument count again !\n", 45);
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	signal(SIGUSR1, reception_check);
	if (pid_check(argv[1]) != 0)
	{
		i = 0;
		while (argv[2][i] != '\0')
			send_message(pid, argv[2][i++]);
		send_message(pid, '\0');
	}
	else
		write(1, "Error : pid is incorrect !\n", 28);
	return (0);
}
