#include <stdio.h>

void ft_swap(int *a, int*b);
int main(){
	int c=1;
	int d=2;
	int *a=&c;
	int *b=&d;

	printf("%d %d", c, d);
	ft_swap(a,b);
	printf("%d %d", c, d);
}

