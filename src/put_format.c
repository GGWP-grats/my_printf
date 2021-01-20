#include "ft_printf.h"

void		putf_i(int i, t_pft *set, int *ret)
{
	int wid;
	
	wid = ft_intwid(i, set->base);
	if (set->f_prec && !(set->zero = 0) && !(set->prec)) 
		;
	else if (set->prec > wid)
		set->width -= i > -1 ? set->prec : set->prec + 1;
	else
		set->width -= i > -1 ? wid : wid;
	if (!(set->ladjust) && !(set->zero))
		print_width(set, ret);
	if (!set->f_prec || set->prec != 0)
	{
		if (i < 0 && wid--)
			putchar_c('-', ret);
		if (!(set->ladjust) && set->zero)
			print_width(set, ret);
		while (set->f_prec && (set->prec)-- > wid)
			putchar_c('0', ret);
		putnum_base(i, set, ret);
	}
	set->zero = FALSE;
	if (set->ladjust)
		print_width(set, ret);
}

void		putf_u(unsigned int i, t_pft *set, int *ret)
{

	int wid;

	wid = ft_intwid((long)i, set->base);
	if (set->width > 0 && set->ladjust == FALSE &&
								(set->width -= wid))
		print_width(set, ret);
	u_putnum_base(i, set, ret);
}

void		putf_s(char *s, t_pft *set, int *ret)
{
	int len;
	int chknull;

	if ((chknull = check_null_str(s, set, ret)) == 1)
		return ;
	else if (chknull < 0)
		s = "(null)";
	len = ft_strlen(s);	
	set->zero = FALSE;
	if (set->f_prec && set->prec < len)
		len = set->prec;
	if (set->ladjust == FALSE && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
	write(1, s, len);
	*ret += len;
	if (set->ladjust && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
}

void		putf_c(char c, t_pft *set, int *ret)
{
	set->zero = FALSE;
	if (set->width > 0 &&
			set->ladjust == FALSE && set->width--)
		print_width(set, ret);
	putchar_c(c, ret);
	set->width--;
	if (set->ladjust)
		print_width(set, ret);
}
