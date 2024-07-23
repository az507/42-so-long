/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:15:25 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:48:37 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**validate_map(int ac, char **av, t_map *map)
{
	if (ac < 2)
		print_error("Too few arguments\n", NULL);
	if (ft_strncmp_last(av[1], ".ber", 4))
		print_error("Invalid file extension\n", NULL);
	return (parse_map(av[1], map));
}

int	main(int ac, char **av)
{
	t_map	map;

	map.map_arr = validate_map(ac, av, &map);
	start_game(map);
	free_arr(map.map_arr);
	free(map.sp);
}
/*
//	i = -1;
//	while (map_arr[++i])
//		printf("map_arr[%d] = %s\n", i, map_arr[i]);
	printf("ok\n");
	printf("map.width = %d\n", map.width);
	printf("map.height = %d\n", map.height);
	printf("map.collectible = %d\n", map.collectible);
*/
