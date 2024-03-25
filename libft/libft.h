#ifndef LIBFT_H
#define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

char    **ft_split(char const *s, char c);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *src);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int	    ft_atoi(const char *str);

#endif