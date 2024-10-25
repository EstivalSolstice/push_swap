#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int index = 0;
	unsigned int str_len = 0;

	while (s[str_len] != '\0')
	{
		str_len++;
	}

	char *new_str = (char *)malloc((str_len + 1) * sizeof(char));

	while (index < str_len)
    {
        new_str[index] = f(index, s[index]);
        index++;
    }

    new_str[index] = '\0';
    return new_str;
}