/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:38:32 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 03:05:31 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static short	start_routine(t_env *env, size_t id)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		routine_handler(env->philo[id]);
		exit(0);
	}
	env->philo[id]->pid = pid;
	return (0);
}

static t_philosopher	*create_a_philosopher(t_env *env, size_t id)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->pid = -1;
	philo->id = id;
	philo->time_last_meal = 0;
	philo->count_to_eat = 0;
	philo->param = env->param;
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
		gc_add(env->gc, env->philo[i]);
		start_routine(env, i);
		i += 2;
	}
	i = 1;
	while (i < env->param->nb_philo)
	{
		env->philo[i] = create_a_philosopher(env, i);
		gc_add(env->gc, env->philo[i]);
		start_routine(env, i);
		i += 2;
	}
	return (0);
}
