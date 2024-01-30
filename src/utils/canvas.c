/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:50:51 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 11:50:51 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec3	canvas_viewport(int x, int y)
{
	t_vec3	viewport_point;

	viewport_point.x = x * ((float)viewport()->width / (float)WIDTH);
	viewport_point.y = y * ((float)viewport()->height / (float)HEIGHT);
	viewport_point.z = viewport()->distance;
	return (viewport_point);
}
