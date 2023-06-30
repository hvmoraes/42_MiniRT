/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:06:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/29 16:51:17 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define	MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../Libft/inc/libft.h"
# include "../mlx/mlx.h"
# include "structs.h"

#define WIDTH 800
#define HEIGHT 600

extern t_data g_data;

/*    init/init.c    */

void	init_data(char **argv);
void	init_scene(void);

/*    end/error.c    */

void	handle_error(char *error);

/*    utils/coords.c    */

int	check_coords(char *coords, t_coor3 *camera);
int	check_normal(char *normal, t_coor3 *normal_final);

/*    utils/math.c    */

double	to_rad(int deg);

#endif
