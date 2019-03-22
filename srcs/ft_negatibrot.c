/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negatibrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:54:02 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 19:56:56 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_negatibrot(t_ptr *p, double col, double row)
{
	double		iteration;
	double		temp;
	t_complex	c;
	t_complex	z;

	iteration = 0.0;
	set_coordinate(&c, p, col, row);
	z = c;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < p->max_iter)
	{
		temp = (z.re * z.re - z.im * z.im) / (z.re * z.re * z.re *
				z.re + z.im * z.im * z.im * z.im + 2 * z.re *
				z.re * z.im * z.im) + c.re;
		z.im = -(2 * z.re * z.im) / (z.re * z.re * z.re * z.re +
				z.im * z.im * z.im * z.im + 2 * z.re * z.re *
				z.im * z.im) + c.im;
		z.re = temp;
		iteration += 1;
	}
	return (iteration);
}
