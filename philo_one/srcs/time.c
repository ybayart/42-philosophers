/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:58:50 by ybayart           #+#    #+#             */
/*   Updated: 2019/12/18 16:58:51 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int					ft_nbrlen(unsigned long int nb)
{
	int		i;

	i = 1;
	while (nb > 9)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

unsigned long int	getms(unsigned long int usec)
{
	int					i;
	int					len;

	len = ft_nbrlen(usec);
	i = 0;
	while (len - i > 3)
	{
		i++;
		usec /= 10;
	}
	return (usec);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec;
	ms *= 1000;
	ms += getms(time.tv_usec);
	return (ms);
}
