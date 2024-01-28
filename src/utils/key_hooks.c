/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:40:21 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 13:40:21 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minirt.h"

int	key_hooks(int keycode, t_data *data)
{
	//printf("%i\n", keycode);
	if (keycode == 65307)
	{
		close_window(data);
	}
	return (0);
}
