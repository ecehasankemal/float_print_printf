#include <stdarg.h>
#include <unistd.h>

int    ft_putchar(int c)
{
    return (write(1, &c, 1));
}

int    ft_float_print(float nbr, char *str)
{
	int	index;
	int	len;
	char	num_list[100];
	long	i;
	long	fraction;
	
	len = 0;
	index = 0;
	i = (long long)nbr;
	fraction = (long long)(((nbr - i) * 1000000) + 0.2);
	while (i)
	{
		num_list[index++] = i % 10;
		i = i / 10;
	}
	while (index--)
		len += ft_putchar(str[num_list[index]]);
	len += ft_putchar('.');
	index = 0;
	while (fraction)
	{
		num_list[index++] = fraction % 10;
		fraction = fraction / 10;
	}
	while (index--)
		len += ft_putchar(str[num_list[index]]);
	return (len);
}


int    ft_printf(const char *str, ...)
{
    int    index;
    int    len;
    va_list    args;

    index = 0;
    len = 0;
    va_start(args, str);
    while (str[index] != '\0')
    {
        if (str[index] == '%' && str[index + 1] == 'f')
        {
            len += ft_float_print(va_arg(args, double), "0123456789");
            index += 2;
        }
        else
            len += ft_putchar(str[index]);
        index++;
    }
    va_end(args);
    return (len);
}

#include <stdio.h>

int    main(void)
{
    double	count;

    count = 31.399999;
    ft_printf("%f  count un degeri", count);
    ft_printf("\n%f  count un degeri", 12.2);
    ft_printf("\n");
    printf("\n%f count un degeri", count);
    printf("\n%f count un degeri", 12.2);

    return (0);
}

