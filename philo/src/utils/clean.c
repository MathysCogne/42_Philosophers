/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:29:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/26 03:33:50 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_env *env)
{
	size_t	i;

	gc_clean(env->gc);
	i = 0;
	while (i < env->param.nb_philo)
	{
		pthread_mutex_destroy(&env->param.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&env->param.printf_lock);
}
