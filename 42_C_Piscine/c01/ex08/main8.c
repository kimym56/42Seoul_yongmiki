#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);
int main(){
	int t[5] = {31, 25, 12, 22, 11};
	for(int i=0; i<5;i++)
		printf("%d ", t[i]);
	ft_sort_int_tab(t,5);
	for(int i=0; i<5;i++)
		printf("%d ", t[i]);
}
