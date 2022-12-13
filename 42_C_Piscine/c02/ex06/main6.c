#include <stdio.h>
int ft_str_is_printable(char *str);
int main(){
	char c[2];
	c[0] = '1';
	c[1] =  'a' - 35;
	printf("%d , %d, %d",ft_str_is_printable(c),ft_str_is_printable(""),ft_str_is_printable("ABC"));
}

