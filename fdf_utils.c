/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:50:19 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/01 14:55:59 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_pixel_put(t_win *img, int x, int y, int color)
{
	char	*pxl;

	if (((x < 1920) && (x >= 0) && (y < 1030) && (y >= 0)))
	{
		pxl = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	ft_swap(int *a, int *b, int *c, int *d)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	if (c != d)
	{
		tmp = *c;
		*c = *d;
		*d = tmp;
	}
}

t_display	perc_calculator(int lines, int width)
{
	t_display	display;

	display.space = (490 * 2) / (width + lines);
	display.origin = 960 - ((744 * (width - lines)) / (width + lines));
	if (display.space == 0)
		display.space = 1;
	return (display);
}
