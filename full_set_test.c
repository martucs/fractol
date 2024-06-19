/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_set_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:42:47 by martalop          #+#    #+#             */
/*   Updated: 2024/06/19 19:03:06 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

#define XK_Escape 65307

int	mouse_input(int keysym, int x_m, int y_m, t_mlx *mlx_info_dir)
{
	(void)x_m;
	(void)y_m;
	int		x;
	int		y;
	t_point	z;
	t_point	c;
	int		count;
	double	tmp_real;
	t_point	formula_res;
	
	
	if (keysym == 5)
	{
//		printf("x: %d\ny: %d\n", x_m, y_m); // son la posicion del mouse en los pixeles de la pantalla, NO de la imagen
//		printf("mouse keysym %d has been pressed\n", keysym);
	//	zoom in
	//	cambio el rango de -2 a 2 a de -1 a 1 (esto es exagerado)
		mlx_info_dir->zoom *= 1.1;
	}
	else if (keysym == 4)
	{
//		printf("mouse keysym %d has been pressed\n", keysym);
	//	zoom out
		mlx_info_dir->zoom *= 0.9;
	}
	// volver a hacer los calculos y pintar en la misma imagen
	x = 0;
	y = 0;

	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			count = 0;
			z.real = 0;
			z.im = 0;
			c.real = scale_map(x, -2, 2, 0, 999) * mlx_info_dir->zoom;
			if (x == 0 && z.real == 0)
				printf("plano de x-> c real: %f\n", c.real);
			c.im = scale_map(y, -2, 2, 0, 999) * mlx_info_dir->zoom;
			if (y == 0 && z.real == 0)
				printf("plano de y-> c im: %f\n", c.real);
			return (0);

			// FORMULA f(z) = z^2 + c
			while (count < 42)
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
				count++;
			}

			// 2. ELEGIR COLOR SEGUN ESTE RESULTADO
			// 3. PINTAR EL PIXEL EN LA IMAGEN CON my_put_pixel 
			if (sqrt(pow(z.real, 2) + pow(z.im, 2)) > 2 || count == 0)
			{
				put_pixel_to_img(&mlx_info_dir->img, x, y, yellow_color);
				//put_pixel_to_img(&mlx_info_dir->img, x - (x_m - 500) /10, y - (y_m - 500) /10, yellow_color);
			}
			else
			{
				put_pixel_to_img(&mlx_info_dir->img, x, y, cyan_color);
			//	put_pixel_to_img(&mlx_info_dir->img, x - (x_m - 500) /10, y - (y_m - 500) /10, cyan_color);
			}
			x++;
		}
		y++;
	}
	// pushear la imagen a la ventana
	mlx_put_image_to_window(mlx_info_dir->ptr, mlx_info_dir->window, mlx_info_dir->img.ptr, 0, 0);

	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	info;

	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0)
	{
		set_window(&info);
		set_image(&info);
		create_fractal(&info, 0, 0);
		mlx_key_hook(info.window, keyboard_input, &info);
		mlx_mouse_hook(info.window, mouse_input, &info);
		mlx_loop(info.ptr);
	}
	else if (argc == 4 && julia_check(argv) == 0)
	{
		set_window(&info);
		set_image(&info);
//		create_julia(&info, argv[2], argv[3]);  TO DO
		mlx_key_hook(info.window, keyboard_input, &info);
		mlx_mouse_hook(info.window, mouse_input, &info);
		mlx_loop(info.ptr);
	}
	else
		write(1, "available sets: Mandelbrot, Julia\n", 34);
	return (0);


	//-------------------------------------------------------------------

	// CONDICIONES / MANEJO DE VENTANA
	//que queremos que pase si tocamos teclas o el raton

// a hook is a function that gets called whenever an event is triggered

	//crear hook(anzuelo) -> el loop espera hasta que algo(evento) haga saltar el anzuelo/funcion
//	mlx_key_hook(mlx_info.window, esc_close_win, &mlx_info);
	// esto es lo mismo que usar 'mlx_hook' con Keypress y KeypressMask(2, 1L<<0) o en key up event(3)
	
}
