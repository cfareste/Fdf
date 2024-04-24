/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:57:58 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/01/18 15:47:37 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	count_words(char const *s, char c)
{
	int		i;
	int		start_counting;
	int		counter;

	i = 0;
	counter = 0;
	start_counting = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && start_counting == 1)
		{
			counter++;
			start_counting = 0;
		}
		else if (s[i] == c)
			start_counting = 1;
		i++;
	}
	return (counter);
}

int static	wordlen(char const *s, char c, int start)
{
	int	j;

	j = 0;
	while (s[start + j] != '\0' && s[start + j] != c)
		j++;
	return (j);
}

char static	**free_array(char **array, int length)
{
	int	i;

	i = 0;
	while (i < length)
		free(array[i++]);
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	splitted_str = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitted_str)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		splitted_str[j] = malloc(sizeof(char) * (wordlen(s, c, i) + 1));
		if (!splitted_str[j])
			return (free_array(splitted_str, j));
		ft_strlcpy(splitted_str[j++], s + i, wordlen(s, c, i) + 1);
		i += wordlen(s, c, i);
	}
	splitted_str[j] = 0;
	return (splitted_str);
}
