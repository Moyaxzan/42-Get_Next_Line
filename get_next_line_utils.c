/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:30:48 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/05/05 22:18:53 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || !c)
	{
		if (s[i] == (unsigned char)c)
			return (&(s[i]));
		i++;
	}
	return (0x0);
}

char	*ft_strdup(const char *s)
{
	unsigned long	i;
	char			*res;

	if (!s)
		return (0x0);
	i = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * i);
	if (!res)
		return (0x0);
	while (i--)
		*res++ = *s++;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0x0);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0x0);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	unsigned int		i;
	unsigned long		len_src;

	if (!s)
		return (0x0);
	len_src = ft_strlen(s);
	if (start >= len_src)
		return (ft_strdup(""));
	if (len_src - start < len)
		len = len_src - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (0x0);
	i = start;
	while (i < start + len && s[i])
	{
		substring[i - start] = s[i];
		i++;
	}
	substring[i - start] = '\0';
	return (substring);
}
