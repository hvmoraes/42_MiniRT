/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:00:36 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 16:19:55 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_sphere(t_hitable *map, t_ray ray)
{
	t_vec3d	rayorigin;
	float	close_t;
	t_vec3d	quad;
	float	discriminant;

	rayorigin = t_vec3d_sub(ray.orig, map->point);
	quad.x = dot(ray.dir, ray.dir);
	quad.y = 2.0f * dot(rayorigin, ray.dir);
	quad.z = dot(rayorigin, rayorigin) - (map->radius2);
	discriminant = quad.y * quad.y - 4.0f * quad.x * quad.z;
	if (discriminant >= 0.0f)
	{
		close_t = (-quad.y - sqrt(discriminant)) / (2.0f * quad.x);
		if (close_t > 0.001)
			return (close_t);
	}
	return (__FLT_MAX__);
}
