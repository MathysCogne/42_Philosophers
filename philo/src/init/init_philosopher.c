/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:38:32 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:45:23 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philosopher	*create_a_philosopher(t_env *env, size_t id)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->time_last_meal = 0;
	philo->count_to_eat = 0;
	philo->param = env->param;
	pthread_mutex_init(&philo->lock_last_meal, NULL);
	pthread_mutex_init(&philo->lock_count_meal, NULL);
	pthread_create(&philo->thread, NULL, routine_handler, philo);
	return (philo);
}

short	init_philosopher(t_env *env)
{
	size_t	i;

	env->philo = malloc(sizeof(t_philosopher) * env->param->nb_philo);
	if (!env->philo)
		return (1);
	gc_add(env->gc, env->philo);
	i = 0;
	while (i < env->param->nb_philo)
	{
		env->philo[i] = create_a_philosopher(env, i);
		if (!env->philo[i])
			return (1);
		gc_add(env->gc, env->philo[i]);
		i += 2;
	}
	i = 1;
	while (i < env->param->nb_philo)
	{
		env->philo[i] = create_a_philosopher(env, i);
		if (!env->philo[i])
			return (1);
		gc_add(env->gc, env->philo[i]);
		i += 2;
	}
	return (0);
}
