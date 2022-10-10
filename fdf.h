/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:33:57 by jcauchet          #+#    #+#             */
/*   Updated: 2022/02/02 10:20:21 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <math.h>
# include "get_next_line/get_next_line.h"

# define TYPO_SIZE -8

typedef struct t_display
{
	int	space;
	int	origin;
}	t_display;

typedef struct t_win
{
	void	*img_data;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_win;

typedef struct t_map
{
	int		width;
	int		line;
}	t_map;

typedef struct t_point
{
	int	x;
	int	y;
}	t_point;

int			key(int key, void *param);
void		ft_pixel_put(t_win *img, int x, int y, int color);
void		ft_swap(int *a, int *b, int *c, int *d);
t_display	perc_calculator(int lines, int width);
int			line_counter(char *file);
int			width_counter(char *file);
char		**file_to_array(char *file, int line_count);
int			**new_array(char *file, t_map size);
void		print_simple_line_y(t_win img, int a, int b, int c);
void		print_simple_line_x(t_win img, int a, int b, int c);
void		print_line(t_point n, int x2, int y2, t_win img);
void		linker(t_win img, t_map size, int **array);

#endif
