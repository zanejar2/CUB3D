/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_merging.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 04:38:00 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/06/03 03:35:40 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
        
int calcul_rows(char **map)
{
	int i=0;    
	
	while(map[i])
		i++;
	return(i);
}
int calcul_col(char **map)
{ 
int i=0;
int j=0;
while (map[i])
{   
	while (map[i][j])
		j++;
	return(j);
}
	return(j);
}
int 	fill_int(char c)
{
	if(c == '6')
		return 6;
	else if(c == '0')
		return 0;
	else if(c == '1')
	   return 1;
	else if(c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return 0;
	else
		return 1;
}

double	get_angle(t_data_parsing *data)
{
	int i=0;
	int j=0;
	while (data->new_map[i])
	{
		j = 0;
		while (data->new_map[i][j])
		{
			if(data->new_map[i][j] == 'N')
				return (PI/2);
			if(data->new_map[i][j] == 'E')
				return (0);
			if(data->new_map[i][j] == 'W')
				return (PI);
			if(data->new_map[i][j] == 'S')
				return (-PI/2);
			j++;
		}
		i++;
	}
	return(PI/2);
}
