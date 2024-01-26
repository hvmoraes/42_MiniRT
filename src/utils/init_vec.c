/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:48:31 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/01/26 15:18:17 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_vec3d	init_vec3d(float x, float y, float z)
{
	t_vec3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}