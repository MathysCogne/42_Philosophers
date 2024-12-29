/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:20:58 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 03:03:46 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static short	philo(t_env *env, char **argv)
{
	if (init_param(env, argv))
		return (1);
	if (init_fork(env))
		return (1);
	if (init_philosopher(env))
		return (1);
	if (init_monitor(env))
		return (1);
	wait_processus(env);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if ((argc != 5 && argc != 6) || is_int(argc, argv))
	{
		write(2,
			"Usage: ./philo [number_of_philosophers]"
			"[time_to_die] [time_to_eat] [time_to_sleep] "
			"[number_of_times_each_philosopher_must_eat (optional)]\n",
			138);
		return (1);
	}
	env.gc = gc_init();
	if (philo(&env, argv))
	{
		clean(&env);
		write(2, "Error.\n", 8);
		return (1);
	}
	clean(&env);
	return (0);
}
