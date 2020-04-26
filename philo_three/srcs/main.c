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
	if (argc != 5 && argc != 6)
	{
		write(1, "error\n", 6);
		return (endofprog());
	}
	if (init(argc, argv) == 0)
		return (endofprog());
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
