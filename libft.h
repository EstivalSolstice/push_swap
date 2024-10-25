#ifndef LIBFT_H
#define LIBFT_H

// Libraries
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_node {
    int             value;
    int             index;
    struct s_node   *prev;
    struct s_node   *next;
} t_node;

typedef struct s_stack {
    t_node  *top;
    int     size;
} t_stack;

typedef struct s_push_swap {
    t_stack *a;
    t_stack *b;
    int move_count;
} t_push_swap;


// Fake bools
int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_strlen(char *str);
void 	ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dest, char *src);
size_t 	ft_strlcat(char *dst, const char *src, size_t dstsize);

// Memory stuff
void 	*ft_memset(void *ptr, int value, size_t num);
void	ft_memcpy(void *dest, const void *src, size_t num);
void 	*ft_memmove(void *dest, const void *src, size_t n);
void 	*ft_memchr(const void *ptr, int value, size_t n);
int		 ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

int		ft_toupper(int c);
int 	ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char 	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(char *str);
void 	*ft_calloc(size_t num, size_t size);

char	*ft_strdup(char *src);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const*s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char*));

// File Descriptor
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

// LinkedList fucntions
t_list 	*ft_lstnew(void *content);
void 	ft_lstadd_front(t_list **lst, t_list *new);
int 	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *));

// Printf
int		ft_printf(const char *, ...);

// Helper functions for printf
void 	ft_puthex_lower(unsigned long num);
void 	ft_puthex_upper(unsigned long num);
void	ft_putnbr_fd_mod(unsigned int n, int fd);
void	ft_checkinputprintf(const char fmt, va_list args);

void	ft_handle_input_c(va_list args);
void	ft_handle_input_s(va_list args);
void	ft_handle_input_p(va_list args);
void	ft_handle_input_d_i(va_list args);
void	ft_handle_input_u(va_list args);
void	ft_handle_input_x(va_list args);
void	ft_handle_input_Xu(va_list args);

// Push Swap begins

// Stack operations
// Swap
void 	sa(t_push_swap *ps);
void 	sb(t_push_swap *ps);
void 	ss(t_push_swap *ps);
// Push
void 	pa(t_push_swap *ps);
void 	pb(t_push_swap *ps);
// Rotate
void 	ra(t_push_swap *ps);
void 	rb(t_push_swap *ps);
void 	rr(t_push_swap *ps);
// Reverse Rotate
void 	rra(t_push_swap *ps);
void 	rrb(t_push_swap *ps);
void 	rrr(t_push_swap *ps);

// Move eval
int 	calculate_rotation_a(t_stack *a, int target_index);
int 	calculate_rotation_b(t_stack *b, int element_index);
int 	find_target_position(t_stack *a, int element_index);
int 	calculate_move_cost(t_stack *a, t_stack *b, int b_position);

// Helper functions
// int 	compare_int(const void *a, const void *b);
t_node 	*new_node(int value, int index);
void 	push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void 	rotate(t_stack *stack);
void 	reverse_rotate(t_stack *stack);
void 	swap(t_stack *stack);

void 	perform_rotations(t_push_swap *ps, int rotation_a, int rotation_b);
int		is_empty(t_stack *stack);
int 	is_sorted(t_stack *stack);
void 	sort_three(t_stack *a, t_push_swap *ps);
void 	swap_mod(int *a, int *b);
int 	partition(int *arr, int low, int high);
void 	quick_sort(int *arr, int low, int high);

void 	push_swap_execute(int argc, char **argv);
int 	*parse_and_convert_args(char **argv, int size);
int 	*copy_and_sort_values(int *values, int size);
int 	*assign_indices(int *values, int *sorted_values, int size);
void 	initialize_stacks(t_push_swap *ps, int *values, int *indices, int size);
void 	sort_push_swap(t_push_swap *ps);
void 	final_rotate_sort(t_push_swap *ps);


#endif