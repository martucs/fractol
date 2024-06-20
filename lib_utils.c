/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:19:37 by martalop          #+#    #+#             */
/*   Updated: 2024/06/20 13:41:33 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

void	put_pixel_to_img(t_img	*img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > 999 || y < 0 || y > 999)
		return ;
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->pixels_ptr)) = color;
}

void	set_display(t_mlx *info)
{
	info->ptr = mlx_init();
	info->window = mlx_new_window(info->ptr, 1000, 1000, "Mandelbrot set");
	info->zoom = 1.0;
	info->img.ptr = mlx_new_image(info->ptr, 1000, 1000);
	info->img.pixels_ptr = mlx_get_data_addr(info->img.ptr, &info->img.bits_per_pixel, &info->img.line_len, &info->img.endian);
}

