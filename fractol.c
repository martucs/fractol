/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:42:47 by martalop          #+#    #+#             */
/*   Updated: 2024/07/02 20:28:11 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

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
	formula_info->count = 0;
	formula_info->z.real = 0;
	formula_info->z.im = 0;
	formula_info->c.real = 0;
	formula_info->c.im = 0;
}

void	set_display(t_mlx *info, char **argv)
{
	info->ptr = mlx_init();
	if (info->set == 0)
		info->window = mlx_new_window(info->ptr, 1000, 1000, "Mandelbrot set");
	else
		info->window = mlx_new_window(info->ptr, 1000, 1000, "Julia set");
	info->img.ptr = mlx_new_image(info->ptr, 1000, 1000);
	info->img.pixels_ptr = mlx_get_data_addr(info->img.ptr,
			&info->img.bits_per_pixel, &info->img.line_len, &info->img.endian);
	info->x = 0;
	info->y = 0;
	info->zoom = 1.0;
	if (info->set == 1 && argv)
	{
		info->c.real = ft_atoi_d(argv[2]);
		info->c.im = ft_atoi_d(argv[3]);
	}
}

int	parsing(char **argv, int argc)
{
	if (argc < 2)
	{
		write(2, "available sets: Mandelbrot, Julia\n", 34);
		return (2);
	}
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0)
		return (0);
	if (ft_strncmp("Julia", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (argc == 4 && argv[2] && argv[3] && (ft_atoi_d(argv[2]) >= -2
				&& ft_atoi_d(argv[2]) <= 2) && (ft_atoi_d(argv[3]) >= -2
				&& ft_atoi_d(argv[3]) <= 2))
			return (1);
		else
		{
			write(2, "incorrect input\nusage: Julia <value1> <value2>\n", 47);
			return (2);
		}
	}
	else
	{
		write(2, "available sets: Mandelbrot, Julia\n", 34);
		return (2);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	info;

	info.set = parsing(argv, argc);
	if (info.set == 0)
	{
		set_display(&info, argv);
		draw_mandelbrot(&info);
		mlx_key_hook(info.window, keyboard_input, &info);
		mlx_mouse_hook(info.window, mouse_input, &info);
		mlx_hook(info.window, 17, 1L, close_window, &info);
		mlx_loop(info.ptr);
	}
	if (info.set == 1)
	{
		set_display(&info, argv);
		draw_julia(&info);
		mlx_key_hook(info.window, keyboard_input, &info);
		mlx_mouse_hook(info.window, mouse_input, &info);
		mlx_hook(info.window, 17, 1L, close_window, &info);
		mlx_loop(info.ptr);
	}
	if (info.set == 2)
		return (1);
	return (0);
}

// mlx_mouse_hook(info.window, mouse_input, &info);
// esto es lo mismo que usar 'mlx_hook' con Keypress 
// y KeypressMask(2, 1L<<0) o en key up event(3)
