/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:37:07 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 20:11:24 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	choose_fractale(char **argv, t_ptr *p)
{
	if (!ft_strcmp(argv[1], "julia"))
		p->type = ft_julia;
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		p->type = ft_mandelbrot;
	else if (!ft_strcmp(argv[1], "negatibrot"))
		p->type = ft_negatibrot;
	else if (!ft_strcmp(argv[1], "tricorne"))
		p->type = ft_tricorne;
	else if (!ft_strcmp(argv[1], "burningship"))
		p->type = ft_burningship;
	else
		p->type = ft_monsieur;
}

int		wrong_parameters(char **argv)
{
	if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "mandelbrot")
			|| !ft_strcmp(argv[1], "negatibrot")
			|| !ft_strcmp(argv[1], "tricorne")
			|| !ft_strcmp(argv[1], "burningship")
			|| !ft_strcmp(argv[1], "xmonsieur"))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_ptr *p;

	if (argc != 2 || wrong_parameters(argv))
		disp_usage();
	ft_init(&p, argv);
	ft_creat_window(p);
	ft_creat_image(p);
	ft_draw(p);
	disp_help();
	mlx_hook(p->win, 2, 0, ft_deal_key, p);
	mlx_hook(p->win, 4, 0, ft_mouse_press, p);
	mlx_hook(p->win, 6, 0, ft_mouse_move, p);
	mlx_loop(p->mlx);
	return (0);
}
