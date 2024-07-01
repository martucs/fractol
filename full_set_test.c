/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_set_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:42:47 by martalop          #+#    #+#             */
/*   Updated: 2024/07/01 23:35:15 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

int	parsing(char **argv, int argc)
{
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0)
		return (0);
	if (ft_strncmp("Julia", argv[1], ft_strlen(argv[1])) == 0)
	{
		if (argc == 4 && argv[2] && argv[3] && (ft_atoi_d(argv[2]) >= -2
				&& ft_atoi_d(argv[2]) <= 2) && (ft_atoi_d(argv[3]) >= -2
				&& ft_atoi_d(argv[3])))
		{
			printf("correct input for now\n");
			return (1);
		}
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
		set_display(&info, NULL);
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
		// esto es lo mismo que usar 'mlx_hook' con Keypress y KeypressMask(2, 1L<<0) o en key up event(3)
		mlx_loop(info.ptr);
	}
	if (info.set == 2)
		return (1);
	return (0);
}
