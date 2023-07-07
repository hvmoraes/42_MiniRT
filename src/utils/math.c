/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:10 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/04 13:13:20 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Convert deg to radians
 * 
 * @param deg 
 * @return double 
 */
double	to_rad(int deg)
{
	return (deg * M_PI / 180);
}

double	min(double nbr1, double nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

/**
 * @brief Solves quadratic function with a, b and c values given and returns 
 * smallest result
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return double 
 */
double	quadratic(double a, double b, double c)
{
	double	result1;
	double	result2;

	if (is_zero(pow(b, 2) - 4 * a * c))
		return (0.0);
	result1 = ((-b + sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
	result2 = ((-b - sqrt(pow(b, 2) - 4.0 * a * c)) / (2.0 * a));
	if (is_zero(result1))
		return (result2);
	if (is_zero(result2))
		return (result1);
	if (result1 == result2)
		return (result1);
	if (is_zero(result1) && is_zero(result2))
		return (0.0);
	return (min(result1, result2));
}
