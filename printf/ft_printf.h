/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:13:27 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/10/24 18:31:52 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	nb_percentage(char const *s);
int	type_data(char type, va_list *ap);
int	nb_digit(long n, int sub);
int	ft_print_address(void *p);
int	ft_putnbr_hex(long n, char *c);


#endif
