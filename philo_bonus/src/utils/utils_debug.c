/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:17:47 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 19:23:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	debug_print_param(t_env *env)
{
	printf("List Param:\n");
	printf(" nb_philo: %ld\n", env->param->nb_philo);
	printf(" time_die: %ld\n", env->param->time_die);
	printf(" time_eat: %ld\n", env->param->time_eat);
	printf(" time_sleep: %ld\n", env->param->time_sleep);
	printf(" nb_to_eat: %ld\n", env->param->nb_to_eat);
	printf(" state_end: %d\n", env->param->state_end);
}
