/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:48:45 by yvieira-          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:29 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 32;
	}
	return (ch);
}
