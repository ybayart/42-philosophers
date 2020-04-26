/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:25 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 16:19:32 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		endofprog(void)
{
	if (g_data.state >= 4)
		free(g_data.philo);
	return (0);
}

int		main_do(int argc)
{
	int					i;
	char				eat;
	unsigned long long	time;

	i = -1;
	time = gettime();
	eat = 1;
	while (++i < g_data.nb)
	{
		if (argc == 6 && eat == 1 &&
			g_data.philo[i].total_eat < g_data.must_eat)
			eat = 0;
		if (g_data.philo[i].last_eat + g_data.time_die < time)
		{
			msg(time, i, " died\n", 6);
			return (endofprog());
		}
	}
	sem_wait(g_data.write);
	if (argc == 6 && eat == 1)
		return (endofprog());
	sem_post(g_data.write);
	return (1);
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
	while (++i < g_data.nb)
		pthread_create(&g_data.philo[i].thread, NULL,
			thread, (void *)&g_data.philo[i].id);
	while (1)
	{
		if (main_do(argc) != 1)
			break ;
	}
	return (0);
}
