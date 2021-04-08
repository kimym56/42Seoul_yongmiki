#include <stdio.h>
char *ft_strncat(char *dest, char *src, unsigned int nb);
int main()
{
	char a[10] = "abc";
	char b[5]="def";
	printf("%s",ft_strncat(a,b,2));
}
