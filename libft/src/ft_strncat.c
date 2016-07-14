/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:42:34 by arnovan-          #+#    #+#             */
/*   Updated: 2016/05/14 16:35:08 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *d;
	char *s;

	d = dest;
	s = (char*)src;
	while (*d != '\0')
		d++;
	while (*s != '\0' && (n > 0))
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	*d = '\0';
	return (dest);
}