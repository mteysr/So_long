/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:23:18 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 20:21:55 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_coordinate(t_list *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->row)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_colon = j;
				data->p_row = i;
			}
			j++;
		}
		i++;
	}
}

void	find_colon(t_list *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		i++;
	data->colon = i;
}

void	map_reading(t_list *data, char *str)
{
	int		i;
	int		fd;
	char	*gnlstr;

	i = 1;
	fd = open (str, O_RDWR);
	if (fd == -1)
		ft_error(data);
	gnlstr = get_next_line(fd);
	data->str = ft_strdup(gnlstr);
	gnlstr = get_next_line(fd);
	while (gnlstr != NULL)
	{
		data->str = ft_strjoin(data->str, gnlstr);
		gnlstr = get_next_line(fd);
		i++;
	}
	data->row = 0;
	data->map = ft_split(data->str, '\n');
	data->maptmp = ft_split(data->str, '\n');
	while (data->map[data->row])
		data->row++;
	if (data->row != i)
		ft_error(data);
}

void	step_counter(void)
{
	static int	i;
	char		*a;

	i++;
	a = ft_itoa(i);
	write(1, a, ft_strlen(a));
	write(1, "\n", 1);
	free(a);
}

int	press_key(int key, t_list *data)
{
	if (key == 13)
		ifpressw(data);
	else if (key == 1)
		ifpresss(data);
	else if (key == 2)
		ifpressd(data);
	else if (key == 0)
		ifpressa(data);
	else if (key == 53)
		ifpressesc(data);
	return (0);
}
