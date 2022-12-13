#include <stdio.h>
char *ft_strlowcase(char *str);
int main(){
	char a[10] = "asSf";
	char b[2] = " ";
	printf("%s, %s", ft_strlowcase(a), ft_strlowcase(b));
}
