/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:36 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 15:14:36 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// viewport()->width = (float)(2 * viewport()->distance) 
// *tan(to_rad(camera()->fov / 2));
// viewport()->width = (float)(2 * viewport()->distance)
//  * tan(to_rad(camera()->fov / 2));

void	set_viewport(void)
{
	viewport()->distance = 1;
	viewport()->width = (float)(2 * viewport()->distance)
	*tan(to_rad(camera()->fov / 2));
	viewport()->height = viewport()->width * HEIGHT / WIDTH;
}

void	parser2(int *error)
{
	if (!data()->total_cameras)
		*error += parse_error("No camera found in scene\n");
}
