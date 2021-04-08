#include <stdio.h>
#include <string.h>
char *ft_strncpy(char *dest, char *src, unsigned int n);
int main(){
	char *s = "as";
	char d[5];
	unsigned int n = 4;
	char r[5];
	strncpy(r,s,n);
	ft_strncpy(d,s,n);
	printf("%s\n%s",d,r);
}
