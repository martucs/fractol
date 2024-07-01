/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:11:55 by martalop          #+#    #+#             */
/*   Updated: 2024/06/25 17:58:52 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>

double	get_decimal(const char *str)
{
	int	i;
	int	count;
	double	dec_num;

	i = 0;
	count = 0;
	dec_num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dec_num = dec_num * 10.0 + (str[i] - '0');
		count++;
		i++;
	}
	return (dec_num / pow(10.0, count));
}

double	ft_atoi_d(const char *str)
{
	int	signo;
	double	num;
	int	i;

	i = 0;
	num = 0;
	signo = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' && str[i + 1])
		num = num + get_decimal(&str[i + 1]); 
	return (signo * num);
}

/*#include <stdlib.h>

int	main(void)
{
	const char	*str;

	str = "12.214748364749";
	printf("%.15f\n", ft_atoi_d(str));
	return (0);
}*/
