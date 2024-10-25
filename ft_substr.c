#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	if (s == NULL) {
        return NULL;
    }

	unsigned int index = 0;
	unsigned int str_len = 0;

	while (s[str_len] != '\0')
	{
		str_len++;
	}

	if (str_len <= start || len == 0)
	{
		return NULL;
	}
	
	char *dest = malloc((len + 1) * sizeof(char));
	char *pdest = dest;

	while (s[index] != '\0' && index <= start)
	{

		while (index == start)
		{
			if (len == 0)
			{
				return pdest;
			}
			*dest = *s;
			dest++;
			s++;
			len--;
		}
		s++;
		index++;
	}
	return pdest;
}

// int main() {
//     const char *str = "Hello World Hello";
//     char *substr = ft_substr(str, 6, 5);

//     if (substr != NULL) {
//         printf("Substring: %s\n", substr);
//         free(substr);
//     } else {
//         printf("Failed to allocate memory.\n");
//     }

//     return 0;
// }