#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int srclen1 = 0;
	unsigned int srclen2 = 0;

	while (s1[srclen1] != '\0')
	{
		srclen1++;
	}
	while (s2[srclen2] != '\0')
	{
		srclen2++;
	}

	unsigned int srclen3 = srclen1 + srclen2;
	char *dest = malloc((srclen3 + 1) * sizeof(char));

	if (dest == NULL)
	{
        return NULL;
    }

	char *pdest = dest;

	while (srclen2 > 0)
	{
		while (srclen1 > 0)
		{
			*dest = *s1;
			s1++;
			dest++;
			srclen1--;
		}
		*dest = *s2;
		s2++;
		dest++;
		srclen2--;
	}
	*dest = '\0';
	return pdest;
}

// int main()
// {
// 	const char *s1 = "Hello ";
// 	const char *s2 = "World";

// 	char *string = ft_strjoin(s1, s2);
// 	printf("String: %s\n", string);
// 	free(string);

// 	return 0;
// }