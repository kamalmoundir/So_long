/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:50:43 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/09 16:02:33 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_recursive(unsigned long long ptr, char *hex)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putchar('0');
	if (ptr >= 16)
		count += ft_print_ptr_recursive(ptr / 16, hex);
	count += ft_putchar(hex[ptr % 16]);
	return (count);
}

int	ft_print_ptr_fd(void *ptr)
{
	char				*hex;
	int					count;
	unsigned long long	ptr1 ;

	ptr1 = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_print_ptr_recursive(ptr1, hex);
	return (count);
}
