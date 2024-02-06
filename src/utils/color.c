/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/30 15:19:56 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	rgb_to_int(t_vec3 color)
{
	color = color_overflow(color);
	return (((int)color.x << 16) + ((int)color.y << 8) + (int)color.z);
}
