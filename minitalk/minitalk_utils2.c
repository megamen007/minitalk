/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:55:35 by mboudrio          #+#    #+#             */
/*   Updated: 2023/03/30 03:10:01 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	counter(long int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		c *= -1;
		i++;
	}
	while (c > 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	nb;

	nb = n;
	len = counter(nb);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	if (nb < 0)
		return (0);
	else if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (s);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
