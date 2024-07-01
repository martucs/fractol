/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:51:46 by martalop          #+#    #+#             */
/*   Updated: 2024/07/01 23:32:06 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

void	chose_color(t_mlx *info, t_math *form)
{
	if (sqrt(pow(form->z.real, 2) + pow(form->z.im, 2)) > 2 || form->count == 0)
	{
		if (form->count > 20 && form->count < 100)
			put_pixel_to_img(&info->img, info->x, info->y, pink);
		else if (form->count < 20)
			put_pixel_to_img(&info->img, info->x, info->y, warm_blue);
	}
	else
		put_pixel_to_img(&info->img, info->x, info->y, pale_pink);
}

void	formula_mandelbrot(t_mlx *info, t_math *form)
{
	double	tmp_real;

	form->count = 0;
	form->z.real = 0;
	form->z.im = 0;
	form->c.real = scale_map(info->x, -2, 2, 999) * info->zoom;
	form->c.im = scale_map(info->y, -2, 2, 999) * info->zoom;
	if (form->c.real > 2 || form->c.real < -2 || form->c.im > 2 || form->c.im < -2)
		return ;
	while (form->count++ < 40)
	{
		if (form->count == 0 && sqrt(pow(form->c.real, 2) + pow(form->c.im, 2)) > 2)
			break ;
		tmp_real = (form->z.real * form->z.real) - (form->z.im * form->z.im);
		form->z.im = 2 * form->z.real * form->z.im;
		form->z.real = tmp_real;
		form->z.real = form->z.real + form->c.real;
		form->z.im = form->z.im + form->c.im;
		if (sqrt(pow(form->z.real, 2) + pow(form->z.im, 2)) > 2)
			break ;
	}
}

void	formula_julia(t_mlx *info, t_math *form)
{
	double	tmp_real;

	form->count = 0;
	form->z.real = scale_map(info->x, -2, 2, 999) * info->zoom;
	form->z.im = scale_map(info->y, -2, 2, 999) * info->zoom;
	
	form->c.real = info->c.real;
	form->c.im = info->c.im;
	if (form->c.real > 2 || form->c.real < -2 || form->c.im > 2 || form->c.im < -2)
		return ;
	while (form->count++ < 40)
	{
		if (form->count == 0 && sqrt(pow(form->c.real, 2) + pow(form->c.im, 2)) > 2)
			break ;
		tmp_real = (form->z.real * form->z.real) - (form->z.im * form->z.im);
		form->z.im = 2 * form->z.real * form->z.im;
		form->z.real = tmp_real;
		form->z.real = form->z.real + form->c.real;
		form->z.im = form->z.im + form->c.im;
		if (sqrt(pow(form->z.real, 2) + pow(form->z.im, 2)) > 2)
			break ;
	}
}

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
