/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:35:29 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/23 19:36:58 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mlc;

	mlc = malloc(nmemb * size);
	if (!mlc)
		return (0);
	else
		memset(mlc, 0, nmemb * size);
	return (mlc);
}


int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	negative;

	i = 0;
	negative = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * negative);
}