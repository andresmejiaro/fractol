/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:01:36 by amejia            #+#    #+#             */
/*   Updated: 2023/03/28 17:29:50 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	cplx_inv(t_cplx a)
{
	t_cplx	result;

	if (cplx_norm2(a) == 0)
		return (a);
	result = cplx_conj(a);
	result.re = result.re / cplx_norm2(a);
	result.im = result.im / cplx_norm2(a);
	return (result);
}

t_cplx	cplx_init(float re, float im)
{
	t_cplx	result;

	result.re = re;
	result.im = im;
	return (result);
}
