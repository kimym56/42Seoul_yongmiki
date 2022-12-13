#include <stdio.h>
char *ft_strcat(char *dest, char *src);
int main()
{
	char a[10] = "abc";
	char b[5]="def";
	printf("%s",ft_strcat(a,b));
}
