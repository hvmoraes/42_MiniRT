/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:09:55 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 12:09:55 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

t_viewport	*viewport(void)
{
	static t_viewport	viewport;

	return (&viewport);
}

t_camera	*camera(void)
{
	static t_camera	camera;

	return (&camera);
}
