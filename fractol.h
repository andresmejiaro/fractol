/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:30 by amejia            #+#    #+#             */
/*   Updated: 2023/03/28 17:38:26 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>
# ifndef DEBUG
#  define DEBUG 1
# endif

typedef struct s_complex_number{
	float	re;
	float	im;
}	t_cplx;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_bag {
	void	*mlx;
	void	*win;
	void	*win2;
	void	*win3;
	t_data	img;
	t_data	img_julia;
	t_data	img_cubic;
	t_cplx	center;
	t_cplx	center_julia;
	t_cplx	center_cubic;
	t_cplx	parameter_julia;
	t_cplx	parameter_cubic;
	float	zoom;
	float	zoom_julia;
	float	zoom_cubic;
}	t_bag;

t_cplx	cplx_mult(t_cplx a, t_cplx b);
t_cplx	cplx_add(t_cplx a, t_cplx b);
float	cplx_norm2(t_cplx a);
t_cplx	cplx_conj(t_cplx a);
t_cplx	cplx_inv(t_cplx a);
t_cplx	cplx_pow(t_cplx a, int n);
t_list	*cplx_poly_create(unsigned int grade, ...);
t_cplx	cplx_poly_eval(t_list *poly, t_cplx nbr);
t_cplx	cplx_init(float re, float im);
float	cplx_point_orbit_cvg(t_list *poly, t_cplx nbr, float pres);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_data img, float zoom, t_cplx center);
void	julia(t_data img, float zoom, t_cplx center, t_cplx parameter);
void	cubic(t_data img, float zoom, t_cplx center, t_cplx parameter);
int		wclose(int keycode, t_bag *bag);
int		mouse(int keycode, int x, int y, t_bag *bag);
int		red_cross(void);
int		mousejulia(int keycode, int x, int y, t_bag *bag);
int		juliakey(int keycode, t_bag *bag);
int		mousecubic(int keycode, int x, int y, t_bag *bag);
int		cubickey(int keycode, t_bag *bag);

#endif