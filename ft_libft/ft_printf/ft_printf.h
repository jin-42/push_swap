/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:16:14 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/24 13:41:36 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_hex_lowercase(unsigned int nbr);
int	print_hex_uppercase(unsigned int n);
int	print_nbr(int nb);
int	print_percent(void);
int	print_ptr(void *ptr);
int	print_unsigned(unsigned int nbr);
int	ft_printf(const char *format, ...);
#endif
