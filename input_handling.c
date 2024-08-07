/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:05:53 by martalop          #+#    #+#             */
/*   Updated: 2024/07/02 17:31:40 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"

int	keyboard_input(int keysym, t_mlx *mlx_info_dir)
{
	if (keysym == XK_ESC)
	{
		mlx_destroy_window(mlx_info_dir->ptr, mlx_info_dir->window);
		exit(0);
	}
	return (0);
}
// HANDLER FUNCTION (keyboard_input)
// los parametros de esta funcion los rellena 'mlx_key_hook'
	//  automaticamente con los argumentos que le paso
// por tanto, keysym se convierte en el numero de la tecla 
	// que yo presiono en el teclado
// XK_Escape lo defino yo porque ya he probado a imprimir y ver 
	// que numero tiene la tecla ESC

int	close_window(t_mlx *info)
{
	mlx_destroy_image(info->ptr, info->img.ptr);
	mlx_destroy_window(info->ptr, info->window);
	mlx_destroy_display(info->ptr);
	exit(0);
	return (0);
}

int	mouse_input(int keysym, int x_m, int y_m, t_mlx *info)
{
	(void)x_m;
	(void)y_m;
	if (keysym == XK_ZOOM_IN)
		info->zoom *= 0.9;
	else if (keysym == XK_ZOOM_OUT)
		info->zoom *= 1.1;
	if (info->set == 0)
		draw_mandelbrot(info);
	else
		draw_julia(info);
	return (0);
}
