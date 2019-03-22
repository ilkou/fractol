/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monsieur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:00:29 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 19:02:38 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_monsieur(t_ptr *p, double col, double row)
{
	double		iteration;
	t_complex	c;
	t_complex	z;

	iteration = 0.0;
	z = ft_create_complex(0, 0);
	set_coordinate(&c, p, col, row);
	while (z.re * z.re + z.im * z.im <= 4 && iteration < p->max_iter)
	{
		z.re = z.re > 0 ? z.re : -z.re;
		ft_power_complex(&z, &c, -3);
		iteration += 1;
	}
	return (iteration);
}
