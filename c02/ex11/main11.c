#include <stdio.h>
void ft_putstr_non_printable(char *str);
int main(){
	char t = (char)133;
	char s[10]="123";
	s[2]=t;
	ft_putstr_non_printable(s);
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}

