/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:19 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/01 11:12:19 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec3	color_overflow(t_vec3 final_color)
{
	if (final_color.x > 255)
		final_color.x = 255;
	if (final_color.x < 0)
		final_color.x = 0;
	if (final_color.y > 255)
		final_color.y = 255;
	if (final_color.y < 0)
		final_color.y = 0;
	if (final_color.z > 255)
		final_color.z = 255;
	if (final_color.z < 0)
		final_color.z = 0;
	return (final_color);
}

void	check_coords_utils(char *coords, int *error, int *i)
{
	while (coords[*i] && coords[*i] != '.' && coords[*i] != ',')
	{
		if (!ft_isdigit(coords[*i]) && coords[*i] != '-')
			*error += 1;
		(*i)++;
	}
	if (coords[*i] == '.')
	{
		(*i)++;
		while (coords[*i] && coords[*i] != ',')
		{
			if (!ft_isdigit(coords[*i]))
				*error += 1;
			(*i)++;
		}
	}
	if (coords[*i])
		(*i)++;
}
