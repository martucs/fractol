/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:50:57 by martalop          #+#    #+#             */
/*   Updated: 2024/06/20 19:12:36 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdio.h>

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
