#include <string.h>
#include <stdio.h>
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
int main(){
	char d[20];
	char* s = "asd ";
	unsigned int size=3;

	printf("%u, %s",ft_strlcpy(d,s,size), d);
}
