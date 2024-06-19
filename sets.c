/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:50:57 by martalop          #+#    #+#             */
/*   Updated: 2024/06/08 21:58:47 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdio.h>

int	mandelbrot_check(char **argv)
{
	if (ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) == 0)
		printf("correct input\n");
	else
	{
		printf("incorrect input\n");
		return (1);
	}
	return (0);
}

int	julia_check(char **argv)
{
	if (ft_strncmp("Julia", argv[1], ft_strlen(argv[1])) == 0)
		printf("correct input\n");
	else
	{
		printf("incorrect input\n");
		return (1);
	}
	return (0);
}
