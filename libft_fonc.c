/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fonc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:32:22 by metyasar          #+#    #+#             */
/*   Updated: 2023/11/09 19:52:16 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*a;

	if (!s1 || !s2)
		return (NULL);
	a = malloc(sizeof(char) * (ft_strlen(s1)) + (ft_strlen(s2) + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		a[i++] = s2[j++];
	free(s1);
	free(s2);
	a[i] = '\0';
	return (a);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		sign;

	size = ft_intlen(n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	else
		sign = 1;
	while (size-- > (sign == -1))
	{
		result[size] = '0' + sign * (n % 10);
		n /= 10;
	}
	return (result);
}
