/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:20:25 by achak             #+#    #+#             */
/*   Updated: 2024/07/23 18:59:49 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	check_if_wall_infront(t_data *data, int *sp, int flag)
{
	if (data->map_arr[data->map.sp[1]]
			[data->map.sp[0]] == '1' && flag == 1)
	{
		sp[1]--;
		return ;
	}
	else if (data->map_arr[data->map.sp[1]]
			[data->map.sp[0]] == '1' && flag == 2)
	{
		sp[0]++;
		return ;
	}
	else if (data->map_arr[data->map.sp[1]]
			[data->map.sp[0]] == '1' && flag == 3)
	
	{
		sp[1]++;
		return ;
	}
	else if (data->map_arr[data->map.sp[1]]
			[data->map.sp[0]] == '1' && flag == 4)
	{
		sp[0]--;
		return ;
	}
	check_if_collectible(data);
}

void	handle_movement(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		check_if_wall_infront(data, ++data->map.sp[1], 1);
	else if (keysym == XK_a || keysym == XK_A)
		check_if_wall_infront(data, --data->map.sp[0], 2);
	else if (keysym == XK_s || keysym == XK_S)
		check_if_wall_infront(data, --data->map.sp[1], 3);
	else if (keysym == XK_d || keysym == XK_D)
		check_if_wall_infront(data, ++data->map.sp[0], 4);
}
*/

/*
void	move_player_position(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img[2].img_ptr);
	data->img[2].img_ptr = mlx_new_image(data->mlx_ptr, data->window_width,
		data->window_height);
	data->img[2].addr = mlx_get_data_addr(data->img[2].img_ptr, 
		&data->img[2].bpp, &data->img[2].size_line,
		&data->img[2].endian);
	render_map_component(data, 'P', RED_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[2].img_ptr, 0, 0);
}

void	remove_collectible_from_map(t_data *data)
{
	render_block(data, data->map.sp[0], data->map.sp[1], WHITE_PIXEL);
}
*/

int	check_infront(t_data *data, char infront, int flag)
{
	if (infront == '1')
	{
		if (flag == 1)
			data->map.sp[0]++;
		else if (flag == 2)
			data->map.sp[1]++;
		else if (flag == 3)
			data->map.sp[0]--;
		else
			data->map.sp[1]--;
		return (0);
	}
	else if (infront == 'E')
	{
		if (data->map.collectible == 0)
			return (1);
		else
			return (2);
	}
	else if (infront == 'C')
		data->map.collectible--;
	return (1);
}
//	remove_collectible_from_map(data);

void	change_previous_map_component(int keysym, t_data *data, char change_to)
{
	if (keysym == XK_w || keysym == XK_W)
		data->map.map_arr[data->map.sp[0] + 1][data->map.sp[1]] = change_to;
	else if (keysym == XK_a || keysym == XK_A)
		data->map.map_arr[data->map.sp[0]][data->map.sp[1] + 1] = change_to;
	else if (keysym == XK_s || keysym == XK_S)
		data->map.map_arr[data->map.sp[0] - 1][data->map.sp[1]] = change_to;
	else
		data->map.map_arr[data->map.sp[0]][data->map.sp[1] - 1] = change_to;
}

void	change_map_arr_components(int keysym, t_data *data)
{
	int		flag;

	flag = 0;
	if (data->map.collectible >= 0 && !find_map_component(data, 'E'))
	{
		flag = 1;
		data->map.map_arr[data->map.exit_pos0][data->map.exit_pos1] = 'E';
	}
	if (data->map.collectible >= 0
		&& data->map.map_arr[data->map.sp[0]][data->map.sp[1]] == 'E')
	{
		data->map.exit_pos0 = data->map.sp[0];
		data->map.exit_pos1 = data->map.sp[1];
	}
	data->map.map_arr[data->map.sp[0]][data->map.sp[1]] = 'P';
	if (!flag)
		change_previous_map_component(keysym, data, '0');
}

int	move_player_on_map(int keysym, t_data *data)
{
	int	i;

	i = 0;
	if (keysym == XK_w || keysym == XK_W)
		i = check_infront(data,
				data->map.map_arr[--data->map.sp[0]][data->map.sp[1]], 1);
	else if (keysym == XK_a || keysym == XK_A)
		i = check_infront(data,
				data->map.map_arr[data->map.sp[0]][--data->map.sp[1]], 2);
	else if (keysym == XK_s || keysym == XK_S)
		i = check_infront(data,
				data->map.map_arr[++data->map.sp[0]][data->map.sp[1]], 3);
	else
		i = check_infront(data,
				data->map.map_arr[data->map.sp[0]][++data->map.sp[1]], 4);
	if (i)
		change_map_arr_components(keysym, data);
	return (i);
}

/*
//	if (flag == 1)
//		change_to = 'E';
//	else
//		change_to = '0';
//	if (keysym == XK_w || keysym == XK_W)
//		data->map.map_arr[data->map.sp[0] + 1][data->map.sp[1]] = '0';
//	else if (keysym == XK_a || keysym == XK_A)
//		data->map.map_arr[data->map.sp[0]][data->map.sp[1] + 1] = '0';
//	else if (keysym == XK_s || keysym == XK_S)
//		data->map.map_arr[data->map.sp[0] - 1][data->map.sp[1]] = '0';
//	else
//		data->map.map_arr[data->map.sp[0]][data->map.sp[1] - 1] = '0';
//	else if (i == 2)
//	{
//		data->map.map_arr[data->map.sp[0]][data->map.sp[1]] = 'P';
//		if (keysym == XK_w || keysym == XK_W)
//			data->map.map_arr[data->map.sp[0] + 1][data->map.sp[1]] = 'E';
//		else if (keysym == XK_a || keysym == XK_A)
//			data->map.map_arr[data->map.sp[0]][data->map.sp[1] + 1] = 'E';
//		else if (keysym == XK_s || keysym == XK_S)
//			data->map.map_arr[data->map.sp[0] - 1][data->map.sp[1]] = 'E';
//		else
//			data->map.map_arr[data->map.sp[0]][data->map.sp[1] - 1] = 'E';
//	}
//
*/

void	handle_movement(int keysym, t_data *data)
{
	static int	movements = INT_MAX;
	int			res;

	res = move_player_on_map(keysym, data);
	if (res)
	{
		if (movements >= INT_MAX || movements < 0)
			movements = 0;
		ft_dprintf(1, "Number of movements: %d\n", ++movements);
		int	i;

		i = -1;
		while (++i < data->map.height)
		{
			printf("%s\n", data->map.map_arr[i]);
		}
	}
}

/*
//	if (keysym == XK_w || keysym == XK_W)
//		data->sp[1]++;
//	else if (keysym == XK_a || keysym == XK_A)
//		data->sp[0]--;
//	else if (keysym == XK_s || keysym == XK_S)
//		data->sp[1]--;
//	else if (keysym == XK_d || keysym == XK_D)
//		data->sp[0]++;
//		move_player_position(data);
//	else if (res == 2)
//		exit_success(data);
*/
