/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:00:28 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/04 14:49:11 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	vec_size(t_coor3 vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

/**
 * @brief Calculates cross product between u and v and stores it in w
 * 
 * @param u 
 * @param v 
 * @param w 
 */
void	cross_prod(t_coor3 *u, t_coor3 *v, t_coor3 *w)
{
	w->x = u->y * v->z - u->z * v->y;
	w->y = u->z * v->x - u->x * v->z;
	w->z = u->x * v->y - u->y * v->x;
}

/**
 * @brief Calculates scalar product between u and v
 * 
 * @param u 
 * @param v 
 * @return double 
 */
double	dot(t_coor3 *u, t_coor3 *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

/**
 * @brief Subtracts u by v and stores value in w, returning it
 * 
 * @param u 
 * @param v 
 * @return t_coor3 
 */
t_coor3	subtract(t_coor3 u, t_coor3 v)
{
	t_coor3	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}
