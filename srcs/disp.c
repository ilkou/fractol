/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:04:01 by oouklich          #+#    #+#             */
/*   Updated: 2019/03/22 21:28:00 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	disp_help(void)
{
	ft_putstr("\t\t-- Fractol Menu -- \n");
	ft_putstr("J -> julia\n");
	ft_putstr("M -> mandelbrot\n");
	ft_putstr("N -> negatibrt\n");
	ft_putstr("T -> tricorne\n");
	ft_putstr("B -> burningship\n");
	ft_putstr("X -> xmonsieur\n");
	ft_putstr("Type many times the same letter -> similar fractals\n");
	ft_putstr("S -> stop julia movement\n");
	ft_putstr("R -> reset\n");
	ft_putstr("+ -> increase iteration\n");
	ft_putstr("- -> decrease iteration\n");
	ft_putstr("arrow UP/DOWN/LEFT/RIGHT -> to move the drawing\n");
	ft_putstr("\t\toouklich -- 1337\n");
}

void	disp_usage(void)
{
	ft_putstr("Usage: ./fractol fractale\n");
	ft_putstr("       ./fractol [ julia | mandelbrot | negatibrot | ");
	ft_putstr("tricorne | burningship | xmonsieur ]\n");
	exit(0);
}
