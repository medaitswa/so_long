/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassi <mnassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:46:41 by mnassi            #+#    #+#             */
/*   Updated: 2022/12/20 11:50:21 by mnassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	mapchecker(t_var *check)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check->map[i][j])
	{
		if (check->map[i][j] == '0')
			ft_error(4);
		j++;
	}
}
