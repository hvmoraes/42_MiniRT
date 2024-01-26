/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:31:36 by jaeshin           #+#    #+#             */
/*   Updated: 2024/01/26 11:35:51 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	open_helper(char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY, 0644);
	if (fd < 0)
	{
		printf("Wrong file name, go check again.\n");
		exit(1);
	}
	return (fd);
}

int32_t	get_type(char *line, uint32_t *type)
{
	int	index;

	index = 0;
	while (line[index] && (line[index] == ' ' || line[index] == '\t'))
		++index;
	if (!line[index])
		return (-1);
	*type = line[index];
	index++;
	if (!(line[index] == ' ' || line[index] == '\t'))
		*type *= line[index];
	if (!(line[index] == ' ' || line[index] == '\t'))
		++index;
	++index;
	return (index);
}

t_hitable	*get_hitable_helper(t_hitable **hitable, uint32_t type)
{
	t_hitable	*new;
	t_hitable	*current;

	new = malloc(sizeof(t_hitable));
	if (!new)
		return (NULL);
	new->type = type;
	new->next = NULL;
	if (*hitable == NULL)
		*hitable = new;
	else
	{
		current = *hitable;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (new);
}