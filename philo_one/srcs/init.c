/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:58:38 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 17:07:54 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init(int argc, char **argv)
{
	int					i;
	unsigned long long	time;

	g_data.nb = ft_atoi(argv[1]);
	g_data.time_die = ft_atoi(argv[2]);
	g_data.time_eat = ft_atoi(argv[3]);
	g_data.time_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&g_data.write, NULL);
	pthread_mutex_init(&g_data.lock, NULL);
	if (argc == 6)
		g_data.must_eat = ft_atoi(argv[5]);
	if ((g_data.philo = malloc(sizeof(t_philo) * g_data.nb)) == NULL)
		return (0);
	g_data.state++;
	i = -1;
	time = gettime();
	while (++i < g_data.nb)
	{
		g_data.philo[i].id = i;
		g_data.philo[i].last_eat = time;
		g_data.philo[i].total_eat = 0;
		pthread_mutex_init(&g_data.philo[i].lock, NULL);
	}
	return (1);
}
