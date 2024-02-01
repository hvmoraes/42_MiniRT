/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:23 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/29 15:29:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_digit(char *nbr)
{
	size_t	i;
	size_t	j;
	char	*check;

	i = 0;
	j = 0;
	check = malloc(sizeof(char) * ft_strlen(nbr) + 1);
	while (i < ft_strlen(nbr))
	{
		if ((nbr[i] >= '0' && nbr[i] <= '9') || (nbr[i] >= 'a' && nbr[i] < 'z')
			|| (nbr[i] >= 'Z' && nbr[i] <= 'Z') || nbr[i] == '.')
		{
			check[i] = nbr[i];
			j++;
		}
		i++;
	}
	while (j < ft_strlen(nbr))
	{
		check[j] = '\0';
		j++;
	}
	check[j] = '\0';
	i = 0;
	while (check[i])
	{
		if (!ft_isdigit(check[i]) && check[i] != '\0' && check[i] != '.')
		{
			free(check);
			return (0);
		}
		i++;
	}
	free(check);
	return (1);
}
