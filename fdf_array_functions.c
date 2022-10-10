/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_array_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:52:14 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/07 21:51:08 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_counter(char *file)
{
	int		fd;
	int		ret;
	char	buf[2];
	int		lines;

	ret = 1;
	lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (ret)
	{
		ret = read(fd, buf, 1);
		if (ret <= 0)
			break ;
		buf[1] = 0;
		if (buf[0] == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

int	width_counter(char *file)
{
	char	*str;
	int		fd;
	char	**split_array;
	int		i;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	str = get_next_line(fd);
	split_array = ft_freed_split(str, ' ');
	i = 0;
	count = 0;
	while (split_array[i])
	{
		if (split_array[i][0] != '\n')
			count++;
		free(split_array[i]);
		i++;
	}
	free(split_array);
	close(fd);
	return (count);
}

char	**file_to_array(char *file, int line_count)
{
	int		i;
	char	*str;
	int		fd;
	char	**array;
	char	*gnl;

	i = 0;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (i < line_count)
	{
		gnl = get_next_line(fd);
		str = ft_strjoin(str, gnl);
		free(gnl);
		i++;
	}
	close(fd);
	array = ft_freed_split(str, '\n');
	return (array);
}

int	**new_array(char *file, t_map size)
{
	char	**transition_array;
	int		**new_array;
	char	**old_array;
	int		i;
	int		j;

	old_array = file_to_array(file, size.line);
	new_array = malloc(size.line * sizeof(int *));
	if (!new_array)
		exit(1);
	i = -1;
	while (old_array[++i])
	{
		transition_array = ft_freed_split(old_array[i], ' ');
		new_array[i] = malloc(size.width * sizeof(int));
		j = -1;
		while (transition_array[++j])
		{
			new_array[i][j] = (int)ft_atoi((char *)transition_array[j]);
			free(transition_array[j]);
		}
		free(transition_array);
	}
	free(old_array);
	return (new_array);
}
