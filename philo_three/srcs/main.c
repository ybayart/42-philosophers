/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:25 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 15:52:29 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(unsigned long long n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	msg(unsigned long long time, int act, char *text, int len)
{
	sem_wait(g_data.write);
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(act + 1);
	write(1, text, len);
	sem_post(g_data.write);
}

int		endofprog(void)
{
	if (g_data.state >= 4)
		free(g_data.philo);
	return (0);
}

int		main(int argc, char **argv)
{
	int					i;

	g_data.state = 0;
	if ((argc != 5 && argc != 6) || init(argc, argv) == 0)
	{
		write(1, "error\n", 6);
		return (endofprog());
	}
	i = -1;
	pthread_create(&g_data.thread, NULL,
		thread, NULL);
	pthread_join(g_data.thread, NULL);
	i = -1;
	while (++i < g_data.nb)
		kill(g_data.philo[i].pid, 1);
	exit(EXIT_SUCCESS);
	return (0);
}
