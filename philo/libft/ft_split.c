/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarcross <zarcross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:24 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/17 00:20:33 by zarcross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	freeze_corleone(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	return (1);
}

int	fill_tab(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*str;

	str = s;
	tab_p = tab;
	while (*str)
	{
		while (*s == sep)
			++s;
		str = s;
		while (*str && *str != sep)
			++str;
		if (*str == sep || str > s)
		{
			*tab_p = ft_substr(s, 0, str - s);
			if (!*tab_p)
				return (freeze_corleone(tab, tab_p - tab));
			s = str;
			++tab_p;
		}
	}
	*tab_p = NULL;
	return (0);
}

int	ft_count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;

	if (!s)
		return (0);
	size = ft_count_words(s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (0);
	if (fill_tab(tab, s, c))
		return (0);
	return (tab);
}
