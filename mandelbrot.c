/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:29:42 by martalop          #+#    #+#             */
/*   Updated: 2024/06/20 13:44:19 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

void	draw_mandelbrot(t_mlx *info, int x, int y)
{
	t_point	z;
	t_point	c;
	int		count;
	double	tmp_real;
	t_point	formula_res;
	
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			count = 0;
			z.real = 0;
			z.im = 0;
			c.real = scale_map(x, -2, 2, 0, 999) * info->zoom;
			c.im = scale_map(y, -2, 2, 0, 999) * info->zoom;
			// FORMULA f(z) = z^2 + c
			while (count < 100)
			{
				if (count == 0 && sqrt(pow(c.real, 2) + pow(c.im, 2)) > 2)
					break ;
				// es la primera iteracion y el radio del rango se pasa de 2 en el punto que nos dan (c)
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
			//	printf("%dth iteration-> real: %f, im: %f\n", count, formula_res.real, formula_res.im);
			if (sqrt(pow(z.real, 2) + pow(z.im, 2)) > 2 || count == 0)
			{
				put_pixel_to_img(&info->img, x, y, yellow_color);
			//	printf("    punto fuera de rango en: (%d, %d)\n", x, y);
			}
			else
			{
				put_pixel_to_img(&info->img, x, y, cyan_color);
			} 
			x++;
		}
		y++;
	}

	//enviar la imagen a la ventana
	mlx_put_image_to_window(info->ptr, info->window, info->img.ptr, 0, 0);
}
