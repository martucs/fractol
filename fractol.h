/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:49:29 by martalop          #+#    #+#             */
/*   Updated: 2024/07/02 20:37:06 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>

# define XK_ESC 65307
# define XK_ZOOM_IN 4
# define XK_ZOOM_OUT 5
# define CYAN 0x0000ffff
# define YELLOW 0x00ffff00
# define PALE_PINK 0x00FFCCCC
# define PINK 0x00FF9999
# define DARK_PINK 0x00FF7882
# define WHITE 0x00FFFFFF
# define ALMOST_WHITE 0x00F0DCDC
# define CHIL_BLUE 0x82D2FF
# define WARM_BLUE 0x280096
# define DEEPER_BLUE 0x001466
# define PURPLE 0x660099
# define MIDDLE_PURPLE 0x6633CC

typedef struct s_img
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

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	t_img	img;
	int		x; // window length
	int		y; // window height
	int		set;
	t_point	c;
	double	zoom;
}	t_mlx;

typedef struct s_math
{
	int		count;
	t_point	z;
	t_point	c;
}	t_math;

int		julia_check(char **argv);
int		start_mandelbrot(void);
double	scale_map(double unscaled_num, double new_min,
			double new_max, double old_max);
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
void	chose_color_julia(t_mlx *info, t_math *form_info);
double	elev2(double num);

#endif
