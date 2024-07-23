/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:54:17 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:34:07 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

char	*strjoin_and_frees1(char *s1, char *s2)
{
	char	*str;
	size_t	str_len;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	if (s1 != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[++j])
		str[i++] = s2[j];
	return (str);
}

void	print_error(char *error_msg, char **map_arr)
{
	write(1, "Error\n", 6);
	write(1, error_msg, ft_strlen(error_msg));
	free_arr(map_arr);
	exit(EXIT_FAILURE);
}

int	ft_strncmp_last(char *s1, char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < n || len2 < n)
		return (1);
	while (n >= 0 && s1[len1 - n] && s2[len2 - n])
	{
		if (s1[len1 - n] == s2[len2 - n])
			n--;
		else
			break ;
	}
	if (!n)
		return (0);
	return (1);
}
