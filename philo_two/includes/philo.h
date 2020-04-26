/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:39 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 15:03:40 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>

# include "philo_tp.h"

t_data	g_data;

int					ft_atoi(char *src);
int					init(int argc, char **argv);
void				*thread(void *arg);
unsigned long long	gettime();
void				ft_putnbr(unsigned long long n);
void				msg(unsigned long long time, int act, char *text, int len);
int					ft_str_is_numeric(char *str);

#endif
