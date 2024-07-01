/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:49:29 by martalop          #+#    #+#             */
/*   Updated: 2024/07/01 23:35:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>

# define XK_Escape 65307
# define XK_ZoomIN 4
# define XK_ZoomOUT 5
# define cyan_color 0x0000ffff
# define yellow_color 0x00ffff00
# define deep_blue_color 0x0000008b
# define pale_pink 0x00FFCCCC
# define pink 0x00FF9999
# define white 0x00FFFFFF
# define almost_white 0x00F0DCDC
# define chill_blue 0x82D2FF
# define warm_blue 0x280096

typedef struct	s_img
{
	void	*ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_point
{
	double	real;
	double	im;
}	t_point;


typedef	struct	s_mlx
{
	void	*ptr;
	void	*window;
	t_img	img;
	int		x; // window length
	int		y; // window height
	int		set;
	t_point c;
	double	zoom;
}	t_mlx;

typedef struct	s_math
{
//	int	x;
//	int	y;
	int count;
//	double	zoom;
	t_point z;
	t_point	c;
}	t_math;

int		julia_check(char **argv);
int		start_mandelbrot(void);
double	scale_map(double unscaled_num, double new_min, double new_max, double old_max);
//void	show_scaled_map(void);
int		mouse_input(int keysym, int x_m, int y_m, t_mlx *info);
int		keyboard_input(int keysym, t_mlx *mlax_info_dir);
void	set_display(t_mlx *info, char **argv);
void	set_math_struct(t_math *formula_info);
void	formula_mandelbrot(t_mlx *info, t_math *form);
void	formula_julia(t_mlx *info, t_math *form);
void	draw_mandelbrot(t_mlx *info);
void	draw_julia(t_mlx *info);
void	put_pixel_to_img(t_img	*img, int x, int y, int color);
int		close_window(t_mlx *info);
void	chose_color(t_mlx *info, t_math *form_info);
//int		mouse_input(int keysym, int x_m, int y_m, t_mlx *info);

#endif
