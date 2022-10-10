/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:38:35 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/01 23:54:28 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_simple_line_x(t_win img, int a, int b, int c)
{
	int	tmp;

	if (a > b)
		ft_swap(&a, &b, 0, 0);
	tmp = c;
	while (tmp < b + 1)
		ft_pixel_put(&img, a, tmp++, 0x0055FFFF);
}

void	print_simple_line_y(t_win img, int a, int b, int c)
{
	int	tmp;

	if (a > b)
		ft_swap(&a, &b, 0, 0);
	tmp = c;
	while (tmp < b + 1)
		ft_pixel_put(&img, tmp++, a, 0x0055FFFF);
}

void	print_line(t_point n1, int x2, int y2, t_win img)
{
	float	a;
	int		tmp;

	if (abs(x2 - n1.x) >= abs(y2 - n1.y) && abs(x2 - n1.x) && abs(y2 - n1.y))
	{
		if (n1.x > x2)
			ft_swap(&n1.x, &x2, &n1.y, &y2);
		a = (float)(y2 - n1.y) / (float)(x2 - n1.x);
		tmp = -1;
		while (++tmp < abs(x2 - n1.x) + 1)
			ft_pixel_put(&img, (tmp) + n1.x, n1.y + (tmp * a), 0x0055FFFF);
	}
	if (abs(x2 - n1.x) < abs(y2 - n1.y) && abs(x2 - n1.x) && abs(y2 - n1.y))
	{
		if (n1.y > y2)
			ft_swap(&n1.y, &y2, &n1.x, &x2);
		a = (float)(x2 - n1.x) / (float)(y2 - n1.y);
		tmp = -1;
		while (++tmp < abs(y2 - n1.y) + 1)
			ft_pixel_put(&img, n1.x + (tmp * a), tmp + n1.y, 0x0055FFFF);
	}
	if (abs(x2 - n1.x) == 0)
		print_simple_line_x(img, n1.x, x2, n1.y);
	if (abs(y2 - n1.y) == 0)
		print_simple_line_y(img, n1.y, y2, n1.x);
}

void	linker(t_win img, t_map size, int **array)
{
	int			i;
	int			j;
	t_display	display;

	display = perc_calculator(size.line, size.width);
	i = -1;
	while (++i < size.line)
	{
		j = -1;
		while (++j < size.width - 1)
			print_line((t_point){((j - i) * 2 * display.space + display.origin),
				((j + i) * display.space) + array[i][j] * (TYPO_SIZE)},
				((j + 1 - i) * 2 * display.space + display.origin), ((j + 1 + i)
					* display.space) + array[i][j + 1] * (TYPO_SIZE), img);
	}
	i = -1;
	while (++i < size.line - 1)
	{
		j = -1;
		while (++j < size.width)
			print_line((t_point){(j - i) * 2 * display.space + display.origin,
				(i + j) * display.space + array[i][j] * (TYPO_SIZE)},
				(j - (i + 1)) * 2 * display.space + display.origin,
				(i + j + 1) * display.space + array[i + 1][j] * TYPO_SIZE, img);
	}
}

int	main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	int			**array;
	t_win		img;
	t_map		size;

	if (ac != 2)
		exit(1);
	size.line = line_counter(av[1]);
	size.width = width_counter(av[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, av[1]);
	img.img_data = mlx_new_image(mlx, 1920, 1030);
	img.addr = mlx_get_data_addr(img.img_data,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	array = new_array(av[1], size);
	linker(img, size, array);
	size.line--;
	while (size.line)
		free(array[size.line--]);
	mlx_put_image_to_window(mlx, mlx_win, img.img_data, 0, 50);
	mlx_key_hook(mlx_win, key, (void *)0);
	mlx_loop(mlx);
}
