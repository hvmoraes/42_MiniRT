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
# include <math.h>
# include <fcntl.h>
# include "structs.h"
# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"

# define WIDTH 960
# define HEIGHT 540
# define INF 2147483647
# define BLACK 0
# define RED 16711680
# define BLUE 255
# define GREEN 65280
# define YELLOW 16776960

/*                                                             /
/                        src/render                            /
/                                                             */

/*draw.c*/
void		put_pixel(int x, int y, int color);
int			render(void);

/*                                                             /
/                        src/init                              /
/                                                             */

/*init.c*/
void		init_values(void);
void		init_mlx(void);
int			init_camera(char **line);
int			add_sphere(char **line);
/*parser.c*/
void		parser(int argc, char **argv);
int			parse_error(char *error);
/*checks.c*/
char		**check_coords(char *coords, int *error);
int			check_normal(char *normal, int *error);
t_vec3		check_color(char *color, int *error);
int			check_fov(char *fov);
void		check_error(int error);
/*parse_utils.c*/
void		set_viewport(void);
void		parser2(int *error);
/*checks_utils.c*/
t_vec3	color_overflow(t_vec3 final_color);
void	check_coords_utils(char *coords, int *error, int *i);

/*                                                             /
/                        src/end                               /
/                                                             */

/*close.c*/
int			close_window(void);
void		free_array(char **array);
void		free_all(void);

/*                                                             /
/                        src/utils                             /
/                                                             */

/*key_hooks.c*/
int			key_hooks(int keycode);
/*canvas.c*/
t_vec3		canvas_viewport(int x, int y);
/*getters.c*/
t_data		*data(void);
t_viewport	*viewport(void);
t_camera	*camera(void);
/*array.c*/
int			array_size(char **array);
/*vectors.c*/
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);
float		dot(t_vec3 v1, t_vec3 v2);
/*math.c*/
double		to_rad(int deg);
/*color.c*/
int			rgb_to_int(t_vec3 color);

/*                                                             /
/                        src/objects                           /
/                                                             */

/*sphere.c*/
t_vec2		intersect_sphere(t_vec3 camera, t_vec3 viewport, t_sphere sphere);

#endif