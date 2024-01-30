/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:35:25 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 15:35:25 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	**check_coords(char *coords, int *error)
{
	int	i;
	char	**final_coords;

	while (coords[i])
	{
		while (coords[i] && coords[i] != '.' && coords[i] != ',')
		{
			if (!ft_isdigit(coords[i]) && coords[i] != '-')
				*error += 1;
			i++;
		}
		if (coords[i++] == '.')
		{
			while (coords[i] && coords[i] != ',')
			{
				if (!ft_isdigit(coords[i]))
					*error += 1;
				i++;
			}
		}
		i++;
	}
	final_coords = ft_split(coords, ',');
	return(final_coords);
}

int	check_fov(char *fov)
{
	if (atoi(fov) > 0 && atoi(fov) < 181)
	{
		camera()->fov = atoi(fov);
		return (0);
	}
	else
		return (1);
}

void	check_error(int error)
{
	if (error)
	{
		close_window();
		exit(EXIT_FAILURE);
	}
}
