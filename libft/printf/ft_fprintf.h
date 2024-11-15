/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:08:19 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/15 14:59:00 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int		ft_printdecimal(int fd, int n);
int		ft_printchar(int fd, char c);
int		ft_printstr(int fd, char *s);
int		ft_printptr(int fd, long unsigned int p);
int		ft_printunint(int fd, unsigned int n);
int		ft_printhexa(int fd, unsigned int n, char c);
int		ft_printpercent(int fd);
int		ft_fprintf(int fd, const char *str, ...);
int		ft_printf(const char *str, ...);

#endif
