/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:35:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/01 11:35:06 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	init_light(char **line)
{
	int		error;
	char	**coords;

	error = 0;
	if (data()->total_lights)
		return (parse_error("More than one light in scene\n"));
	if (array_size(line) != 3)
		return (parse_error("Invalid number of arguments for light\n"));
	coords = check_coords(line[1], &error);
	light()->coords.x = ft_atod(coords[0]);
	light()->coords.y = ft_atod(coords[1]);
	light()->coords.z = ft_atod(coords[2]);
	free_array(coords);
	if (ft_atod(line[2]) < 0.0 || ft_atod(line[2]) > 1.0 || !is_digit(line[2]))
		return (parse_error("Invalid intensity for light\n"));
	light()->intensity = ft_atod(line[2]);
	data()->total_lights++;
	return (error);
}

int	init_ambient(char **line)
{
	int		error;
	t_vec3	color;

	error = 0;
	if (data()->total_ambients)
		return (parse_error("More than one ambient light in scene\n"));
	if (array_size(line) != 3)
		return (parse_error("Invalid number of arguments for ambient light\n"));
	color = check_color(line[2], &error);
	ambient()->color.x = color.x;
	ambient()->color.y = color.y;
	ambient()->color.z = color.z;
	if (ft_atod(line[1]) < 0.0 || ft_atod(line[1]) > 1.0 || !is_digit(line[1]))
		return (parse_error("Invalid intensity for ambient light\n"));
	ambient()->intensity = ft_atod(line[1]);
	data()->total_ambients++;
	return (error);
}