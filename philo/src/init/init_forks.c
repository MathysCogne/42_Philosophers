/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:34:02 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:45:06 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	init_fork(t_env *env)
{
	size_t	i;

	env->param->forks = malloc(sizeof(pthread_mutex_t) * env->param->nb_philo);
	if (!env->param->forks)
		return (1);
	gc_add(env->gc, env->param->forks);
	i = 0;
	while (i < env->param->nb_philo)
	{
		pthread_mutex_init(&env->param->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&env->param->lock_forks, NULL);
	pthread_mutex_init(&env->param->lock_printf, NULL);
	pthread_mutex_init(&env->param->lock_state_end, NULL);
	return (0);
}
