#include "include/ft_printf.h"
#include <stdio.h>
#define PRINT ft_printf
#define PRINTF printf 
#define		BPRINT(x, ...) PRINT("|%s| asfsa//my \n", x)
#define		FPRINTF(x, ...) PRINTF("|%s| //real \n", x)
void		multi_tests(void)
{
	char	c = 'a';
	int     d = 2147483647;
    int     e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	
	printf("\e[1;33m------------------------------TEST multi------------------------------\e[0m\n");
	PRINTF(" mmm Return : %d\n", PRINT("%.0u, %d, %d, %d, %s, %c, %c, %d, %u, %x, %%", 0, k, l, m, n, c, c, j, j, j));
	PRINTF("     Return : %d\n", PRINTF("%.0u, %d, %d, %d, %s, %c, %c, %d, %u, %x, %%", 0,  k, l, m, n, c, c, j, j, j));
	PRINTF(" mmm Return : %d\n", PRINT("%4.3i, %4.3d, %4.3d, %4.3d, %d, %s, %c, %d, %u, %x, %X", 14, j, k, l, m, n, c, c, j, j, j));
	PRINTF(" --- Return : %d\n", PRINTF("%4.3i, %4.3d, %4.3d, %4.3d, %d, %s, %c, %d, %u, %x, %X", 14, j, k, l, m, n, c, c, j, j, j));
	PRINTF(" mmm Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	PRINTF(" --- Return : %d\n", PRINTF("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	PRINTF(" mmm Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d));
	PRINTF(" --- Return : %d\n", PRINTF("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d));
}
void		print_flags(t_pft *set)
{
	printf("\n----set list------\n");
	printf("ladjust = %d\n", set->ladjust);
	printf("f_prec = %d\n", set->f_prec);
	printf("zero = %d\n", set->zero);
	printf("width = %d\n",set->width);
	printf("prec = %d\n",set->prec);
	printf("------------------\n");
}

void	test_s(void)
{
	char *null = NULL;
	int ret;
	printf("\e[1;33m------------------------------TEST STRINGS------------------------------\e[0m\n");
	ret = printf("ix|%20s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%20s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%.5s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%.5s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%10.1s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%10.1s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-19.29s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%-19.29s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-*.*s|",-30,-1, "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%-*.*s|",-30,-1, "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%3.1s|",null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%3.1s|",null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%.03s|", null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("ix|%.03s|", null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_c(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST CHARACT------------------------------\e[0m\n");
	ret = printf("ix|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67); 
	printf("\e[1;35m[%d]\e[0m\n", ret);
//	ret = printf(NULL, (char)0); 
	int ch = 0;
	while (ch < 255) 
	{
		ret = printf("ix|%23lc|",(char)ch);
		printf("\e[1;35m[%d ch%d]\e[0m\n", ret, ch);
		ret = PRINT("my|%23lc|",(char)ch);
		printf("\e[1;35m[%d ch%d]\e[0m\n", ret, ch++);
	}
}
void	test_i(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST INTEGER------------------------------\e[0m\n");
	ret = printf("ix|d.%10d i.%.2i|",10, -12345);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|d.%10d i.%.2i|",10, -12345);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|d.%010d i.%010i|",-10, -10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|d.%010d i.%010i|",-10, -10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|d.%.10d i.%5.10i|",123123, -123123);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|d.%.10d i.%5.10i|",123123, -123123);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|d.%.10d i.%10.5i|",123123, -123);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|d.%.10d i.%10.5i|",123123, -123);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_n(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST N------------------------------\e[0m\n");
	int	i;
	ret = PRINT("my|%123d|%n", 5, &i);
	printf("\e[1;35m[%u n=%d]\e[0m\n", ret, i);
	ret = printf("ix|%123d|%n", 5, &i);
	printf("\e[1;35m[%u n=%d]\e[0m\n", ret, i);
	ret = PRINT("my|%1230d|%n", 5, &i);
	printf("\e[1;35m[%u n=%d]\e[0m\n", ret, i);
	ret = printf("ix|%1230d|%n", 5, &i);
	printf("\e[1;35m[%u n=%d]\e[0m\n", ret, i);
}
void 	test_x(void)
{
	int ret;

	printf("\e[1;33m------------------------------TEST POINTER------------------------------\e[0m\n");
	ret = printf("ix|%#3x|",0);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%#3x|",0);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_p(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST POINTER------------------------------\e[0m\n");
	PRINTF(" mmm Return : %d\n", PRINT("%.*p", -1, &ret));
	//PRINTF("     Return : %d\n", PRINTF("%.*p", -1, &ret));
	ret = PRINT("my|%-32p|", &ret);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-32p|",&ret);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%p|", 0);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%p|", NULL);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%5p|", NULL);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%5p|", NULL);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_percent(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST PERCENT------------------------------\e[0m\n");
	ret = PRINT("my|%05%|");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%05%|");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = PRINT("my|%-05%|");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-05%|");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	
}
int main(void)
{
//multi_tests();
//test_s();
//test_c();
//test_i();
test_p();
//test_x();
//test_n();
//test_percent();
	return 0;
}

