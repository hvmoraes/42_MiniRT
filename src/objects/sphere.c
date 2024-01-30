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
	t_vec3	sphere_camera;
	float	a;
	float	b;
	float	c;
	float	descriminant;
	t_vec2	result;

	//printf("%f\n", sphere.radius);

	sphere_camera = vec3_sub(camera, sphere.center);
	a = dot(viewport, viewport);
	b = 2 * dot(sphere_camera, viewport);
	c = (dot(sphere_camera, sphere_camera)) - (sphere.radius * sphere.radius);
	descriminant = (b * b) - (4.0f * a * c);
	if (descriminant < 0)
	{
		result.x = INF;
		result.y = INF;
	}
	else
	{
		result.x = (-b + (sqrt(descriminant)) / (2 * a));
		result.y = (-b - (sqrt(descriminant)) / (2 * a));
	}
	return (result);
}
