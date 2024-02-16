/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:58:41 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/16 12:58:41 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	compute_lights(t_vec3 P, t_vec3 N)
{
	float	i;
	t_vec3	L;
	t_vec3	point_pos;
	float	n_dot_l;
	//t_vec3	direction;

	i = 0.0;
	point_pos.x = 2;
	point_pos.y = 1;
	point_pos.z = 0;

	/*direction.x = 1;
	direction.y = 4;
	direction.z = 4;*/

	i += 0.2;
	L = vec3_sub(P, point_pos);
	n_dot_l = dot(N, L);
	if (n_dot_l > 0)
		i += 0.6 * n_dot_l / (length(N) * length(L));
	/*L = direction;
	n_dot_l = dot(N, L);
	if (n_dot_l > 0)
		i += 0.2 * n_dot_l / (length(N) * length(L));*/
	return (i);
}
