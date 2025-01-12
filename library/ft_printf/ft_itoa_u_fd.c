/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:25:10 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/09 15:52:49 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	str_implement(char *nbr, unsigned int n, int len)
{
	nbr[len] = '\0';
	len--;
	while (len >= 0)
	{
		nbr[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

int	ft_itoa_u_fd(unsigned int n)
{
	char		*nbr;
	int			len;
	int			count;	

	len = len_int(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	str_implement(nbr, n, len);
	count = ft_strlen(nbr);
	ft_putstr(nbr);
	free(nbr);
	return (count);
}
