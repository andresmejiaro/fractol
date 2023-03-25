/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:30 by amejia            #+#    #+#             */
/*   Updated: 2023/03/25 10:24:43 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <stdarg.h>
# include <mlx.h>
#include <stdio.h>

typedef struct s_complex_number{
	float re;
	float im;
} t_cplx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_bag {
	void 	*mlx;
	void 	*win;
	void	*win2;
	void	*win3;
	t_data	img;
	t_data	imgJulia;
	t_data	imgCubic;
	t_cplx	center;
	t_cplx	centerJulia;
	t_cplx	centerCubic;
	t_cplx	parameterJulia;
	t_cplx	parameterCubic;
	float	zoom;
	float	zoomJulia;
	float	zoomCubic;
}	t_bag;


t_cplx cplx_mult(t_cplx a,t_cplx b);
t_cplx cplx_add(t_cplx a,t_cplx b);
float cplx_norm2(t_cplx a);
t_cplx cplx_conj(t_cplx a);
t_cplx cplx_inv(t_cplx a);
t_cplx cplx_pow(t_cplx a, int n);
t_list *cplx_poly_create(unsigned int grade, ...);
t_cplx cplx_poly_eval(t_list *poly, t_cplx nbr);
float cplx_point_orbit_cvg(t_list *poly, t_cplx nbr, float pres);
void mandelbrot(t_data img,float zoom, t_cplx center);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	wclose(int keycode, t_bag *bag);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	mouse(int keycode,int x,int y, t_bag *bag);
int		red_cross(void);
void julia(t_data img,float zoom, t_cplx center,t_cplx parameter);
int	mousejulia(int keycode,int x,int y, t_bag *bag);
int	juliakey(int keycode, t_bag *bag);
void cubic(t_data img,float zoom, t_cplx center, t_cplx parameter);
int	mousecubic(int keycode,int x,int y, t_bag *bag);
int	cubickey(int keycode, t_bag *bag);

#endif