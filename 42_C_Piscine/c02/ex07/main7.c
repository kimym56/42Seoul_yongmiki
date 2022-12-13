#include <stdio.h>
char *ft_strupcase(char *str);
int main(){
	char a[10] = "asSf";
	char b[2] = " ";
	printf("%s, %s", ft_strupcase(a), ft_strupcase(b));
}
