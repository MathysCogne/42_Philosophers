/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:43 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/25 17:48:37 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	is_int(size_t size, char **arg)
{
	size_t	i;
	char	*str;

	i = 1;
	while (i < size)
	{
		if (ft_strlen(arg[i]) > 12)
			return (1);
		if (ft_atoll(arg[i]) > INT_MAX || ft_atoll(arg[i]) < INT_MIN)
			return (1);
		str = arg[i];
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (1);
			str++;
		}
		i++;
	}
	return (0);
}