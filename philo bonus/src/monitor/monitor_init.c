/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:11:06 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 19:23:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	check_nb_eat(t_env *env)
{
	size_t	i;

	i = 0;
	if (get_count_eat(env->philo[0]) >= env->param->nb_to_eat)
	{
		while (i < env->param->nb_philo)
		{
			if (get_count_eat(env->philo[i]) < env->param->nb_to_eat)
				break ;
			if (i == env->param->nb_philo - 1)
			{
				update_state_end(env->param, 1);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

short	check_time_eat(t_env *env)
{
	size_t	i;
	size_t	time_dead;

	i = 0;
	while (i < env->param->nb_philo)
	{
		if (get_delay_last_meal(env->philo[i]) > env->param->time_die
			&& get_count_eat(env->philo[i]) < env->param->nb_to_eat)
		{
			time_dead = get_time_simulation(env->philo[i]);
			update_state_end(env->param, 1);
			usleep(300);
			print_state_philo(env->philo[i], LOG_DIED, time_dead);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*routine_monitor_handler(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (1)
	{
		if (get_state_end(env->param))
			break ;
		if (check_time_eat(env))
			break ;
		if (check_nb_eat(env))
			break ;
		usleep(50);
	}
	return (NULL);
}

short	init_monitor(t_env *env)
{
	pthread_create(&env->monitor_thread, NULL, routine_monitor_handler, env);
	return (0);
}
