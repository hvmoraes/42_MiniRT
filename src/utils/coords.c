/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:54:39 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:37:41 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Check if coords are in format: [x,y,z]
 * 
 * @param coords 
 */
int	check_coords(char *coords, t_coor3 *coor_final)
{
	char	**coords_check;

	coords_check = ft_split(coords, ',');
	if (line_fields(coords_check) != 3)
		handle_error("Coordinates have to be in format [x,y,z]");
	coor_final->x = ft_atod(coords_check[0]);
	coor_final->y = ft_atod(coords_check[1]);
	coor_final->z = ft_atod(coords_check[2]);
	return (ft_atod(coords_check[0]) >= 0 && ft_atod(coords_check[1])  >= 0
		&& ft_atod(coords_check[2]) >= 0);	
}

int	check_normal(char *normal, t_coor3 *normal_final)
{
	char	**normal_check;

	normal_check = ft_split(normal, ',');
	if (line_fields(normal_check) != 3)
		handle_error("Coordinates have to be in format [x,y,z]");
	normal_final->x = ft_atod(normal_check[0]);
	normal_final->y = ft_atod(normal_check[1]);
	normal_final->z = ft_atod(normal_check[2]);
	return (ft_atod(normal_check[0]) >= -1 && ft_atod(normal_check[0])  <= 1
		&& ft_atod(normal_check[1]) >= -1 && ft_atod(normal_check[1]) <= 1
		&& ft_atod(normal_check[2]) >= -1 && ft_atod(normal_check[2]) <= 1);	
}
