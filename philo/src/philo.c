/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:20:58 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/26 03:30:27 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static short	philo(t_env *env, char **argv)
{
	if (parsing(env, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	env.gc = gc_init();
	if ((argc != 5 && argc != 6) || is_int(argc, argv))
	{
		printf("Usage: %s [number_of_philosophers] [time_to_die] "
				"[time_to_eat] [time_to_sleep] "
				"[number_of_times_each_philosopher_must_eat (optional)]\n",
				argv[0]);
		return (1);
	}
	if (philo(&env, argv))
	{
		clean(&env);
		printf("Error.\n");
		return (1);
	}
	return (0);
}
