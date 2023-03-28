/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:48:23 by amejia            #+#    #+#             */
/*   Updated: 2023/03/28 17:36:35 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	wclose(int keycode, t_bag *bag)
{
	if (keycode == 53)
	{
		mlx_destroy_window(bag->mlx, bag->win);
		exit(0);
	}
	else if (keycode == 126)
		bag->center.im += 1 / bag->zoom;
	else if (keycode == 125)
		bag->center.im -= 1 / bag->zoom;
	else if (keycode == 123)
		bag->center.re += 1 / bag->zoom;
	else if (keycode == 124)
		bag->center.re -= 1 / bag->zoom;
	else if (keycode == 36)
	{
		bag->center.re = 0;
		bag->center.im = 0;
		bag->zoom = 1;
	}	
	if ((keycode >= 123 && keycode <= 126) || keycode == 36)
		mandelbrot(bag->img, bag->zoom, bag->center);
	mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
	return (0);
}

void	update_mandelbrot(t_bag *bag, int keycode, t_cplx coords, int *x2)
{
	bag->zoom *= (keycode == 5) * 1.5 + (keycode == 4) / 1.5;
	bag->center.re = (4 * (x2[0] - 256)) / (bag->zoom * 512) - coords.re;
	bag->center.im = (4 * (x2[1] - 256)) / (bag->zoom * 512) - coords.im;
	mandelbrot(bag->img, bag->zoom, bag->center);
	mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
}

int	mouse(int keycode, int x, int y, t_bag *bag)
{
	t_cplx	coords;
	int		x2[2];

	x2[0] = x;
	x2[1] = y;
	coords.re = (4 * (x - 256)) / (bag->zoom * 512) - bag->center.re;
	coords.im = (4 * (y - 256)) / (bag->zoom * 512) - bag->center.im;
	if (keycode == 1)
	{
		bag->parameter_julia = coords;
		julia(bag->img_julia, bag->zoom_julia, bag->center_julia, \
			bag->parameter_julia);
		mlx_put_image_to_window(bag->mlx, bag->win2, bag->img_julia.img, 0, 0);
	}
	else if (keycode == 2)
	{
		bag->parameter_cubic = coords;
		cubic(bag->img_cubic, bag->zoom_cubic, bag->center_cubic, \
			bag->parameter_cubic);
		mlx_put_image_to_window(bag->mlx, bag->win3, bag->img_cubic.img, 0, 0);
	}
	if (keycode == 4 || keycode == 5)
		update_mandelbrot(bag, keycode, coords, x2);
	return (0);
}

int	mousecubic(int keycode, int x, int y, t_bag *bag)
{
	t_cplx	coords;

	coords.re = (4 * (x - 256)) / (bag->zoom_cubic * 512) - \
		bag->center_cubic.re;
	coords.im = (4 * (y - 256)) / (bag->zoom_cubic * 512) - \
		bag->center_cubic.im;
	if (keycode == 4 || keycode == 5)
	{
		bag->zoom_cubic *= (keycode == 5) * 1.5 + (keycode == 4) / 1.5;
		bag->center_cubic.re = (4 * (x - 256)) / (bag->zoom_cubic * 512) - \
			coords.re;
		bag->center_cubic.im = (4 * (y - 256)) / (bag->zoom_cubic * 512) - \
			coords.im;
		cubic(bag->img_cubic, bag->zoom_cubic, bag->center_cubic, \
			bag->parameter_cubic);
		mlx_put_image_to_window(bag->mlx, bag->win3, bag->img_cubic.img, 0, 0);
	}
	return (0);
}

int	mousejulia(int keycode, int x, int y, t_bag *bag)
{
	t_cplx	coords;

	coords.re = (4 * (x - 256)) / (bag->zoom_julia * 512) - \
		bag->center_julia.re;
	coords.im = (4 * (y - 256)) / (bag->zoom_julia * 512) - \
		bag->center_julia.im;
	if (keycode == 4 || keycode == 5)
	{
		bag->zoom_julia *= (keycode == 5) * 1.5 + (keycode == 4) / 1.5;
		bag->center_julia.re = (4 * (x - 256)) / (bag->zoom_julia * 512) - \
			coords.re;
		bag->center_julia.im = (4 * (y - 256)) / (bag->zoom_julia * 512) - \
			coords.im;
		julia(bag->img_julia, bag->zoom_julia, bag->center_julia, \
			bag->parameter_julia);
		mlx_put_image_to_window(bag->mlx, bag->win2, bag->img_julia.img, 0, 0);
	}
	return (0);
}
