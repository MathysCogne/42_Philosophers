/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:20:58 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/25 17:55:55 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Your(s) program(s) should take the following arguments:
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// ◦number_of_philosophers: The number of philosophers and also the number
// of forks.
// ◦time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
// milliseconds since the beginning of their last meal or the beginning of the sim-
// ulation, they die.
// ◦time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
// During that time, they will need to hold two forks.
// ◦time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
// ◦number_of_times_each_philosopher_must_eat (optional argument): If all
// philosophers have eaten at least number_of_times_each_philosopher_must_eat
// times, the simulation stops. If not specified, the simulation stops when a
// philosopher dies

short	philo(char **argv)
{
	
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Usage: %s [number_of_philosophers] [time_to_die] "
				"[time_to_eat] [time_to_sleep] "
				"[number_of_times_each_philosopher_must_eat (optional)]\n",
				argv[0]);
		return (1);
	}
	if (philo(argv))
	{
		printf("Error.\n");
		return (1);
	}
	return (0);
}
