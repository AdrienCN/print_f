/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:53:38 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/15 18:13:38 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PRINTF_H
# define HEADER_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef PRINTF_MACRO
#  define PRINTF_MACRO
#  define TYPE "csdiuxXp%"
#  define FLAG "-0"
#  define HEX_MAJ "0123456789ABCDEF"
#  define HEX_MIN "0123456789abcdef"
#  define DIGIT "0123456789"
# endif

typedef	struct	s_data
{
	char	type;
	int		null_count;
	int		no_flags;
	int		width;
	int		w_val;
	int		minus;
	int		precision;
	int		p_val;
	int		zero;
	char	*res;
	char	*flag;
}				t_data;

char			*ft_null_char_case(t_data *data);
char			*ft_minus_padding(char *str, t_data *data, int choice);
char			*ft_precision_padding(char *str, t_data *data);
void			ft_truncate(char *str, unsigned int precision);
char			*ft_display_nbr(char *str, t_data *data);
char			*ft_display_hex(char *str, t_data *data);
char			*ft_display_char(char *str, t_data *data);
char			*ft_display_str(char *str, t_data *data);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *str);
unsigned int	ft_strlen(char const *str);
void			ft_putstr(char *str);
char			*ft_strndup_char(char c, unsigned int len);
unsigned int	ft_move_on(const char *str, t_data *data);
char			*ft_display(const char *str);
char			*ft_get_flag(const char *str);
int				ft_isbase(char *str, char c);
void			ft_reset_datablock(t_data *data);
void			ft_init_datablock(t_data *data);
int				ft_setup_data_flag(t_data *data, const char *str, va_list args);
unsigned int	ft_precision_init(t_data *data, char *str, va_list args);
unsigned int	ft_minus_zero(t_data *data, char *str);
unsigned int	ft_width_init(t_data *data, char *str, va_list args);
void			ft_initial_flag(t_data *data, va_list args);
int				ft_printf_loop(const char *str, va_list args, t_data *data);
char			*ft_apply_flag_output(char *str, t_data *data);
int				ft_printf(const char *str, ...);
char			*ft_conversion(const char *str, va_list args, t_data *data);
char			*ft_make_initial_string(t_data data, va_list args);
unsigned int	ft_precision_format(const char *str);
unsigned int	ft_width_format(const char *str);
unsigned int	ft_flag_format(const char *str);
int				ft_check_conversion_format(const char *str);
char			*ft_chardup(int c);
char			*ft_strdup(char *str);
char			*ft_itoa_base_dup(int n, char *base);
char			*ft_u_itoa_base_dup(unsigned int nbr, char *base);
char			*ft_address_dup(void *ptr, char *base, t_data data);
void			ft_convert_base(unsigned int nbr,
								char *s, char *base, unsigned int size);
void			ft_convert_address_base(unsigned long nbr,
										char *s, char *base, unsigned int size);
#endif
