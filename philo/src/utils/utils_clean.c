/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:29:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 01:28:37 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->param->nb_philo)
	{
		pthread_mutex_destroy(&env->param->forks[i]);
		pthread_mutex_destroy(&env->philo[i]->lock_last_meal);
		i++;
	}
	pthread_mutex_destroy(&env->param->lock_forks);
	pthread_mutex_destroy(&env->param->lock_printf);
	pthread_mutex_destroy(&env->param->lock_state_end);
	gc_clean(env->gc);
}