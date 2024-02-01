/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:23:14 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 12:23:14 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec2	intersect_sphere(t_vec3 camera, t_vec3 viewport, t_sphere sphere)
{
	float	b;
	float	c;
	float	descriminant;
	t_vec2	result;

	b = 2 * dot(vec3_sub(camera, sphere.center), viewport);
	c = (dot(vec3_sub(camera, sphere.center), vec3_sub(camera, sphere.center)))
		- (sphere.radius * sphere.radius);
	descriminant = (b * b) - (4.0f * dot(viewport, viewport) * c);
	if (descriminant < 0)
	{
		result.x = INF;
		result.y = INF;
	}
	else
	{
		result.x = (-b + (sqrt(descriminant)) / (2 * dot(viewport, viewport)));
		result.y = (-b - (sqrt(descriminant)) / (2 * dot(viewport, viewport)));
	}
	return (result);
}
