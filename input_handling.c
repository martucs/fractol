/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:05:53 by martalop          #+#    #+#             */
/*   Updated: 2024/06/18 19:39:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "fractol.h"
#include "libft/libft.h"

int	keyboard_input(int keysym, t_mlx *mlx_info_dir)
{
	printf("Key num(keysym): %d\n", keysym);
	if (keysym == XK_Escape)
	{
		printf("%d, ESC key has been pressed\n", keysym);
		mlx_destroy_window(mlx_info_dir->ptr, mlx_info_dir->window);
		// liberar memoria
		// salir del programa
	}
	return (0);
}
// HANDLER FUNCTION (keyboard_input)
// los parametros de esta funcion los rellena 'mlx_key_hook' automaticamente con los argumentos que le paso
// por tanto, keysym se convierte en el numero de la tecla que yo presiono en el teclado
// XK_Escape lo defino yo porque ya he probado a imprimir y ver que numero tiene la tecla ESC

/*int	mouse_input(int keysym, int x_m, int y_m, t_mlx *mlx_info_dir)
{
	if (keysym == 5)
	{
		printf("x: %d\ny: %d\n", x_m, y_m); // son la posicion del mouse en los pixeles de la pantalla, NO de la imagen
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
	return (0);
}*/
