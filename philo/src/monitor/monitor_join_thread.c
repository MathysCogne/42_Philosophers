/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_join_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 22:52:45 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	join_thread(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->param->nb_philo)
	{
		pthread_join(env->philo[i]->thread, NULL);
		i++;
	}
	pthread_join(env->monitor_thread, NULL);
	return (0);
}
