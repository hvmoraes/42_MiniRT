/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:02:53 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/04 15:20:37 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief Adds object to list of objects' end in g_data
 * 
 * @param object 
 */
void	add_object(t_object *object)
{
	t_object	*tmp;

	if (!object)
		return ;
	if (!g_data.objects)
	{
		g_data.objects = object;
		return ;
	}
	tmp = g_data.objects;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = object;
}
