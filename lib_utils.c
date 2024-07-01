/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:19:37 by martalop          #+#    #+#             */
/*   Updated: 2024/07/01 23:38:29 by martalop         ###   ########.fr       */
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

void	set_math_struct(t_math *formula_info)
{
//	formula_info->x = 0;
//	formula_info->y = 0;
	formula_info->count = 0;
	formula_info->z.real = 0;
	formula_info->z.im = 0;
	formula_info->c.real = 0;
	formula_info->c.im = 0;
}

void	set_display(t_mlx *info, char **argv)
{
	info->ptr = mlx_init();
	if (ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0)
		info->window = mlx_new_window(info->ptr, 1000, 1000, "Mandelbrot set");
	else
		info->window = mlx_new_window(info->ptr, 1000, 1000, "Julia set");
	info->img.ptr = mlx_new_image(info->ptr, 1000, 1000);
	info->img.pixels_ptr = mlx_get_data_addr(info->img.ptr, &info->img.bits_per_pixel, &info->img.line_len, &info->img.endian);
	info->x = 0;
	info->y = 0;
	info->zoom = 1.0;
	if (info->set == 1 && argv)
	{
		info->c.real = ft_atoi_d(argv[2]);
		info->c.im = ft_atoi_d(argv[3]);
	}
}

