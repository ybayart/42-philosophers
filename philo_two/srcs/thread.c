/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:29 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 14:48:41 by ybayart          ###   ########.fr       */
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

void	*thread(void *arg)
{
	int					act;
	unsigned long long	time;

	act = *(int*)arg;
	sem_wait(g_data.lock);
	sem_wait(g_data.forks);
	msg(gettime(), act, " has taken a fork\n", 18);
	sem_wait(g_data.forks);
	msg((time = gettime()), act, " has taken a fork\n", 18);
	sem_post(g_data.lock);
	g_data.philo[act].last_eat = time;
	msg(time, act, " is eating\n", 11);
	usleep(g_data.time_eat * 1000);
	time = gettime();
	g_data.philo[act].total_eat += g_data.time_eat;
	msg(time, act, " is sleeping\n", 13);
	sem_post(g_data.forks);
	sem_post(g_data.forks);
	usleep((g_data.time_sleep - (time - g_data.philo[act].last_eat -
												g_data.time_eat)) * 1000);
	time = gettime();
	msg(time, act, " is thinking\n", 13);
	if (g_data.state == 5)
		thread(arg);
	return (0);
}
