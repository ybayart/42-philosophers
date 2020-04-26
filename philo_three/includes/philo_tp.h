/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:43 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 15:41:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TP_H
# define PHILO_TP_H

typedef struct	s_philo
{
	unsigned long long	last_eat;
	int					total_eat;
	pid_t				pid;
}				t_philo;

typedef struct	s_data
{
	int			nb;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			must_eat;
	char		state;
	int			argc;
	sem_t		*forks;
	sem_t		*write;
	sem_t		*lock;
	t_philo		*philo;
	pthread_t	thread;
}				t_data;

#endif
