/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tricorne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:53:15 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 18:53:42 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	ft_tricorne(t_ptr *p, double col, double row)
{
	double		iteration;
	t_complex	c;
	t_complex	z;

	iteration = 0.0;
	z = ft_create_complex(0, 0);
	set_coordinate(&c, p, col, row);
	while (z.re * z.re + z.im * z.im <= 4 && iteration < p->max_iter)
	{
		ft_power_complex(&z, &c, p->tricorne_type);
		iteration += 1;
	}
	return (iteration);
}
