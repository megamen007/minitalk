/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:49:57 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/04 20:35:52 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	if (pid_check(argv[1]) != 0)
	{
		i = 0;
		while (argv[2][i] != '\0')
			send_message(pid, argv[2][i++]);
		send_message(pid, '\0');
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
