/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:41:46 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 19:51:20 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_true_map2(t_list *data, int i, int j)
{
	data->maptmp[i][j] = '.';
	if (data->maptmp[i - 1][j] != '1' && data->maptmp[i - 1][j] != '.')
		is_true_map2(data, i - 1, j);
	if (data->maptmp[i][j + 1] != '1' && data->maptmp[i][j + 1] != '.')
		is_true_map2(data, i, j + 1);
	if (data->maptmp[i + 1][j] != '1' && data->maptmp[i + 1][j] != '.')
		is_true_map2(data, i + 1, j);
	if (data->maptmp[i][j - 1] != '1' && data->maptmp[i][j - 1] != '.')
		is_true_map2(data, i, j - 1);
}

int	collectable_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->colon)
		{
			if (data->maptmp[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_control2(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	is_true_map(data, data->p_row, data->p_colon);
	if (collectable_control(data))
		return (0);
	is_true_map2(data, data->p_row, data->p_colon);
	while (i < data->row)
	{
		while (j < data->colon)
		{
			if (data->maptmp[i][j] == 'C' || data->maptmp[i][j] == 'P'
				|| data->maptmp[i][j] == 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	map_word_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row - 1)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P'
			&& data->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	finished_game(t_list *data)
{
	(void)data;
	write(1, "You have entered the portal\n", 29);
	exit(0);
}
