/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:50:23 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 16:21:07 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d	clamp(t_vec3d value, t_vec3d min, t_vec3d max)
{
	t_vec3d	result;

	result = value;
	if (value.x < min.x)
		result.x = min.x;
	else if (value.x > max.x)
		result.x = max.x;
	if (value.y < min.y)
		result.y = min.y;
	else if (value.y > max.y)
		result.y = max.y;
	if (value.z < min.z)
		result.z = min.z;
	else if (value.z > max.z)
		result.z = max.z;
	return (result);
}

void	normalize(t_vec3d *vec)
{
	float	length;

	length = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	if (length != 0.0f)
	{
		vec->x /= length;
		vec->y /= length;
		vec->z /= length;
	}
}

float	length(t_vec3d vec)
{
	float	length;

	length = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (length);
}

float	dot(t_vec3d v1, t_vec3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

uint32_t	convert_to_rgba(const t_vec3d color)
{
	uint32_t	result;

	result = ((int)color.x << 16) | ((int)color.y << 8) | (int)color.z;
	return (result);
}
