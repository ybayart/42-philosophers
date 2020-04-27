/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:29 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 16:26:44 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*thread_do(void *arg)
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
	msg(time, act, " is sleeping\n", 13);
	sem_post(g_data.forks);
	sem_post(g_data.forks);
	g_data.philo[act].total_eat += g_data.time_eat;
	usleep((g_data.time_sleep - (time - g_data.philo[act].last_eat -
												g_data.time_eat)) * 1000);
	time = gettime();
	msg(time, act, " is thinking\n", 13);
	if (g_data.state == 5)
		thread_do(arg);
	return (0);
}

int		check_died(int i)
{
	char				eat;
	unsigned long long	time;

	time = gettime();
	eat = 1;
	if (g_data.argc == 6 && eat == 1 &&
		g_data.philo[i].total_eat < g_data.must_eat)
		eat = 0;
	if (g_data.philo[i].last_eat + g_data.time_die < time)
	{
		msg(time, i, " died\n", 6);
		return (endofprog());
	}
	sem_wait(g_data.write);
	if (g_data.argc == 6 && eat == 1)
	{
		endofprog();
		sem_post(g_data.write);
		return (1);
	}
	sem_post(g_data.write);
	return (2);
}

void	*thread(void *arg)
{
	int		i;
	int		ret;

	(void)arg;
	i = 0;
	while (i < g_data.nb)
		if ((g_data.philo[i].pid = fork()) == 0)
		{
			pthread_create(&g_data.thread, NULL, thread_do, (void*)&i);
			while (1)
				if ((ret = check_died(i)) != 2)
					exit(ret);
		}
		else
			i++;
	i = -1;
	while (++i < g_data.nb)
	{
		waitpid(-1, &ret, 0);
		if (WEXITSTATUS(ret) == 0)
			return (0);
	}
	return (0);
}
