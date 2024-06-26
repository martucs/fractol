/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:51 by martalop          #+#    #+#             */
/*   Updated: 2024/06/17 13:29:15 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include "fractol.h"
#include <stdio.h>

int	main()
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		y;
	t_point	z;
	t_point	c;
	int		count;
	double	tmp_real;
	t_point	formula_res;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1500, 1000, "new window :)");
	
	c.im = 1.9;
	while (c.im > -2)
	{
		c.real = -1.9;
		while (c.real < 2)
		{
			count = 0;
			z.real = 0;
			z.im = 0;
			x = scale_map(c.real, 0, 1499, -2, 2);
			y = scale_map(-c.im, 0, 999, -2, 2);
			// FORMULA f(z) = z^2 + c
			while (count < 100)
			{
				if ((z.real > 2 || z.real < -2) || (z.im > 2 || z.im < -2))
					break ; // en cuanto se sale de -2 o 2 dejamos de calcular y pintamos el punto
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
			// CHECK DEL RESULTADO DE LA FORMULA
			// ELEGIR COLOR SEGUN ESTE RESULTADO
			// PINTAR EL PIXEL
			printf("%dth iteration-> real: %f, im: %f\n", count, formula_res.real, formula_res.im);
			if (sqrt(pow(z.real, 2) + pow(z.im, 2)) > 2 || count == 0)
			{
				mlx_pixel_put(mlx_ptr, window, x, y, yellow_color);
				printf("    punto fuera de rango en: (%d, %d)\n", x, y);
			}
			else
				mlx_pixel_put(mlx_ptr, window, x, y, cyan_color);
			c.real += 0.01;
		}
		c.im -= 0.01;
	}
	mlx_loop(mlx_ptr);
	return (0);

}


/*int	main()
{
	void	*mlx_ptr;
	void	*window;
	int		color;
	int		x;
	int		y;

	x = 500;
	y = 400;
	color = 0x00FF0000;
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1500, 1000, "new window :)");
	while (x < 1000)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, color);
		mlx_pixel_put(mlx_ptr, window, x, y + 50, color);
		x++;
	}
	mlx_loop(mlx_ptr);
	mlx_loop_end(mlx_ptr);
	return (0);
}*/
