/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:36 by amejia            #+#    #+#             */
/*   Updated: 2023/03/25 11:54:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	cplx_mult(t_cplx a, t_cplx b)
{
	float	re;
	float	im;

	re = (a.re * b.re) - (a.im * b.im);
	im = (a.re * b.im) + (a.im * b.re);
	a.re = re;
	a.im = im;
	return (a);
}

t_cplx	cplx_add(t_cplx a, t_cplx b)
{
	float	re;
	float	im;

	re = a.re + b.re;
	im = a.im + b.im;
	a.re = re;
	a.im = im;
	return (a);
}

t_cplx	cplx_pow(t_cplx a, int n)
{
	t_cplx	result;

	if (n < 0)
		return (cplx_pow(cplx_inv(a), -n));
	result.re = 1;
	result.im = 0;
	while (n-- > 0)
		result = cplx_mult(a, result);
	return (result);
}

t_cplx	cplx_conj(t_cplx a)
{
	a.im = -a.im;
	return (a);
}

float	cplx_norm2(t_cplx a)
{
	return (a.re * a.re + a.im * a.im);
}
