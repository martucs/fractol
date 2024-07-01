/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:50:57 by martalop          #+#    #+#             */
/*   Updated: 2024/06/26 18:09:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdio.h>

int	julia_check(char **argv)
{
	if (ft_strncmp("Julia", argv[1], ft_strlen("Julia")) == 0)
	{
		if ((ft_atoi_d(argv[2]) >= -2 && ft_atoi_d(argv[2]) <= 2) && (ft_atoi_d(argv[3]) >= -2 && ft_atoi_d(argv[3])))
		{
			printf("%f\n", ft_atoi_d(argv[2]));
			printf("correct input\n");
		}
		else
		{
			printf("incorrect input\nusage: Julia <value1 from -2 to 2> <value2 from -2 to 2>\n");
			return (1);
		}

	}
	else
	{
		printf("incorrect input\n");
		return (1);
	}
	return (0);
}
