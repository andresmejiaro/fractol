/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:13:28 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:58:19 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	newton_color(t_data img, float x, float y, t_cplx *nbs)
{
	float	d[3];

	d[0] = cplx_norm2(cplx_add(nbs[6], nbs[5]));
	d[1] = cplx_norm2(cplx_add(nbs[6], cplx_conj(nbs[5])));
	d[2] = cplx_norm2(cplx_add(nbs[6], nbs[2]));
	if (d[0] < d[1] && d[0] < d[2])
		my_mlx_pixel_put(&img, x, y, 0xA6CEE3);
	else if (d[1] < d[2] && d[1] < d[0])
		my_mlx_pixel_put(&img, x, y, 0x1F78B4);
	else
		my_mlx_pixel_put(&img, x, y, 0xB2DF8A);
}

void	newton_while(t_data img, t_cplx *nbs, float zoom, t_cplx center)
{
	t_list	*poly[2];
	int		x;
	int		y;

	x = 0;
	while (++x < 512)
	{
		y = 0;
		while (++y < 512)
		{
			nbs[4].re = (float)((x - 256) / zoom) / (512 / 4) - center.re;
			nbs[4].im = (float)((y - 256) / zoom) / (512 / 4) - center.im;
			poly[0] = cplx_poly_create(3, nbs[3], nbs[0], nbs[0], nbs[1]);
			poly[1] = cplx_poly_create(2, nbs[0], nbs[0], nbs[3]);
			nbs[6] = (cplx_point_orbit_cvg2(poly[0], poly[1], nbs[4], zoom));
			newton_color(img, x, y, nbs);
			ft_lstclear(&poly[1], free);
			ft_lstclear(&poly[0], free);
		}
	}
}

void	newton(t_data img, float zoom, t_cplx center)
{
	t_cplx	nbs[7];

	nbs[0] = cplx_init(0, 0);
	nbs[1] = cplx_init(2, 0);
	nbs[2] = cplx_init(1, 0);
	nbs[3] = cplx_init(3, 0);
	nbs[5] = cplx_init(0.5, 0.86603);
	newton_while(img, nbs, zoom, center);
}
