#include "libft.h"

char    *ft_itoa(int n)
{
    char *str;
    long num = n;
    int len = 0;
    int neg = 0;

    if (num < 0)
    {
        neg = 1;
        num = -num;
    }

    len = neg + 1;
    long tmp = num;
    while (tmp /= 10)
	{
    	len++;
	}

    str = (char *)malloc(len + 1);

    if (!str)
	{
        return NULL;
	}

    str[len] = '\0';

    while (len--)
    {
        str[len] = num % 10 + '0';
        num /= 10;
    }
    if (neg)
	{
        str[0] = '-';
	}

    return str;
}


// int main()
// {
//     int number = -4242;
//     char *str = ft_itoa(number);

//     printf("The string representation of %d is %s\n", number, str);
//     free(str); 

//     return 0;
// }