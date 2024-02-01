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
	int		i;
	char	**final_coords;

	i = 0;
	while (coords[i])
		check_coords_utils(coords, error, &i);
	final_coords = ft_split(coords, ',');
	if (array_size(final_coords) != 3)
		*error += 1;
	return (final_coords);
}

int	check_normal(char *normal, int *error)
{
	char	**final_normal;

	final_normal = check_coords(normal, error);
	if (array_size(final_normal) != 3)
		*error += 1;
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

t_vec3	check_color(char *color, int *error)
{
	int		i;
	t_vec3	final_color;
	char	**color_vec;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ','
			&& color[i] != '\n' && !color[i])
			*error += 1;
		i++;
	}
	color_vec = ft_split(color, ',');
	if (array_size(color_vec) != 3)
		*error += 1;
	final_color.x = ft_atoi(color_vec[0]);
	final_color.y = ft_atoi(color_vec[1]);
	final_color.z = ft_atoi(color_vec[2]);
	free_array(color_vec);
	final_color = color_overflow(final_color);
	return (final_color);
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
