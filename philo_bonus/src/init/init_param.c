/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:34:30 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 19:23:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	init_param(t_env *env, char **argv)
{
	env->param = malloc(sizeof(t_param));
	if (!env->param)
		return (1);
	gc_add(env->gc, env->param);
	env->param->nb_philo = ft_atoll(argv[1]);
	env->param->time_die = ft_atoll(argv[2]);
	env->param->time_eat = ft_atoll(argv[3]);
	env->param->time_sleep = ft_atoll(argv[4]);
	if (argv[5])
		env->param->nb_to_eat = ft_atoll(argv[5]);
	else
		env->param->nb_to_eat = -1;
	env->param->start_time = get_time();
	env->param->state_end = 0;
	return (0);
}
