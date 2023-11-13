/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:23:07 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 21:04:35 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

typedef struct s_list
{
	int		row;
	int		colon;
	char	**map;
	char	**maptmp;
	char	*str;
	int		p_colon;
	int		p_row;
	void	*mlx;
	void	*mlxwin;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
	void	*backg;
	int		coin_count;
}	t_list;

void	map_reading(t_list *data, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2);
char	*find_line(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
void	ft_error(t_list *data);
char	**ft_split(char *s, char c);
void	find_colon(t_list *data);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*new_str(char *str);
void	mlxinitialize(t_list *data);
void	wall_backg_init(t_list *data);
void	player_coin_exit_init(t_list *data);
void	player_coordinate(t_list *data);
void	map_reading(t_list *data, char *str);
void	coin_count(t_list *data);
void	step_counter(void);
int		press_key(int key, t_list *data);
void	ifpressd(t_list *data);
void	ifpressw(t_list *data);
void	ifpressa(t_list *data);
void	ifpresss(t_list *data);
void	ifpressesc(t_list *data);
void	is_true_map(t_list *data, int i, int j);
void	is_true_map2(t_list *data, int i, int j);
int		start_control(t_list *data);
int		wall_control(t_list *data);
int		wall_control2(t_list *data);
int		exit_control(t_list *data);
int		coin_control(t_list *data);
int		map_is_square(t_list *data);
int		map_name_control(t_list *data, char *av);
int		start_control(t_list *data);
void	finished_game(t_list *data);
int		map_control2(t_list *data);
int		map_word_control(t_list *data);
int		collectable_control(t_list *data);

#endif
