/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:09:15 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/09 08:42:03 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_length(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int d_len1;
	unsigned int d_len2;
	unsigned int s_len;

	i = 0;
	d_len1 = ft_length(dest);
	d_len2 = ft_length(dest);
	s_len = ft_length(src);
	if (size < 1 || size < d_len1)
		return (s_len + size);
	while (src[i] && d_len1 < (size - 1))
	{
		dest[d_len1] = src[i];
		d_len1++;
		i++;
	}
	dest[d_len1] = 0;
	return (s_len + d_len2);
}
