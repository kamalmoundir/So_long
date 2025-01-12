/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_up_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:11:48 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/09 15:53:13 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex_up_fd(unsigned int nbr)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_write_hex_up_fd(nbr / 16);
	ft_putchar(hex[nbr % 16]);
	count++;
	return (count);
}
