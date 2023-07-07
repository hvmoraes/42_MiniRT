/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:55:50 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/04 08:53:59 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/**
 * @brief 
 * 
 * @param error 
 */
void	handle_error(char *error)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	free_all(1);
}
