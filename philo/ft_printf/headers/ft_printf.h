/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:37:05 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/21 16:37:05 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_int(int n);
void	ft_put_upper_digit(unsigned int n, unsigned int base, int *len);
void	ft_put_digit(unsigned int n, unsigned int base, int *len);
int		ft_print_unsigned_int(unsigned int n);
void	ft_print_pointer(size_t ptr, int *len);
int		ft_putchar(char c, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);

#endif // FT_PRINTF_H