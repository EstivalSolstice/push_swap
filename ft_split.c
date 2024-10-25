#include "libft.h"

static void free_allocated_memory(char **result, int substr_index)
{
    int index = 0;
    while (index < substr_index)
    {
        free(result[index]);
        index++;
    }
    free(result);
}

int count_str(const char *str, char delimiter)
{
	int count = 0;
	int index = 0;
	int insubstr = 0;

	while (str[index] != '\0')
	{
		if (str[index] != delimiter)
		{
			if (insubstr == 0)
            {
                count++;
                insubstr = 1;
            }
		}
		else
		{
			insubstr = 0;
		}
		index++;
	}
	return count;
}

char *create_substring(char *str, int start, int end)
{
	char *substr = (char *)malloc((end - start + 1) * sizeof(char));
	long int index = start;

	while (index < end)
	{
		substr[index - start] = str[index];
		index++;
	}
	substr[index - start] = '\0';
	return substr;
}

char    **ft_split(char const*s, char c)
{
	int substr_count = count_str(s, c);
	char **result = (char **)malloc((substr_count + 1) * sizeof(char *));

	int start = 0;
	int index = 0;
    int substr_index = 0;

	while (s[index] != '\0')
    {
        if (s[index] != c)
        {
            start = index;

            while (s[index] != '\0' && s[index] != c)
			{
                index++;
			}
			result[substr_index] = create_substring((char *)s, start, index);
            if (!result[substr_index])
            {
                free_allocated_memory(result, substr_index);
                return NULL;
            }
            substr_index++;
        }
        else
        {
            index++;
        }
    }
    result[substr_index] = NULL;

    return result;
}

// int main()
// {
//     char **result = ft_split("Hal,,lo,WELT,It42Is,,meeeeee,",',');
// 	int i = 0;

//     while (result[i] != NULL)
//     {
//         printf("Substring %d: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
//     }
// 	free(result);

//     return 0;
// }