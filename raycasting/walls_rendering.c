/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanejar <zanejar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:13:46 by zanejar           #+#    #+#             */
/*   Updated: 2023/05/24 05:55:08 by zanejar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
        
void wall_sider(t_data *data, int i)
{
	if (!is_ray_facing_down(data->ray[i].ray_angle && !data->ray[i].vert))
		data->wall_side = NORTH;
	else if (is_ray_facing_down(data->ray[i].ray_angle && !data->ray[i].vert))
		data->wall_side = SOUTH;
	else if (is_ray_facing_right(data->ray[i].ray_angle && data->ray[i].vert))
		data->wall_side = EAST;
	else if (!is_ray_facing_right(data->ray[i].ray_angle && data->ray[i].vert))
		data->wall_side = WEST;
}

void put_textures(t_data *data)
{
	
}

void render_walls(t_data *data, int i)
{
	for (int a = data->wall.strip_top; a < data->wall.strip_bottom; a++)
		my_mlx_pixel_put(&data->img, i, a, WHITE_COLOR);
	put_textures(data);
}

void render_ceiling(t_data *data, int i)
{
	for (int y = 0; y < data->wall.strip_top; y++)
		my_mlx_pixel_put(&data->img, i, y, data->color_ceiling);
}

void render_floor(t_data *data, int i)
{
	for (int y = data->wall.strip_bottom; y < WINDOW_HEIGHT; y++)
		my_mlx_pixel_put(&data->img, i, y, data->color_floor);
}

void render_3d(t_data *data)
{
	int i;
	double perp_distance;

	i = -1;
	while (++i < NBR_RAYS)
	{
		perp_distance = data->ray[i].ray_distance * cos(data->ray[i].ray_angle - data->player.rotationAngle);
		data->wall.strip_height = (PIXEL / perp_distance) * data->wall.projection;

		data->wall.strip_top = (WINDOW_HEIGHT - data->wall.strip_height) / 2;
		if (data->wall.strip_top < 0)
			data->wall.strip_top = 0;
		data->wall.strip_bottom = (WINDOW_HEIGHT + data->wall.strip_height) / 2;
		if (data->wall.strip_bottom > WINDOW_HEIGHT)
			data->wall.strip_bottom = WINDOW_HEIGHT;
		wall_sider(data, i);
		render_walls(data, i);
		render_ceiling(data, i);
		render_floor(data, i);
	}
}
