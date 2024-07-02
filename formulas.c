/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:29:42 by martalop          #+#    #+#             */
/*   Updated: 2024/07/02 20:37:51 by martalop         ###   ########.fr       */
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
			chose_color_julia(info, &form_info);
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

void	chose_color_julia(t_mlx *info, t_math *form)
{
	if (sqrt(pow(form->z.real, 2) + pow(form->z.im, 2)) > 2 || form->count == 0)
	{
		if (form->count > 40 && form->count < 100)
			put_pixel_to_img(&info->img, info->x, info->y, PINK);
		else if (form->count >= 25 && form->count <= 40)
			put_pixel_to_img(&info->img, info->x, info->y, PURPLE);
		else if (form->count >= 20 && form->count < 25)
			put_pixel_to_img(&info->img, info->x, info->y, MIDDLE_PURPLE);
		else if (form->count < 20)
			put_pixel_to_img(&info->img, info->x, info->y, WARM_BLUE);
	}
	else
		put_pixel_to_img(&info->img, info->x, info->y, PALE_PINK);
}

void	chose_color(t_mlx *info, t_math *form)
{
	if (sqrt(pow(form->z.real, 2) + pow(form->z.im, 2)) > 2 || form->count == 0)
	{
		if (form->count >= 20 && form->count < 50)
			put_pixel_to_img(&info->img, info->x, info->y, PINK);
		else if (form->count < 20)
			put_pixel_to_img(&info->img, info->x, info->y, WARM_BLUE);
	}
	else
		put_pixel_to_img(&info->img, info->x, info->y, PALE_PINK);
}
