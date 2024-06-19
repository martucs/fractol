/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:59:16 by martalop          #+#    #+#             */
/*   Updated: 2024/06/10 21:31:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <math.h>

typedef struct s_point
{
	double	real;
	double	im;
}	t_point;

int	start_mandelbrot(void)
{
	// crear ventana
		// decidir de cuantos pixeles hago la pantalla
	t_point	z;
	t_point	c;
	int		count;
	double	tmp_real;
	int	res;

	count = 0;
	z.real = 0;
	z.im = 0;
	c.real = 1.5;
	c.im = -1.5;
	while (count < 5)
	{
	/*	if(sqrt(pow(c.real, 2)+pow(c.im, 2)) > 2) 
		{
			// el radio se pasa de 2, osea que se sale del rango (circulo) del set
		}*/
		if (count == 0)
		{
			res = sqrt(pow(c.real, 2) + pow(c.im, 2));
			printf("first res: %d\n", res);
		}


		tmp_real = (z.real * z.real) - (z.im * z.im); // x^2 - y^2
		z.im = 2 * z.real * z.im; // 2xyi
		z.real = tmp_real;
		
		//suma de el resultado de z^2 + c
		z.real += c. real;
		z.im += c.im;

	/*	if(sqrt(pow(z.real, 2)+pow(z.im, 2)) > 2) 
		{
			// el radio se pasa de 2, osea que se sale del rango (circulo) del set
		}*/
		if (count > 0)
		{
			res = sqrt(pow(z.real, 2) + pow(z.im, 2));
			printf("%d\n", res);
		}
		printf("iteracion %d:\nz real: %f, imaginary: %f\nc real: %f, imaginary: %f\n", count, z.real, z.im, c.real, c.im); 
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && mandelbrot_check(argv) == 0)
	{
		start_mandelbrot();
//		show_scaled_map();
	}
	else if (argc == 4)
		julia_check(argv);
	else
		write(1, "available sets: Mandelbrot, Julia\n", 34); 
	return (0);
}
