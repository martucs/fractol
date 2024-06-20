/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:49:29 by martalop          #+#    #+#             */
/*   Updated: 2024/06/20 19:12:15 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <math.h>
#include <stdio.h>

#define XK_Escape 65307
#define cyan_color 0x0000ffff
#define yellow_color 0x00ffff00
#define deep_blue_color 0x0000008b

typedef struct	s_img
{
	void	*ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef	struct	s_mlx
{
	void	*ptr;
	void	*window;
	t_img	img;
	double	zoom;
}	t_mlx;


typedef struct s_point
{
	double	real;
	double	im;
}	t_point;

int		julia_check(char **argv);
int		start_mandelbrot(void);
double	scale_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
//void	show_scaled_map(void);
int		keyboard_input(int keysym, t_mlx *mlax_info_dir);
void	set_display(t_mlx *info);
void	draw_mandelbrot(t_mlx *info, int x, int y);
void	put_pixel_to_img(t_img	*img, int x, int y, int color);

#endif
