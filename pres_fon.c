/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pres_fon.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:23:42 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 20:07:40 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ifpressd(t_list *data)
{
	if (data->map[data->p_row][data->p_colon + 1] != '1')
	{
		if (data->map[data->p_row][data->p_colon + 1] != 'E')
		{
			step_counter();
			if (data->map[data->p_row][data->p_colon + 1] == 'C')
				data->coin_count -= 1;
			data->map[data->p_row][data->p_colon + 1] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			wall_backg_init(data);
			player_coin_exit_init(data);
			player_coordinate(data);
		}
		else
		{
			if (data->coin_count == 0)
			{
				step_counter();
				finished_game(data);
			}
		}
	}
}

void	ifpressw(t_list *data)
{
	if (data->map[data->p_row - 1][data->p_colon] != '1')
	{
		if (data->map[data->p_row - 1][data->p_colon] != 'E')
		{
			step_counter();
			if (data->map[data->p_row - 1][data->p_colon] == 'C')
				data->coin_count -= 1;
			data->map[data->p_row - 1][data->p_colon] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			wall_backg_init(data);
			player_coin_exit_init(data);
			player_coordinate(data);
		}
		else
		{
			if (data->coin_count == 0)
			{
				step_counter();
				finished_game(data);
			}
		}
	}
}

void	ifpressa(t_list *data)
{
	if (data->map[data->p_row][data->p_colon - 1] != '1')
	{
		if (data->map[data->p_row][data->p_colon - 1] != 'E')
		{
			step_counter();
			if (data->map[data->p_row][data->p_colon - 1] == 'C')
				data->coin_count -= 1;
			data->map[data->p_row][data->p_colon - 1] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			wall_backg_init(data);
			player_coin_exit_init(data);
			player_coordinate(data);
		}
		else
		{
			if (data->coin_count == 0)
			{
				step_counter();
				finished_game(data);
			}
		}
	}
}

void	ifpresss(t_list *data)
{
	if (data->map[data->p_row + 1][data->p_colon] != '1')
	{
		if (data->map[data->p_row + 1][data->p_colon] != 'E')
		{
			step_counter();
			if (data->map[data->p_row + 1][data->p_colon] == 'C')
				data->coin_count -= 1;
			data->map[data->p_row + 1][data->p_colon] = 'P';
			data->map[data->p_row][data->p_colon] = '0';
			wall_backg_init(data);
			player_coin_exit_init(data);
			player_coordinate(data);
		}
		else
		{
			if (data->coin_count == 0)
			{
				step_counter();
				finished_game(data);
			}
		}
	}
}

void	ifpressesc(t_list *data)
{
	mlx_destroy_window(data->mlx, data->mlxwin);
	exit(0);
}
