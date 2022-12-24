/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmapp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:16 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/23 17:51:03 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

char	**reading(char **av)
{
	int		fd;
	char	**ptr;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(2);
	ptr = (char **)malloc(33 * sizeof(char *));
	if (!ptr)
		ft_error(1);
	ptr[0] = get_next_line(fd);
	while (ptr[i++])
	{
		if (i > 33)
			ft_error(2);
		ptr[i] = get_next_line(fd);
	}
	ptr[i] = NULL;
	return (ptr);
}

void	copy(char **av, t_var *read, t_text *big)
{
	int		i;
	int		j;
	int		x;
	int		y;

	read->map = reading(av);
	i = -1;
	y = 0;
	while (read->map[++i])
	{
		j = 0;
		x = 0;
		while(read->map[i][j] && read->map[i][j] != '\n')
		{
			if (read->map[i][j] == '1')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->ptr, x, y);
			else if (read->map[i][j] == '0')
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
			else if (read->map[i][j] == 'E')
			{
				read->doorp1 = y;
				read->doorp2 = x;
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->door, x, y);
			}
			else if (read->map[i][j] == 'P')
			{
				read->p1 = x;
				read->p2 = y;
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->player, x, y);
			}
			else if (read->map[i][j] == 'C')
			{
				read->count++;
				mlx_put_image_to_window(read->mlx, read->mlx_win, read->p, x, y);
				mlx_put_image_to_window(read->mlx, read->mlx_win, big->res, x, y);
			}
			enemy(read, x, y, i, j);
			x += 32;
			j++;
		}
		y += 32;
	}
}
