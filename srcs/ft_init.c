/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:02:31 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/23 11:27:28 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
	if (x >= 0 && x < WIN
			&& y >= 0 && y < WIN)
	{
		p->data[y * (int)WIN + x] = color;
	}
}

void	ft_creat_window(t_ptr *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN, WIN, "fractol");
}

void	ft_creat_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, WIN, WIN);
	p->data = (int*)mlx_get_data_addr(p->img, p->bpp, p->size, p->endian);
}

void	ft_init_switch(t_ptr **p)
{
	(*p)->zoom = 1.0;
	(*p)->max_iter = 40.0;
	(*p)->x1_max = (WIN - WIN / 2.0) * 4.0 / WIN;
	(*p)->x2_max = (WIN - WIN / 2.0) * 4.0 / WIN;
	(*p)->x1_min = (0 - WIN / 2.0) * 4.0 / WIN;
	(*p)->x2_min = (0 - WIN / 2.0) * 4.0 / WIN;
}

void	ft_init(t_ptr **p, char **argv)
{
	*p = (struct s_ptr*)malloc(sizeof(struct s_ptr));
	choose_fractale(argv, *p);
	ft_init_switch(p);
	(*p)->img = NULL;
	(*p)->mlx = NULL;
	(*p)->data = NULL;
	(*p)->win = NULL;
	(*p)->bpp = malloc(4);
	(*p)->size = malloc(4);
	(*p)->endian = malloc(4);
	(*p)->seed.x = -0.4;
	(*p)->seed.y = 0.6;
	(*p)->stop = 0;
	(*p)->color = 0;
	(*p)->julia_type = 0;
	(*p)->tricorne_type = -2;
	(*p)->mandelbrot_type = 2;
}
