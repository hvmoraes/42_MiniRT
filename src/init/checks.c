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

	i = 0;
	while (coords[i])
	{
		while (coords[i] && coords[i] != '.' && coords[i] != ',')
		{
			if (!ft_isdigit(coords[i]) && coords[i] != '-')
				*error += 1;
			i++;
		}
		if (coords[i] == '.')
		{
			i++;
			while (coords[i] && coords[i] != ',')
			{
				if (!ft_isdigit(coords[i]))
					*error += 1;
				i++;
			}
		}
		if (coords[i])
			i++;
	}
	final_coords = ft_split(coords, ',');
	return(final_coords);
}

int	check_normal(char *normal, int *error)
{
	char	**final_normal;

	final_normal = check_coords(normal, error);
	camera()->normal.x = ft_atod(final_normal[0]);
	camera()->normal.y = ft_atod(final_normal[1]);
	camera()->normal.z = ft_atod(final_normal[2]);
	free_array(final_normal);
	if (camera()->normal.x < -1 || camera()->normal.x > 1)
		return (1);
	if (camera()->normal.y < -1 || camera()->normal.y > 1)
		return (1);
	if (camera()->normal.z < -1 || camera()->normal.z > 1)
		return (1);
	return (0);
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
		//free_all();
		exit(EXIT_FAILURE);
	}
}
