/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:36:29 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/07 14:44:07 by hcorrea-         ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	t_coor3	vector;

	printf("Camera = %f\n%f\n%f\n Viewport = %f\n%f\n%f\n Sphere = %f\n%f\n%f\n",
		camera_origin.x, camera_origin.y, camera_origin.z, viewport_point.x,
		viewport_point.y, viewport_point.z, sphere.coor.x, sphere.coor.y,
		sphere.coor.y);
	vector = subtract(camera_origin, sphere.coor);
	a = dot(&viewport_point, &viewport_point);
	b = 2 * dot(&vector, &viewport_point);
	c = dot(&vector, &vector);
	printf("a = %f, b = %f, c = %f\n", a, b, c);
	t = quadratic(a, b, c);
	printf("t = %f\n", t);
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
		handle_error("Dynamic allocation failed");
	}
	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		free_matrix(line);
		handle_error("Dynamic allocation failed");
	}
	object->object = sphere;
	add_object(object);
	if (line_fields(line) != 4)
		return (parse_error("Sphere's usage: sp "
				"[coord: x,y,z] [diameter] [color: R,G,B]"));
	return (init_sphere(line, object, sphere));
}
