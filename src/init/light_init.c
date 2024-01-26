/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:38:12 by jaeshin           #+#    #+#             */
/*   Updated: 2024/01/26 16:15:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_a_light	*a_light(void)
{
	static t_a_light	a_light;

	return (&a_light);
}

void	init_a_light(t_nothitable map)
{
	a_light()->intensity = map.light;
	a_light()->color.x = map.rgb.x;
	a_light()->color.y = map.rgb.y;
	a_light()->color.z = map.rgb.z;
}

t_light	*light(void)
{
	static t_light	light;

	return (&light);
}

void	init_light(t_nothitable map)
{
	light()->pos.x = map.point.x;
	light()->pos.y = map.point.y;
	light()->pos.z = map.point.z;
	light()->intensity = map.brightness;
	light()->color.x = map.rgb.x;
	light()->color.y = map.rgb.y;
	light()->color.z = map.rgb.z;
}
