/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:23:04 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:53:57 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	red_cross(void)
{
	exit(0);
	return (0);
}

int	juliakey(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win2);
		exit(0);
	}
	else if (keycode == 126)
		bag->center_julia.im += 1 / bag->zoom_julia;
	else if (keycode == 125)
		bag->center_julia.im -= 1 / bag->zoom_julia;
	else if (keycode == 123)
		bag->center_julia.re += 1 / bag->zoom_julia;
	else if (keycode == 124)
		bag->center_julia.re -= 1 / bag->zoom_julia;
	else if (keycode == 36)
	{
		bag->center_julia.re = 0;
		bag->center_julia.im = 0;
		bag->zoom_julia = 1;
	}	
	if ((keycode >= 123 && keycode <= 126) || keycode == 36)
		julia(bag->img_julia, bag->zoom_julia, bag->center_julia, \
			bag->parameter_julia);
	mlx_put_image_to_window(bag->mlx, bag->win2, bag->img_julia.img, 0, 0);
	return (0);
}

int	cubickey(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win2);
		exit(0);
	}
	else if (keycode == 126)
		bag->center_cubic.im += 1 / bag->zoom_cubic;
	else if (keycode == 125)
		bag->center_cubic.im -= 1 / bag->zoom_cubic;
	else if (keycode == 123)
		bag->center_cubic.re += 1 / bag->zoom_cubic;
	else if (keycode == 124)
		bag->center_cubic.re -= 1 / bag->zoom_cubic;
	else if (keycode == 36)
	{
		bag->center_cubic.re = 0;
		bag->center_cubic.im = 0;
		bag->zoom_cubic = 1;
	}	
	if ((keycode >= 123 && keycode <= 126) || keycode == 36)
		cubic(bag->img_cubic, bag->zoom_cubic, bag->center_cubic, \
			bag->parameter_cubic);
	mlx_put_image_to_window(bag->mlx, bag->win3, bag->img_cubic.img, 0, 0);
	return (0);
}

int	newtonkey(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win4);
		exit(0);
	}
	else if (keycode == 126)
		bag->center_newton.im += 1 / bag->zoom_newton;
	else if (keycode == 125)
		bag->center_newton.im -= 1 / bag->zoom_newton;
	else if (keycode == 123)
		bag->center_newton.re += 1 / bag->zoom_newton;
	else if (keycode == 124)
		bag->center_newton.re -= 1 / bag->zoom_newton;
	else if (keycode == 36)
	{
		bag->center_newton.re = 0;
		bag->center_newton.im = 0;
		bag->zoom_newton = 1;
	}	
	if ((keycode >= 123 && keycode <= 126) || keycode == 36)
		newton(bag->img_newton, bag->zoom_newton, bag->center_newton);
	mlx_put_image_to_window(bag->mlx, bag->win4, bag->img_newton.img, 0, 0);
	return (0);
}
