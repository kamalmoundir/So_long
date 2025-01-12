/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_l_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:15 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/09 15:53:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex_l_fd(unsigned int nbr)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_write_hex_l_fd(nbr / 16);
	ft_putchar(hex[nbr % 16]);
	count++;
	return (count);
}
