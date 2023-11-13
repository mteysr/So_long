/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:24:11 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 19:44:29 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_control2(t_list *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[data->row - 1][j])
	{
		if (data->map[data->row - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < data->row)
	{
		if (data->map[i][data->colon - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_control(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][j])
	{
		if (data->map[0][j] != '1')
			return (0);
		j++;
	}
	while (i < data->row -1)
	{
		if (data->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	exit_control(t_list *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < data->row - 1)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				flag++;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag >= 2 || flag <= 0)
		return (0);
	else
		return (1);
}

int	coin_control(t_list *data)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < data->row - 1)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	coin_count(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	data->coin_count = 0;
	while (i < data->row - 1)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->coin_count++;
			j++;
		}
		i++;
	}
}
