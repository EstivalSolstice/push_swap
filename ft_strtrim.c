#include "libft.h"

static int is_in_set(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return 1;
        set++;
    }
    return 0;
}


char	*mod_ft_strdup(const char *src)
{
	int		i = 0;
	int 	len = 0;
	char	*dest;

	while (src[len] != '\0')
	{
        len++;
    }

	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char    *ft_strtrim(char const *s1, char const *set)
{
	char *nwstr;
	size_t start = 0;
	size_t str_len = 0;
	size_t newstr_len = 0;
	char *ps1 = mod_ft_strdup(s1);
	if (!s1)
		return NULL;
	if (!set)
		return ps1;
	while (s1[start] && is_in_set(s1[start], set))
    	start++;
	while (s1[str_len] != '\0')
		str_len++;
	while (str_len > start && is_in_set(s1[str_len - 1], set))
		str_len--;
	newstr_len = str_len - start;
	nwstr = (char *)malloc(newstr_len + 1);
	if (!nwstr)
		return NULL;
	size_t i = 0;
    while (start < str_len)
    {
        nwstr[i] = s1[start];
        i++;
        start++;
    }
    nwstr[i] = '\0';
	return nwstr;
}

// int main()
// {
//     char *s1 = "   Hello World   ";
//     char *set = " ";
//     char *trimmed = ft_strtrim(s1, set);
//     printf("'%s'\n", trimmed);
//     free(trimmed);

//     return 0;
// }