#include "libft.h"

char *ft_strnstr(const char *forest, const char *tree, size_t n)
{
	size_t tree_heigth = 0;
	size_t i = 0;

	if (*tree == '\0')
	{
        return (char *)forest;
    }

	while (tree[tree_heigth] != '\0')
	{
        tree_heigth++;
    }
	
	while (n >= tree_heigth && *forest != '\0')
	{
		i = 0;
		while (i < tree_heigth && forest[i] == tree[i])
		{
           	i++;
       	}
		if (i == tree_heigth)
		{
			return (char *)forest;
		}
		forest++;
		n--;
	}
	return NULL;
}
