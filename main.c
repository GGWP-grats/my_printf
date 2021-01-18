#include "ft_printf.h"

void		print_flags(t_pft *set)
{
	printf("\n----set list------\n");
	printf("f_ladjust = %d\n", set->f_ladjust);
	printf("f_prec = %d\n", set->f_prec);
	printf("zero = %d\n", set->zero);
	printf("width = %d\n",set->width);
	printf("prec_width = %d\n",set->prec_width);
	printf("------------------\n");
}

void	test_s(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST STRINGS------------------------------\e[0m\n");
	ret = printf("ix|%20s|", "Hello World");
	printf("[%d]\n", ret);
	ret = ft_printf("my|%20s|", "Hello World");
	printf("[%d]\n", ret);
	ret = printf("ix|%.5s|", "Hello World");
	printf("[%d]\n", ret);
	ret = ft_printf("my|%.5s|", "Hello World");
	printf("[%d]\n", ret);
	ret = printf("ix|%10.0s|", "Hello World");
	printf("[%d]\n", ret);
	ret = ft_printf("my|%10.0s|", "Hello World");
	printf("[%d]\n", ret);
	ret = printf("ix|%-19.29s|", "Hello World");
	printf("[%d]\n", ret);
	ret = ft_printf("my|%-19.29s|", "Hello World");
	printf("[%d]\n", ret);
	ret = printf("ix|%-*.*s|",-30,-1, "Hello World");
	printf("[%d]\n", ret);
	ret = ft_printf("my|%-*.*s|",-30,-1, "Hello World");
	printf("[%d]\n", ret);
}
void	test_c(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST CHARACT------------------------------\e[0m\n");
	ret = printf("ix|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67);
	printf("[%d]\n", ret);
	ret = ft_printf("my|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67); // FIXME -
	printf("[%d]\n", ret);
}
void	test_i(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST INTEGER------------------------------\e[0m\n");
	ret = printf("ix|%u %u|",10, -1);
	printf("[%d]\n", ret);
	ret = ft_printf("my|%u %u|",10, -1);
	printf("[%d]\n", ret);
	ret = ft_printf("my|%x %d %d|",2147483648,10, 2147483647);
	printf("[%d]\n", ret);
	ret = ft_printf("my|%x %d|",0,-255);// FIXME negative %d,
	printf("[%d]\n", ret);
}
int main(void)
{
	test_s();
	test_c();
	test_i();
	return 0;
}

