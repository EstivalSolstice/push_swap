#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	const char *pstr = str;
	const char *locc = NULL;

	while (*pstr)
    {
        if (*pstr == (char)c)
        {
            locc = pstr;
        }
        pstr++;
    }

 if (*pstr == (char)c)
    {
        locc = pstr;
		return (char *)locc;
    }

    return NULL;
}
