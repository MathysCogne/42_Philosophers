/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:38:32 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 03:34:46 by mcogne--         ###   ########.fr       */
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
	philo->time_last_meal = get_time();
	philo->count_to_eat = 0;
	philo->param = env->param;
	pthread_create(&philo->thread, NULL, routine_handler, philo);
	return (philo);
}

short	init_philosopher(t_env *env)
{
	size_t	i;

	env->philo = malloc(sizeof(t_philosopher) * env->param.nb_philo);
	if (!env->philo)
		return (1);
	gc_add(env->gc, env->philo);
	i = 0;
	while (i < env->param.nb_philo)
	{
		if (!(env->philo[i] = create_a_philosopher(env, i)))
			return (1);
		i++;
	}
	i = 0;
	while (i < env->param.nb_philo)
	{
		pthread_join(env->philo[i]->thread, NULL);
		i++;
	}
	return (0);
}
