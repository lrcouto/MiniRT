/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambi_rgb_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:52:46 by lcouto            #+#    #+#             */
/*   Updated: 2020/09/04 18:30:42 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/*
** There is a printf in this function. It's there just to see if the parameters
** are being transfered correctly. Don't forget to remove it.
*/

void		ambi_rgb_values(int i, int check, char *line, t_rt *rt)
{
	char	*temp;
	int		j;

	j = 0;
	while (line[i + j] >= '0' && line[i + j] <= '9')
		j++;
	if (line[i + j] == '.')
		errormsg(8);
	temp = ft_substr(line, i, j);
	if (check == 3)
		rt->ambi.color.r = ft_atoi(temp);
	else if (check == 2)
		rt->ambi.color.g = ft_atoi(temp);
	else if (check == 1)
		rt->ambi.color.b = ft_atoi(temp);
	free(temp);
	if ((rt->ambi.color.r < 0 || rt->ambi.color.r > 255) ||
	(rt->ambi.color.g < 0 || rt->ambi.color.g > 255) ||
	(rt->ambi.color.b < 0 || rt->ambi.color.b > 255))
		errormsg(8);
	printf("LIGHT: %f R: %d G: %d B: %d\n", rt->ambi.light,
	rt->ambi.color.r, rt->ambi.color.g, rt->ambi.color.b);
}
