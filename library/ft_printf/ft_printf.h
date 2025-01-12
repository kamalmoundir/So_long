/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:10:12 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/09 17:46:55 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_itoa_fd(int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_printf(char const *str, ...);
int		ft_write_hex_l_fd(unsigned int nbr);
int		ft_write_hex_up_fd(unsigned int nbr);
int		ft_itoa_u_fd(unsigned int n);
int		ft_print_ptr_fd(void *ptr);
size_t	ft_strlen(const char *s);

#endif
