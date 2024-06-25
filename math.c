/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:46 by martalop          #+#    #+#             */
/*   Updated: 2024/06/25 17:53:58 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

/* int	formula_mandelbrot(int x, int y, t_mlx *info)
{
	int	count;
	t_point	z;
	t_point	c;
	double	tmp_real;
	t_point	formula_res;

	count = 0;
	z.real = 0;
	z.im = 0;
	c.real = scale_map(x, -2, 2, 0, 999) * info->zoom;
	c.im = scale_map(y, -2, 2, 0, 999) * info->zoom;
	while (count++ < 100)
	{
		if (count == 0 && sqrt(pow(c.real, 2) + pow(c.im, 2)) > 2)
			break ;
		tmp_real = (z.real * z.real) - (z.im * z.im); // x^2 - y^2
		z.im = 2 * z.real * z.im; // 2xyi
		z.real = tmp_real;
		formula_res.real = z.real + c.real;
		formula_res.im = z.im + c.im;
		z = formula_res;
		if (sqrt(pow(z.real, 2) + pow(z.im, 2)) > 2)
			break ;
	}
	return (count);
}*/

double	scale_map(double unscaled_num, double new_min, double new_max, double old_max)
{
	int	old_min;

	old_min = 0;
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
