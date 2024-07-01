/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:29:42 by martalop          #+#    #+#             */
/*   Updated: 2024/07/01 23:29:18 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

void	draw_julia(t_mlx *info)
{
	t_math	form_info;

	set_math_struct(&form_info);
	while (info->y < 1000)
	{
		info->x = 0;
		while (info->x < 1000)
		{
			formula_julia(info, &form_info);
			chose_color(info, &form_info);
			info->x++;
		}
		info->y++;
	}
	info->x = 0;
	info->y = 0;
	mlx_put_image_to_window(info->ptr, info->window, info->img.ptr, 0, 0);
}

void	draw_mandelbrot(t_mlx *info)
{
	t_math	form_info;

	set_math_struct(&form_info);
	while (info->y < 1000)
	{
		info->x = 0;
		while (info->x < 1000)
		{
			formula_mandelbrot(info, &form_info);
			chose_color(info, &form_info);
			info->x++;
		}
		info->y++;
	}
	info->x = 0;
	info->y = 0;
	mlx_put_image_to_window(info->ptr, info->window, info->img.ptr, 0, 0);
}
