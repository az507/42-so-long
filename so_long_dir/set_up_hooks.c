/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:17:26 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:33:40 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	handle_no_input(void *data)
{
	if (!data)
		return (1);
	return (0);
}
//	mlx_destroy_image(data->mlx_ptr, data->img[1].img_ptr);
//	mlx_destroy_image(data->mlx_ptr, data->img[2].img_ptr);
*/
void	exit_success(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img[0].img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->map.sp);
	free_arr(data->map.map_arr);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_success(data);
	else if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym
		== XK_d || keysym == XK_W || keysym == XK_A || keysym == XK_S
		|| keysym == XK_D)
		handle_movement(keysym, data);
	return (0);
}

int	handle_cross(t_data *data)
{
	exit_success(data);
	return (0);
}

void	set_up_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&handle_cross, data);
	mlx_loop(data->mlx_ptr);
}
//	mlx_destroy_image(data->mlx_ptr, data->img[1].img_ptr);
//	mlx_destroy_image(data->mlx_ptr, data->img[2].img_ptr);
