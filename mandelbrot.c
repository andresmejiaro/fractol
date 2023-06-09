/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:40:16 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 19:57:33 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data img, float zoom, t_cplx center)
{
	int		x[2];
	float	n;
	t_cplx	nbs[3];
	t_list	*poly;

	ft_bzero(x, 2 * sizeof(int));
	nbs[0] = cplx_init(0, 0);
	nbs[1] = cplx_init(1, 0);
	while (++x[0] < 512)
	{
		x[1] = 0;
		while (++x[1] < 512)
		{
			nbs[2].re = (float)((x[0] - 256) / zoom) / (512 / 4) - center.re;
			nbs[2].im = (float)((x[1] - 256) / zoom) / (512 / 4) - center.im;
			poly = cplx_poly_create(2, nbs[2], nbs[0], nbs[1]);
			if ((nbs[2].re - 1 / 4) * (nbs[2].re - 1 / 4) + nbs[2].im * \
				nbs[2].im < 1 / 4 - 4 * nbs[2].im * nbs[2].im)
				n = 0;
			else
				n = (cplx_point_orbit_cvg(poly, nbs[0], zoom));
			my_mlx_pixel_put(&img, x[0], x[1], (int)(n * 1000000));
			ft_lstclear(&poly, free);
		}
	}
}

void	cubic(t_data img, float zoom, t_cplx center, t_cplx parameter)
{
	int		x;
	int		y;
	float	n;
	t_cplx	nbs[4];
	t_list	*poly;

	nbs[0] = cplx_init(0, 0);
	nbs[1] = cplx_init(1, 0);
	x = 0;
	while (++x < 512)
	{
		y = 0;
		while (++y < 512)
		{
			nbs[2].re = (float)((x - 256) / zoom) / (512 / 4) - center.re;
			nbs[2].im = (float)((y - 256) / zoom) / (512 / 4) - center.im;
			poly = cplx_poly_create(3, nbs[1], parameter, nbs[0], nbs[1]);
			n = (cplx_point_orbit_cvg(poly, nbs[2], zoom));
			my_mlx_pixel_put(&img, x, y, (int)(n * 5000000));
			ft_lstclear(&poly, free);
		}
		if (x % 150 == 0)
			printf("%d/512\n", x);
	}
}

void	julia(t_data img, float zoom, t_cplx center, t_cplx parameter)
{
	int		x;
	int		y;
	float	n;
	t_cplx	nbs[4];
	t_list	*poly;

	nbs[0] = cplx_init(0, 0);
	nbs[1] = cplx_init(1, 0);
	x = 0;
	while (++x < 512)
	{
		y = 0;
		while (++y < 512)
		{
			nbs[2].re = (float)((x - 256) / zoom) / (512 / 4) - center.re;
			nbs[2].im = (float)((y - 256) / zoom) / (512 / 4) - center.im;
			poly = cplx_poly_create(2, parameter, nbs[0], nbs[1]);
			n = (cplx_point_orbit_cvg(poly, nbs[2], zoom));
			my_mlx_pixel_put(&img, x, y, (int)(n * 400000));
			ft_lstclear(&poly, free);
		}
		if (x % 150 == 0)
			printf("%d/512\n", x);
	}
}
