/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:18:57 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/28 11:18:57 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include "structs.h"
# include "../mlx/mlx.h"

# define WIDTH 700
# define HEIGHT 400

/*        src/render/draw.c        */
void	put_pixel(t_data *data, int x, int y, int color);
int		render(t_data *data);

/*        src/init/init.c        */
void	init(t_data *data);

/*        src/end/close_window.c        */
int		close_window(t_data *data);

/*        src/utils/key_hooks.c        */
int		key_hooks(int keycode, t_data *data);

#endif