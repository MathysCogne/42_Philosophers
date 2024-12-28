/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:29:46 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 23:32:29 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean(t_env *env)
{
	sem_close(env->param->sem_forks);
	sem_close(env->param->sem_state_end);
	sem_close(env->param->sem_printf);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_state_end");
	sem_unlink("/sem_printf");
	gc_clean(env->gc);
}
