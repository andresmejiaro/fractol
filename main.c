/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:38:58 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:55:39 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bag_init(t_bag *bag)
{
	bag->center.re = 0;
	bag->center.im = 0;
	bag->zoom = 1;
	bag->zoom_julia = 1;
	bag->zoom_cubic = 1;
	bag->parameter_julia = bag->center;
	bag->parameter_cubic = bag->center;
	bag->center_julia = bag->center;
	bag->center_cubic = bag->center;
	bag->mlx = mlx_init();
	bag->img.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img_julia.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img_cubic.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img.addr = mlx_get_data_addr(bag->img.img, &(bag->img.bits_per_pixel), \
		&(bag->img.line_length), &(bag->img.endian));
	bag->img_julia.addr = mlx_get_data_addr(bag->img_julia.img, \
		&(bag->img_julia.bits_per_pixel), &(bag->img_julia.line_length), \
		&(bag->img_julia.endian));
	bag->img_cubic.addr = mlx_get_data_addr(bag->img_cubic.img, \
		&(bag->img_cubic.bits_per_pixel), &(bag->img_cubic.line_length), \
		&(bag->img_cubic.endian));
}

void	bag_init2(t_bag *bag)
{
	bag->zoom_newton = 1;
	bag->center_newton = cplx_init(0, 0);
	bag->img_newton.img = mlx_new_image(bag->mlx, 512, 512);
	bag->img_newton.addr = mlx_get_data_addr(bag->img_newton.img, \
		&(bag->img_newton.bits_per_pixel), &(bag->img_newton.line_length), \
		&(bag->img_newton.endian));
}

void	windows_init_2(t_bag *bag)
{
	if (bag->mode == 0 || bag->mode == 4)
	{
		bag->win = mlx_new_window(bag->mlx, 512, 512, "Mandelbrot");
		mandelbrot(bag->img, bag->zoom, bag->center);
		mlx_put_image_to_window(bag->mlx, bag->win, bag->img.img, 0, 0);
		mlx_hook(bag->win, 2, 0, wclose, bag);
		mlx_hook(bag->win, 4, 0, mouse, bag);
		mlx_hook(bag->win, 17, 0L, red_cross, bag);
	}
	if (bag->mode == 1 || bag->mode == 4)
	{
		bag->win2 = mlx_new_window(bag->mlx, 512, 512, "Julia");
		julia(bag->img_julia, bag->zoom_julia, bag->center_julia, \
			bag->parameter_julia);
		mlx_put_image_to_window(bag->mlx, bag->win2, bag->img_julia.img, 0, 0);
		mlx_hook(bag->win2, 2, 0, juliakey, bag);
		mlx_hook(bag->win2, 4, 0, mousejulia, bag);
		mlx_hook(bag->win2, 17, 0L, red_cross, bag);
	}
}

void	windows_init(t_bag *bag)
{
	windows_init_2(bag);
	if (bag->mode == 2 || bag->mode == 4)
	{
		bag->win3 = mlx_new_window(bag->mlx, 512, 512, "Cubic");
		cubic(bag->img_cubic, bag->zoom_cubic, bag->center_cubic, \
			bag->parameter_cubic);
		mlx_put_image_to_window(bag->mlx, bag->win3, bag->img_cubic.img, 0, 0);
		mlx_hook(bag->win3, 2, 0, cubickey, bag);
		mlx_hook(bag->win3, 4, 0, mousecubic, bag);
		mlx_hook(bag->win3, 17, 0L, red_cross, bag);
	}
	if (bag->mode == 3 || bag->mode == 4)
	{
		bag->win4 = mlx_new_window(bag->mlx, 512, 512, "Newton");
		newton(bag->img_newton, bag->zoom_newton, bag->center_newton);
		mlx_put_image_to_window(bag->mlx, bag->win4, bag->img_newton.img, 0, 0);
		mlx_hook(bag->win4, 2, 0, newtonkey, bag);
		mlx_hook(bag->win4, 4, 0, mousenewton, bag);
		mlx_hook(bag->win4, 17, 0L, red_cross, bag);
	}
	mlx_loop(bag->mlx);
}

int	main(int argc, char **argv)
{
	t_bag	bag;

	bag_init(&bag);
	bag_init2(&bag);
	window_launcher(argc, argv, &bag);
	return (0);
}
