/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:32:23 by yojablao          #+#    #+#             */
/*   Updated: 2024/03/23 06:29:40 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lp;
	size_t	lc;
	char	*p;

	if (s1 && !s2)
		return ((char *) s1);
	if (!s1 && s2)
		return ((char *) s2);
	if (!s1 || !s2)
		return (NULL);
	lc = ft_strlen(s2);
	lp = ft_strlen(s1);
	p = (char *)malloc(lp + lc + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy (p, s1, lp +1);
	ft_strlcat (p, s2, (lc + lp +1));
	return (p);
}
