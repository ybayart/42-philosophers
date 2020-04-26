/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:39 by ybayart           #+#    #+#             */
/*   Updated: 2020/01/06 15:42:42 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

# include <stdio.h>

# include "philo_tp.h"

t_data	g_data;

int					ft_atoi(char *src);
int					init(int argc, char **argv);
void				*thread(void *arg);
unsigned long long	gettime();
void				ft_putnbr(unsigned long long n);
void				msg(unsigned long long time, int act, char *text, int len);
int					endofprog(void);

#endif
