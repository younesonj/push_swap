#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


//#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"

typedef struct t_list{
    int value;
    int index;
    int cost;
    int is_in_top;
    struct t_list *target;
    struct t_list *next;
} t_list;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
//static char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    insert_ls_end(t_list **list,int value);
int     ft_atoi(const char *str);
void    print_ls(t_list **list);
void    free_list(t_list **list);
void    ft_check_nbrs(char **strs);
void    ft_exit_msg(char *str);
int     ft_strcmp(char *s1, char *s2);
//void    ft_check_doubles(char **strs);
int     len_strs(char **strs);
int     *convert_strs_tab(char **strs);
void    int_check_doubles(int *tab, int size);
void    free_strs(char **strs);
void    check_overflow(char **strs);
//void    free_arr(int *tab, int size);



#endif