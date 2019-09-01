/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:04:46 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 22:22:08 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static	t_color	ft_create_color(int x, int y)
{
	t_color	c;

	c.a = x;
	c.b = y;
	return (c);
}

static	t_color	ft_color(t_ptr *p, double iteration)
{
	if (p->color == 0)
		return (ft_create_color(0x0FF00F / iteration,
					0x0F00F0 / iteration));
	else if (p->color == 1)
		return (ft_create_color(0x2D86FF / iteration, 0));
	else if (p->color == 2)
		return (ft_create_color(0xDF00FF / iteration, 0));
	else if (p->color == 3)
		return (ft_create_color(0x2B8BE6 / iteration, 0));
	else if (p->color == 4)
		return (ft_create_color(0xCC6D74 / iteration, 0));
	else if (p->color == 5)
		return (ft_create_color(0x74CC6D / iteration, 0));
	else if (p->color == 6)
		return (ft_create_color(0x40A9F9 / iteration, 0));
	else
		return (ft_create_color(0x4DF940 / iteration, 0));
}

void			*ft_calcul(t_thread *p)
{
	double	iteration;
	int		col;
	int		row;
	t_color	c;

	row = -1;
	while (++row < WIN)
	{
		col = (int)(p->i * WIN / NBTHREAD) - 1;
		while (++col < (int)((p->i + 1) * WIN / NBTHREAD))
		{
			iteration = p->e->type(p->e, col, row);
			c = ft_color(p->e, iteration);
			if (iteration < p->e->max_iter)
				ft_mlx_putpixel(p->e, col, row, c.a);
			else
				ft_mlx_putpixel(p->e, col, row, c.b);
		}
	}
	pthread_exit(NULL);
}

void			ft_begin(t_ptr *p)
{
	pthread_t	thread[NBTHREAD];
	t_thread	div[NBTHREAD];
	int			i;

	i = -1;
	while (++i < NBTHREAD)
	{
		div[i].e = p;
		div[i].i = i;
		pthread_create(&thread[i], NULL, (void*)ft_calcul, &div[i]);
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}

void			ft_draw(t_ptr *p)
{
	ft_bzero(p->data, WIN * WIN * 4);
	ft_begin(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
