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

//printf("%f\n", sphere.radius);

t_vec2	intersect_sphere(t_vec3 camera, t_vec3 viewport, t_sphere sphere)
{
	t_vec3	sphere_camera;
	float	a;
	float	b;
	float	c;
	float	descriminant;
	t_vec2	result;

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

// typedef struct {
//     float a;
//     float b;
//     float c;
// } QuadraticCoefficients;

// QuadraticCoefficients calculate_quadratic_coefficients(t_vec3 viewport, t_vec3 sphere_camera, float sphere_radius) {
//     QuadraticCoefficients coeffs;

//     coeffs.a = dot(viewport, viewport);
//     coeffs.b = 2 * dot(sphere_camera, viewport);
//     coeffs.c = dot(sphere_camera, sphere_camera) - (sphere_radius * sphere_radius);

//     return coeffs;
// }

// t_vec2 intersect_sphere_ray(t_vec3 sphere_camera, QuadraticCoefficients coeffs) {
    
// 	(void) sphere_camera;
// 	t_vec2 result;
//     float discriminant = (coeffs.b * coeffs.b) - (4.0f * coeffs.a * coeffs.c);

//     if (discriminant < 0) {
//         result.x = INF;
//         result.y = INF;
//     } else {
//         result.x = (-coeffs.b + sqrt(discriminant)) / (2 * coeffs.a);
//         result.y = (-coeffs.b - sqrt(discriminant)) / (2 * coeffs.a);
//     }

//     return result;
// }

// t_vec2 intersect_sphere(t_vec3 camera, t_vec3 viewport, t_sphere sphere) {
//     t_vec3 sphere_camera = vec3_sub(camera, sphere.center);
//     QuadraticCoefficients coeffs = calculate_quadratic_coefficients(viewport, sphere_camera, sphere.radius);

//     return intersect_sphere_ray(sphere_camera, coeffs);
// }
