/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:23:31 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 19:33:53 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ifpressx(t_list *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	othercase(t_list *data)
{
	if (exit_control(data) && coin_control(data)
		&& start_control(data) && map_is_square(data))
	{
		player_coordinate(data);
		if (map_control2(data))
		{
			mlxinitialize(data);
			wall_backg_init(data);
			player_coin_exit_init(data);
		}
		else
			ft_error(data);
	}
	else
		ft_error(data);
}

int	main(int ac, char **av)
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	map_reading(data, av[1]);
	find_colon(data);
	if (ac == 2 && map_name_control(data, av[1]))
	{
		if (wall_control2(data) && wall_control(data) && map_word_control(data))
		{
			coin_count(data);
			othercase(data);
		}
		else
			ft_error(data);
	}
	else
		ft_error(data);
	mlx_hook(data->mlxwin, 2, 0, press_key, data);
	mlx_hook(data->mlxwin, 17, 0, ifpressx, data);
	mlx_loop(data->mlx);
	return (0);
}
