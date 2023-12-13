/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:36:29 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/12/13 11:08:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Intersect ray starting in camera_origin and passing through
 * viewport_point with sphere
 * 
 * @param camera_origin 
 * @param viewport_point 
 * @param sphere 
 * @return double 
 */
double	intersect_sphere(t_coor3 camera_origin, t_coor3 viewport_point,
	t_sphere sphere)
{
	double	t;
	double	quad[3];
	t_coor3	vector;
	t_coor3	vector2;

	vector = subtract(viewport_point, camera_origin);
	vector = normalize(vector);
	vector2 = subtract(camera_origin, sphere.coor);
	vector2 = normalize(vector2);
	quad[0] = dot(&vector, &vector);
	quad[1] = 2 * dot(&vector2, &vector);
	quad[2] = dot(&vector2, &vector2) - pow(sphere.radius, 2);
	t = quadratic(quad[0], quad[1], quad[2]);
	return (t);
}

/**
 * @brief Initialize sphere's info: coordinates, radius and color
 * 
 * @param line 
 * @param object 
 * @param sphere 
 * @return int 
 */
int	init_sphere(char **line, t_object *object, t_sphere *sphere)
{
	object->type = SPHERE;
	if (!check_coords(line[1], &sphere->coor))
		return (parse_error("Sphere's coordinates "
				"have to be in format [x,y,z]"));
	sphere->radius = ft_atod(line[2]) / 2;
	if (sphere->radius <= 0)
		return (parse_error("Sphere's diameter can't be negative"));
	if (!check_color(line[3], &object->color))
		return (parse_error("Invalid Sphere colors"));
	return (1);
}

/**
 * @brief Adds a new sphere to the list of objects
 * 
 * @param line 
 * @return int 
 */
int	add_sphere(char **line)
{
	t_object	*object;
	t_sphere	*sphere;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
	{
		free_matrix(line);
		//handle_error("Dynamic allocation failed");
	}
	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		free_matrix(line);
		//handle_error("Dynamic allocation failed");
	}
	object->object = sphere;
	add_object(object);
	if (line_fields(line) != 4)
		return (parse_error("Sphere's usage: sp "
				"[coord: x,y,z] [diameter] [color: R,G,B]"));
	return (init_sphere(line, object, sphere));
}
