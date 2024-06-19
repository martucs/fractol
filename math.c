/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:46 by martalop          #+#    #+#             */
/*   Updated: 2024/06/18 14:05:26 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

int	check_range(t_point num)
{
	if ((num.real > 2 || num.real < -2) || (num.im > 2 || num.im < -2))
		return (1);
	// FORMULA = raiz cuadrada de (c.real^2 + c.im^2)
	if (sqrt(pow(num.real, 2) + pow(num.im, 2)) > 2)
		return (1);
	return (0);
}

double	scale_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

/*void	show_scaled_map(void)
{
	double	i;
	double	res;

	i = 0;
	while ( i <= 1000)
	{
		res = scale_map(i, -2, 2, 0, 999);
		printf("before: %d, after: %f\n", (int)i, res);
		i++;
	}
}*/

/*int	main()
{
	show_scaled_map();
	return (0);
}*/
