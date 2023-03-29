/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:34:30 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:54:16 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousenewton(int keycode, int x, int y, t_bag *bag)
{
	t_cplx	coords;

	coords.re = (4 * (x - 256)) / (bag->zoom_newton * 512) - \
		bag->center_newton.re;
	coords.im = (4 * (y - 256)) / (bag->zoom_newton * 512) - \
		bag->center_newton.im;
	if (keycode == 4 || keycode == 5)
	{
		bag->zoom_newton *= (keycode == 5) * 1.5 + (keycode == 4) / 1.5;
		bag->center_newton.re = (4 * (x - 256)) / (bag->zoom_newton * 512) - \
			coords.re;
		bag->center_newton.im = (4 * (y - 256)) / (bag->zoom_newton * 512) - \
			coords.im;
		newton(bag->img_newton, bag->zoom_newton, bag->center_newton);
		mlx_put_image_to_window(bag->mlx, bag->win4, bag->img_newton.img, 0, 0);
	}
	return (0);
}
