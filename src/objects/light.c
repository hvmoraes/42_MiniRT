/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/01 13:41:07 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	calculate_light(t_vec3 point, t_vec3 normal)
{
	float		i;
	t_vec3	l;
	float		n_dot_l;

	i = 0;
	i += ambient()->intensity;
	//printf("point x = %f y = %f z = %f\n", point.x, point.y, point.z);
	l = vec3_sub(point, light()->coords);
	l = normalize(l);
	//printf("l x = %f y = %f z = %f\n", l.x, l.y, l.z);
	//printf("normal x = %f y = %f z = %f\n", normal.x, normal.y, normal.z);
	n_dot_l = dot(normal, l);
	//printf("%f\n", n_dot_l);
	if (n_dot_l > 0)
		i += light()->intensity * n_dot_l / (length(normal) * length(l));
	return (i);
}
