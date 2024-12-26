/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:34 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/26 18:42:11 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_handler(void *philo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo;
	while (1)
	{
	}
	(void)philo;
	printf("COUCOU !");
	return (NULL);
}

t_philosopher	create_a_philosopher(t_env *env, size_t id)
{
	t_philosopher	philo;

	philo.id = id;
	printf("%zu", id);
	pthread_create(&philo.thread, NULL, routine_handler, &philo);
	philo.time_last_meal = 0;
	philo.count_to_eat = 0;
	philo.param = env->param;
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
		env->philo[i] = create_a_philosopher(env, i);
		i++;
	}
	return (0);
}

short	init_fork(t_env *env)
{
	size_t	i;

	env->param.forks = malloc(sizeof(pthread_mutex_t) * env->param.nb_philo);
	if (!env->param.forks)
		return (1);
	gc_add(env->gc, env->param.forks);
	i = 0;
	while (i < env->param.nb_philo)
	{
		pthread_mutex_init(&env->param.forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&env->param.printf_lock, NULL);
	return (0);
}

static void	get_param(t_env *env, char **argv)
{
	env->param.nb_philo = ft_atoll(argv[1]);
	env->param.time_die = ft_atoll(argv[2]);
	env->param.time_eat = ft_atoll(argv[3]);
	env->param.time_sleep = ft_atoll(argv[4]);
	if (argv[5])
		env->param.nb_to_eat = ft_atoll(argv[5]);
	else
		env->param.nb_to_eat = -1;
	env->param.state_end = 0;
}

// TODO: GESTION DE QUELLE VALUE PEUX ETRE A ZERO OU UN (Ex nb philo 1,
// TODO: 	time to eat 0 ?)
short	parsing(t_env *env, char **argv)
{
	get_param(env, argv);
	debug_print_param(env);
	if (init_fork(env))
		return (1);
	if (init_philosopher(env))
		return (1);
	return (0);
}