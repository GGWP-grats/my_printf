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
	char *null = NULL;
	int ret;
	printf("\e[1;33m------------------------------TEST STRINGS------------------------------\e[0m\n");
	ret = printf("ix|%20s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%20s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%.5s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%.5s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%10.1s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%10.1s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-19.29s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%-19.29s|", "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%-*.*s|",-30,-1, "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%-*.*s|",-30,-1, "Hello World");
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%3.1s|",null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%3.1s|",null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|%.03s|", null);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_c(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST CHARACT------------------------------\e[0m\n");
	ret = printf("ix|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|%10c%20c%-30c%1c%2c%3c|",62,63,64,65,66,67); // FIXME -
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_i(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST INTEGER------------------------------\e[0m\n");
	ret = printf("ix|d.%10d i.%10i u.%10u|",10, 10, 10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|d.%10d i.%10i u.%10u|",10, 10, 10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|d.%010d i.%010i u.%010u|",-10, -10, -10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|d.%010d i.%010i u.%010u|",-10, -10, -10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = printf("ix|d.%.10d i.%5.10i u.%u|",123123, -123123, 10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
	ret = ft_printf("my|d.%.10d i.%5.10i u.%u|",123123, -123123, 10);
	printf("\e[1;35m[%d]\e[0m\n", ret);
}
void	test_x(void)
{
	int ret;
	printf("\e[1;33m------------------------------TEST INTEGER------------------------------\e[0m\n");
	ret = printf("ix|%u %u|",10, -1);
	printf("[%d]\n", ret);
	ret = ft_printf("my|%u %u|",10, -1);
}
int main(void)
{
test_s();
//test_c();
//	test_i();
	return 0;
}

