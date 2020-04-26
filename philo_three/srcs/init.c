/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:20 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 15:41:57 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_sem(void)
{
	sem_unlink("forks");
	if ((g_data.forks = sem_open("forks", O_CREAT, S_IRWXU, g_data.nb)) ==
																	SEM_FAILED)
		return (0);
	g_data.state++;
	sem_unlink("write");
	if ((g_data.write = sem_open("write", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		return (0);
	g_data.state++;
	sem_unlink("lock");
	if ((g_data.lock = sem_open("lock", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		return (0);
	g_data.state++;
	return (1);
}

int		init(int argc, char **argv)
{
	int					i;
	unsigned long long	time;

	g_data.nb = ft_atoi(argv[1]);
	g_data.time_die = ft_atoi(argv[2]);
	g_data.time_eat = ft_atoi(argv[3]);
	g_data.time_sleep = ft_atoi(argv[4]);
	g_data.argc = argc;
	if (init_sem() == 0)
		return (0);
	if (argc == 6)
		g_data.must_eat = ft_atoi(argv[5]);
	if ((g_data.philo = malloc(sizeof(t_philo) * g_data.nb)) == NULL)
		return (0);
	g_data.state++;
	i = -1;
	time = gettime();
	while (++i < g_data.nb)
	{
		g_data.philo[i].last_eat = time;
		g_data.philo[i].total_eat = 0;
	}
	g_data.state++;
	return (1);
}
